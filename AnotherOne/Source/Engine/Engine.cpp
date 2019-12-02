#include "assert.h"
#include "stdio.h"

#include "Engine.h"


LEngine::LEngine() : m_Renderer(nullptr)
{

}

LEngine::~LEngine()
{

}

void LEngine::Initialize()
{
	//Initialize all subsystems and assert if something fails

	m_Renderer = new LRenderer();
	if (!m_Renderer)
	{
		printf("Couldn't allocate memory for renderer clss (%d B)", sizeof(LRenderer));
		assert(false);
	}
	m_Renderer->Initialize();

}

void LEngine::Terminate()
{
	delete m_Renderer;
}