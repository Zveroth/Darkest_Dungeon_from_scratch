#include "chrono"

#include "GameLogicSystem.h"
#include "InputHandler.h"
#include "Engine.h"
#include "Debugging/DebugMacros.h"
#include "Management/World.h"


std::mutex LGameLogicSystem::m_LogicMutex;

LGameLogicSystem::LGameLogicSystem() : bCloseSystem(false), World(nullptr)
{

}

LGameLogicSystem::~LGameLogicSystem()
{
	LogicThread.join();//Synchronize the thread
}

void LGameLogicSystem::Initialize()
{
	//WARNING
	//Input handler requires OpenGl to be already initialized
	LInputHandler::Initialize(this);
}

void LGameLogicSystem::SystemLoop()
{
	World = new HWorld();
	if (!World)
		FatalError_Size("Couldn't allocate memory for world class (%d B)\n\n", sizeof(HWorld));
	World->GameLogic = this;

	LogicThread = std::thread(&LGameLogicSystem::LogicLoop, this);//Set the handle and start running logic
}

void LGameLogicSystem::LogicLoop()
{
	//World->SomeInitialize();

	std::chrono::time_point<std::chrono::high_resolution_clock> PointA = std::chrono::high_resolution_clock::now();
	while (true)
	{
		std::chrono::time_point<std::chrono::high_resolution_clock> PointB = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> Time = PointA - PointB;//Calculate time between ticks
		PointA = PointB;

		//printf("Logic Loop\n");
		//Update stuff

		//Thread safe check of the closing flag
		//Now that I think about it, bCloseSystem doesn't need thread protection since 
		//engine writes to it only once and game logic only reads it so there is no threat of overriding
		std::unique_lock<std::mutex> SafetyLock(LGameLogicSystem::m_LogicMutex, std::try_to_lock);
		if (SafetyLock)
		{
			if (bCloseSystem)
			{
				SafetyLock.unlock();
				break;
			}
			else
				SafetyLock.unlock();
		}
	}
}

template<typename T>
std::weak_ptr<T> LGameLogicSystem::CreateActor()
{
	if(std::shared_ptr<HActor> Actor = LEngine::Engine->CreateActor())//Don't add null pointers
		m_ActorList.push_front(Actor);
	return m_ActorList.front();//Newly added actor is surely at the front
}