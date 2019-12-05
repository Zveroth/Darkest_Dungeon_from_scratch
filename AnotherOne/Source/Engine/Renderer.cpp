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

void LRenderer::SystemLoop()
{
	glClearColor(0.25f, 0.25f, 0.25f, 1.0f);//The default color of pixels that are not drawn

	while (!glfwWindowShouldClose(m_Window))
	{
		glClear(GL_COLOR_BUFFER_BIT);//Clear buffers

		//printf("Render loop\n");

		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}
}