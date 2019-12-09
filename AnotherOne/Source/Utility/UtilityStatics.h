#pragma once



class HWorld;
struct GLFWwindow;

class UtilityStatics
{

public:

	//Returns the world managed by the game logic subsystem
	static HWorld* GetWorld();

	//Returns the window managed by the rendering subsystem
	static GLFWwindow* GetWindow();

private:

	UtilityStatics() {};
	UtilityStatics(const UtilityStatics& Statics) = delete;
};