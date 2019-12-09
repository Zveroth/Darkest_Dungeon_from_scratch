#include "InputHandler.h"
#include "Utility/UtilityStatics.h"
#include "GameLogicSystem.h"

#include "GLFW/glfw3.h"


LGameLogicSystem* LInputHandler::m_OwningLogic = nullptr;

std::forward_list<unsigned int> LInputHandler::m_ProcessedInputs =
{
	//Provide the desired input keys here for now
	//GLFW_KEY_1
};

void LInputHandler::Initialize(LGameLogicSystem* OwningLogic)
{
	glfwSetMouseButtonCallback(UtilityStatics::GetWindow(), &LInputHandler::ProcessMouseInput);//Set the mouse input callback function
	glfwSetKeyCallback(UtilityStatics::GetWindow(), &LInputHandler::ProcessKeyboardInput);//Set the key input callback function

	LInputHandler::m_OwningLogic = OwningLogic;
}

void LInputHandler::ProcessMouseInput(GLFWwindow* window, int button, int action, int mods)
{

}

void LInputHandler::ProcessKeyboardInput(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	
}