#pragma once
#include "Renderer.h"


class LEngine
{

public:

	LEngine();
	~LEngine();

	//Initializes all subsystems and prepares the engine.
	//If someting goes wrong, the program will be terminated
	void Initialize();

	//Terminate all subsystems
	//Note that engine still needs a delete call for itself
	void Terminate();

private:

	LRenderer* m_Renderer;
};