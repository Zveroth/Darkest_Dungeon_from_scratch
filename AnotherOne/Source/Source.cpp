#pragma once
#include "assert.h"
#include "stdio.h"

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
	LEngine* Engine = new LEngine();
	if (Engine)
	{
		Engine->Initialize();

		Engine->Terminate();
		delete Engine;
	}
	else
	{
		printf("Couldn't allocate memory for the engine class (%d B)\n\n", sizeof(LEngine));
		assert(false);
	}
	return 0;
}