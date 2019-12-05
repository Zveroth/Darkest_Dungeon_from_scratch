#pragma once
#include "forward_list"


struct GLFWwindow;
class LGameLogicSystem;

class LInputHandler
{

	friend class LGameLogicSystem;

private:

	//Set the input handling calls
	static void Initialize(LGameLogicSystem* OwningLogic);

	static void ProcessMouseInput(GLFWwindow* window, int button, int action, int mods);

	static void ProcessKeyboardInput(GLFWwindow* window, int key, int scancode, int action, int mods);

	//List of the inputs that will be passed down the input chain
	static std::forward_list<unsigned int> m_ProcessedInputs;

	//Refrence to the owner
	static LGameLogicSystem* m_OwningLogic;
};