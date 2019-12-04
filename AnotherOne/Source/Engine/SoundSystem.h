#pragma once



namespace irrklang
{
	class ISoundEngine;
}

class LSoundSystem
{

public:

	LSoundSystem();
	~LSoundSystem();

	void Initialize();

private:

	irrklang::ISoundEngine* m_SoundEngine;
};