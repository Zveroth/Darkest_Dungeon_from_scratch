#pragma once



struct GLFWwindow;

class LRenderer
{

public:

	LRenderer();
	~LRenderer();

	void Initialize();

private:

	GLFWwindow* m_Window;
};