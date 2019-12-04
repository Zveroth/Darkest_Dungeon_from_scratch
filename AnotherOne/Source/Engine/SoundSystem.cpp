#include "SoundSystem.h"
#include "irrKlang.h"

#include "Debugging/DebugMacros.h"

LSoundSystem::LSoundSystem() : m_SoundEngine(nullptr)
{

}

LSoundSystem::~LSoundSystem()
{
	if (m_SoundEngine)
		m_SoundEngine->drop();
}

void LSoundSystem::Initialize()
{
	m_SoundEngine = irrklang::createIrrKlangDevice();

	if (!m_SoundEngine)
	{
		FatalError("Couldn't initialize ISoundEngine\n\n");
	}
}