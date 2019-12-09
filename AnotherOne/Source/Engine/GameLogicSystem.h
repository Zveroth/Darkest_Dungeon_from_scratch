#pragma once
#include "thread"
#include "mutex"
#include "memory"
#include "forward_list"


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
	static std::mutex m_LogicMutex;

	//System closing flag
	bool bCloseSystem;

	template<typename T>
	std::weak_ptr<T> CreateActor();

private:

	//Game logic is processed here
	void LogicLoop();

	//Thread handle
	std::thread LogicThread;

	//Complete list of actors that are not waiting for destruction
	std::forward_list<std::shared_ptr<HActor>> m_ActorList;

	//Reference to world managed by this system
	HWorld* World;
};