#include "GLFW/glfw3.h"

#include "Engine.h"
#include "Debugging/DebugMacros.h"
#include "Engine/Objects/Actor.h"


LEngine* LEngine::Engine = nullptr;

LEngine::LEngine() : m_Renderer(nullptr), m_SoundSystem(nullptr), m_GameLogic(nullptr)
{

}

LEngine::~LEngine()
{

}

void LEngine::Initialize()
{
	//Initialize all subsystems and assert if something fails

	//Renderer doesn't require other subsystems to be initialized
	m_Renderer = new LRenderer();
	if (!m_Renderer)
		FatalError_Size("Couldn't allocate memory for renderer class (%d B)\n\n", sizeof(LRenderer));
	m_Renderer->Initialize();

	//WARNING	
	//Game logic must be initialized AFTER the renderer since it uses OpenGl calls during initialization
	m_GameLogic = new LGameLogicSystem();
	if (!m_GameLogic)
		FatalError_Size("Couldn't allocate memory for game logic class (%d B)\n\n", sizeof(LGameLogicSystem));
	m_GameLogic->Initialize();

	//SoundSystem doesn't require other subsystems to be initialized
	m_SoundSystem = new LSoundSystem();
	if (!m_SoundSystem)
		FatalError_Size("Couldn't allocate memory for sound system class (%d B)\n\n", sizeof(LSoundSystem));
	m_SoundSystem->Initialize();
}

void LEngine::GameLoop()
{
	m_GameLogic->SystemLoop();//Game logic is ran on another thread

	m_Renderer->SystemLoop();//Rendering is ran on the main thread and has to be called last

	std::unique_lock<std::mutex> SafetyLock(LGameLogicSystem::m_LogicMutex);//Get access to the shared flag
	m_GameLogic->bCloseSystem = true;//The game logic will end after it's current tick 
	SafetyLock.unlock();//Release the resource so that game logic can read it
	//Game logic thread is synced in the system's destructor
}

void LEngine::Terminate()
{
	delete m_Renderer;
	delete m_SoundSystem;
	delete m_GameLogic;
}

template<typename T>
std::shared_ptr<T> LEngine::CreateActor()
{
	std::shared_ptr<T> ptr(new T());

	if (ptr)
	{
		for (std::shared_ptr<IComponent>& Component : ptr->m_ComponentList)//Check the flags of every component this actor owns at the time of spawning
		{
			unsigned int Flags = Component->GetComponentFlags();

			if (Flags & EComponentFlags::RENDERABLE)//Renderable components are added to rendering subsystem
			{
				std::unique_lock<std::mutex> SafetyLock(LRenderer::m_PendingComp_Mutex);//Wait until component can be added
				m_Renderer->m_PendingComponents.push_front(static_cast<LRenderComponent>(Component));
				SafetyLock.unlock();
			}

			if (Flags & EComponentFlags::CLICKABLE)
			{
				//Do some fancy stuff in game logic
			}
		}
	}
	else
		Error("Actor couldn't be spawend - allocation failed.\n");

	return ptr;
}