#pragma once
#include "RenderComponent.h"



class HSpriteComponent : public LRenderComponent
{

public:

	unsigned int GetComponentFlags() override;

	void Draw() override;
};