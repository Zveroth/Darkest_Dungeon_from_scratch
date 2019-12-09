#pragma once
#include "World.h"
#include "Engine/Objects/Actor.h"
#include "Engine/GameLogicSystem.h"




template<typename T>
std::weak_ptr<T> HWorld::CreateActor()
{
	//This is just a wrapper
	return GameLogic->CreateActor<T>();
}