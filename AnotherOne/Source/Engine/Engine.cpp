#include "Engine.h"
#include "Debugging/DebugMacros.h"

#include "GLFW/glfw3.h"


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

void LEngine::Terminate()
{
	delete m_Renderer;
	delete m_SoundSystem;
	delete m_GameLogic;
}