#pragma once
#include "memory"
#include "forward_list"



class HActor;

class HWorld
{

public:

	template<typename T>
	std::weak_ptr<T> CreateActor();

private:

	std::forward_list<std::shared_ptr<HActor>> m_ActorList;
};