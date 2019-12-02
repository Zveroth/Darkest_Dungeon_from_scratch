#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "assert.h"
#include "stdio.h"

#include "Renderer.h"


LRenderer::LRenderer() : m_Window(nullptr)
{

}

LRenderer::~LRenderer()
{
	glfwTerminate();
}

void LRenderer::Initialize()
{
	//OpenGL
	if (!glfwInit())
	{
		printf("Couldn't initialize glfw\n\n");
		assert(false);
	}

	m_Window = glfwCreateWindow(960, 540, "Help", nullptr, nullptr);
	if (!m_Window)
	{
		printf("Couldn't create a window\n\n");
		assert(false);
	}

	glfwMakeContextCurrent(m_Window);

	if (glewInit() != GLEW_OK)
	{
		glfwTerminate();
		printf("Couldn't initialize glew\n\n");
		assert(false);
	}
	//--OpenGL
}