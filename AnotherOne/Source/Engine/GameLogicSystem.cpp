#include "GameLogicSystem.h"
#include "InputHandler.h"
#include "Debugging/DebugMacros.h"



LGameLogicSystem::LGameLogicSystem() : m_InputHandler(nullptr)
{

}

LGameLogicSystem::~LGameLogicSystem()
{
	if (m_InputHandler)
		delete m_InputHandler;
}

void LGameLogicSystem::Initialize()
{
	//WARNING
	//Input handler requires OpenGl to be already initialized
	m_InputHandler = new LInputHandler();
	if (!m_InputHandler)
		FatalError_Size("Couldn't allocate memory for input handler class (%d B)\n\n", sizeof(LInputHandler));
	m_InputHandler->Initialize(this);
}