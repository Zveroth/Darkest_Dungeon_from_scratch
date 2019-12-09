#pragma once
#include "memory"

#include "RenderComponent.h"
#include "Engine/Rendering/Texture.h"



class HSpriteComponent : public LRenderComponent
{

public:

	HSpriteComponent();

	unsigned int GetComponentFlags() override;

private:

	void PrepareIndices();
	void PrepareVertices();
	void PrepareCoords();
	void PrepareBuffers();

	std::shared_ptr<Texture> Sprite;

	float Vertices[20];
	unsigned int Indices[6];
};