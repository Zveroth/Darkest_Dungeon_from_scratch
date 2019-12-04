#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Renderer.h"
#include "Debugging/DebugMacros.h"


LRenderer::LRenderer() : m_Window(nullptr)
{

}

LRenderer::~LRenderer()
{
	glfwTerminate();
}

void LRenderer::Initialize()
{
	if (!glfwInit())//Start initializing OpenGl
	{
		FatalError("Couldn't initialize glfw\n\n");
	}

	m_Window = glfwCreateWindow(960, 540, "Help", nullptr, nullptr);//Create an OpenGl window
	if (!m_Window)
	{
		glfwTerminate();//Clean up
		FatalError("Couldn't create a window\n\n");
	}

	glfwMakeContextCurrent(m_Window);

	if (glewInit() != GLEW_OK)//Finalize
	{
		glfwTerminate();//Clean up
		FatalError("Couldn't initialize glew\n\n");
	}
}