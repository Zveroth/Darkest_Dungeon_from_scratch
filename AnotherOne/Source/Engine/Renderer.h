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

private:

	//Reference to the created OpenGl window
	GLFWwindow* m_Window;
};