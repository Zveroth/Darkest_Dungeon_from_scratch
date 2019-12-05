#pragma once


struct GLFWwindow;

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

private:

	//Reference to the created OpenGl window
	GLFWwindow* m_Window;
};