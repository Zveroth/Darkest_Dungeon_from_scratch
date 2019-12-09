#pragma once
#include "memory"



class HActor;
class LGameLogicSystem;

class HWorld
{
	friend class LGameLogicSystem;

public:

	//Create an actor of a given class
	//Provided class must inherit HActor
	template<typename T>
	std::weak_ptr<T> CreateActor();

private:

	//Reference to owning system
	LGameLogicSystem* GameLogic;
};