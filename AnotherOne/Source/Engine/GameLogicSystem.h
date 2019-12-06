#pragma once
#include "thread"
#include "mutex"
#include "memory"


class HWorld;
class HActor;

class LGameLogicSystem
{

	friend class LEngine;

public:

	LGameLogicSystem();
	~LGameLogicSystem();

	//Initialize game logic and input handling
	void Initialize();

	//Loop of this system
	//Runs LogicLoop on another thread
	void SystemLoop();

	//Game logic resources mutex, used for thread safety
	static std::mutex LogicMutex;

	//System closing flag
	bool bCloseSystem;

	template<typename T>
	std::shared_ptr<T> CreateActor();

private:

	//Game logic is processed here
	void LogicLoop();

	//Thread handle
	std::thread LogicThread;

	HWorld* World;
};