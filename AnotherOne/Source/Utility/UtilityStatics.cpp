#include"UtilityStatics.h"
#include "Engine/Engine.h"



HWorld* UtilityStatics::GetWorld()
{
	return LEngine::Engine->GetWorld();
}

GLFWwindow* UtilityStatics::GetWindow()
{
	return LEngine::Engine->GetWindow();
}