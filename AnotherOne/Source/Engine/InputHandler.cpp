#include "InputHandler.h"
#include "Engine/Engine.h"
#include "GameLogicSystem.h"

#include "GLFW/glfw3.h"



LInputHandler::LInputHandler()
{
	m_ProcessedInputs =
	{
		//Provide the desired input keys here
		//GLFW_KEY_1
	};
}

void LInputHandler::Initialize(LGameLogicSystem* OwningLogic)
{
	glfwSetMouseButtonCallback(LEngine::Engine->GetWindow(), this->ProcessMouseInput);//Set the mouse input callback function

	m_OwningLogic = OwningLogic;
}

void LInputHandler::ProcessMouseInput(GLFWwindow* window, int button, int action, int mods)
{

}

void LInputHandler::ProcessKeyboardInput()
{

}