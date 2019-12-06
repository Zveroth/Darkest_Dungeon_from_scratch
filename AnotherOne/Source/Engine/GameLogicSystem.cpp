#include "chrono"

#include "GameLogicSystem.h"
#include "InputHandler.h"
#include "Debugging/DebugMacros.h"
#include "Management/World.h"


std::mutex LGameLogicSystem::LogicMutex;

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
		std::unique_lock<std::mutex> SafetyLock(LGameLogicSystem::LogicMutex, std::try_to_lock);
		if (SafetyLock)
		{
			if (bCloseSystem)
			{
				SafetyLock.unlock();
				break;
			}
		}
	}
}

template<typename T>
std::shared_ptr<T> CreateActor()
{
	std::shared_ptr<T> ptr(new T());
	//Check its flags and distribute the actor
	return ptr;
}