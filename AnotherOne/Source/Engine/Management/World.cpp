#pragma once
#include "World.h"
#include "Engine/Objects/Actor.h"
#include "Engine/Engine.h"




template<typename T>
std::weak_ptr<T> HWorld::CreateActor()
{
	m_ActorList.push_front(static_cast<std::shared_ptr<HActor>>(LEngine::Engine->CreateActor<T>()));
	return m_ActorList.front();//The actor is 100% at the front, IF m_ActorList isn't a multithread resource
}