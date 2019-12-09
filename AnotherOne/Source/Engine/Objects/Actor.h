#pragma once
#include "forward_list"
#include "memory"

#include "Components/Component.h"



class HActor
{
	friend class LEngine;

public:

//private:
protected:

	std::forward_list<std::shared_ptr<IComponent>> m_ComponentList;
};