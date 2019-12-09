#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Renderer.h"
#include "Objects/Components/RenderComponent.h"
#include "Debugging/DebugMacros.h"


std::mutex LRenderer::m_PendingComp_Mutex;

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

		std::list<std::shared_ptr<LRenderComponent>>::iterator itr = m_RenderedComponents.begin();
		while (itr != m_RenderedComponents.end())
		{
			std::list<std::shared_ptr<LRenderComponent>>::iterator Cache = itr;//Cache the iterator in case the component needs to be removed
			itr++;

			std::shared_ptr<LRenderComponent> Component = *Cache;

			//Do some rendering

			if (Component->bPendingDestroy)//Check if the component is awaiting destruction
			{
				m_RenderedComponents.erase(itr);
			}
		}


		{
			std::unique_lock<std::mutex> SafetyLock(LRenderer::m_PendingComp_Mutex, std::try_to_lock);//Try to get access to pending components
			if (SafetyLock)
			{
				for (std::shared_ptr<LRenderComponent>& Component : m_PendingComponents)//Iterate over them
				{
					m_RenderedComponents.push_back(Component);
				}
				m_PendingComponents.clear();//Clean up
				SafetyLock.unlock();
			}
		}

		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}
}