#pragma once
#include "Component.h"



class LRenderComponent : public IComponent
{

public:

	virtual unsigned int GetComponentFlags() override;

	virtual void Draw() = 0;
};