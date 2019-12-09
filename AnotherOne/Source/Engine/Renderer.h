#pragma once
#include "list"
#include "forward_list"
#include "memory"
#include "mutex"


struct GLFWwindow;
class LRenderComponent;

class LRenderer
{

	friend class LEngine;

public:

	LRenderer();
	~LRenderer();

	//Prepare OpenGl for work
	void Initialize();

	//Loop of this system
	//Rendering takes place here
	void SystemLoop();

	static std::mutex m_PendingComp_Mutex;

private:

	//Reference to the created OpenGl window
	GLFWwindow* m_Window;

	//List of components that are rendered
	std::list<std::shared_ptr<LRenderComponent>> m_RenderedComponents;

	//List of components that are waiting to be added to m_RenderedComponents
	//They are added at the end of a tick
	std::forward_list<std::shared_ptr<LRenderComponent>> m_PendingComponents;
};