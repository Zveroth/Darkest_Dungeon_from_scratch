#pragma once
#include "Renderer.h"
#include "SoundSystem.h"
#include "GameLogicSystem.h"


class HActor;

//Engine class manages all the other subsystems 
//and provides communication between them
class LEngine
{

public:

	LEngine();
	~LEngine();

	//Global getter for the engine instance
	static LEngine* Engine;

	//Initializes all subsystems and prepares the engine.
	//If someting goes wrong, the program will be terminated
	void Initialize();

	//Call the subsystems' loops and perform a clean exit once done
	void GameLoop();

	//Terminate all subsystems
	//Note that engine still needs a delete call for itself
	void Terminate();

	//Getter for the OpenGL window
	inline GLFWwindow* GetWindow() { return m_Renderer->m_Window; }
	
	HWorld* GetWorld() { return m_GameLogic->World; }

	template<typename T>
	std::shared_ptr<T> CreateActor();

private:

	//Subsystem pointers
	LRenderer* m_Renderer;
	LSoundSystem* m_SoundSystem;
	LGameLogicSystem* m_GameLogic;
};