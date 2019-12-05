#pragma once
#include "thread"
#include "mutex"


class LGameLogicSystem
{

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

private:

	//Game logic is processed here
	void LogicLoop();

	//Thread handle
	std::thread LogicThread;
};