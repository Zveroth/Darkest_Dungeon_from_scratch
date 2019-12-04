#pragma once
#include "assert.h"
#include "stdio.h"

#include "Debugging/DebugMacros.h"
#include "Engine/Engine.h"

/*Second attempt at making something from scratch.
This time with a more clear goal.
I will try to create Darkest Dungeon like game
using:
OpenGL for graphics (GLEW),
irrklang for sound
*/

int main()
{
	LEngine* Engine = new LEngine();//Create a new Engine instance

	if (Engine)//Safety check
	{
		LEngine::Engine = Engine;//Set the global getter for the enigne
		Engine->Initialize();//Initialize the subsystems

		//Engine->GameLoop();

		Engine->Terminate();//Destroy all subsystems
		delete Engine;//Final clean up
	}
	else
	{
		FatalError_Size("Couldn't allocate memory for the engine class (%d B)\n\n", sizeof(LEngine));
	}

	return 0;
}