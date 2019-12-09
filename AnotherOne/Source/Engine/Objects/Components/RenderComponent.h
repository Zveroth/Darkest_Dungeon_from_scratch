#pragma once
#include "Component.h"
#include "Engine/Rendering/RenderInfo.h"



class LRenderComponent : public IComponent
{

public:

	LRenderComponent();

	virtual unsigned int GetComponentFlags() override;

protected:

	//OpenGL stuff
	VertexArray VAO;
	VertexBuffer VBO;
	IndexBuffer EBO;

	bool m_bRenderReady;
};