#pragma once



class LInputHandler;

class LGameLogicSystem
{

public:

	LGameLogicSystem();
	~LGameLogicSystem();

	//Initialize game logic and input handling
	void Initialize();

private:

	//Reference to the input handler
	LInputHandler* m_InputHandler;
};