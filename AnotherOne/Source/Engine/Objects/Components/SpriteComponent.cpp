#include "SpriteComponent.h"




HSpriteComponent::HSpriteComponent()
{
	Sprite = std::shared_ptr<Texture>(new Texture("Source/test.png"));

	PrepareIndices();
	PrepareVertices();

	PrepareBuffers();
}

unsigned int HSpriteComponent::GetComponentFlags()
{
	//Sprite don't need to be clickable but I will leave this for now
	return (EComponentFlags::RENDERABLE | EComponentFlags::CLICKABLE);
}

void HSpriteComponent::PrepareIndices()
{
	Indices[0] = 0;
	Indices[1] = 1;
	Indices[2] = 2;
	Indices[3] = 1;
	Indices[4] = 2;
	Indices[5] = 3;
}

void HSpriteComponent::PrepareVertices()
{
	PrepareCoords();

	//Setting Z
	Vertices[2] = 0.0f;
	Vertices[7] = 0.0f;
	Vertices[12] = 0.0f;
	Vertices[17] = 0.0f;

	//Texture coords
	Vertices[3] = 0.0f;
	Vertices[4] = 1.0f;

	Vertices[8] = 0.0f;
	Vertices[9] = 0.0f;

	Vertices[13] = 1.0f;
	Vertices[14] = 1.0f;

	Vertices[18] = 1.0f;
	Vertices[19] = 0.0f;
}

void HSpriteComponent::PrepareCoords()
{
	if (Sprite)
	{
		//Size of sprites
		float ExtentY = Sprite->GetHeight();// / (SPRITE_SIZE_RATIO * 10.0f);
		float ExtentX = Sprite->GetWidth();// / (SPRITE_SIZE_RATIO * 10.0f);

		//Setting X and Y based on sprite
		Vertices[0] = -ExtentX;
		Vertices[1] = ExtentY;

		Vertices[5] = -ExtentX;
		Vertices[6] = -ExtentY;

		Vertices[10] = ExtentX;
		Vertices[11] = ExtentY;

		Vertices[15] = ExtentX;
		Vertices[16] = -ExtentY;
	}
}

void HSpriteComponent::PrepareBuffers()
{
	//Create new data
	VAO.Generate();
	VBO.Generate();
	EBO.Generate();

	VAO.Bind();
	VBO.Bind();

	VBO.AddData(20 * sizeof(float), Vertices);

	EBO.Bind();
	EBO.AddData(6, Indices);

	BufferLayout Layout;
	Layout.Push<float>(3);
	Layout.Push<float>(2);

	VAO.CreateBuffer(Layout);

	glBindVertexArray(0);
}