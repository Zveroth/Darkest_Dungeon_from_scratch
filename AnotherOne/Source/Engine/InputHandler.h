#pragma once
#include "forward_list"


struct GLFWwindow;
class LGameLogicSystem;

class LInputHandler
{

	friend class LGameLogicSystem;

public:

	//Constructor sets m_ProcessedInputs for now
	LInputHandler();

	//Input handling calls
	void Initialize(LGameLogicSystem* OwningLogic);

	void ProcessMouseInput(GLFWwindow* window, int button, int action, int mods);

private:

	void ProcessKeyboardInput();

	//List of the inputs that will be passed down the input chain
	std::forward_list<unsigned int> m_ProcessedInputs;

	//Refrence to the owner
	LGameLogicSystem* m_OwningLogic;
};