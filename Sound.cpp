#include "include.h"

FMOD::System* Sound::system = nullptr;

Sound::Sound()
{
	channel = nullptr;
	sound = nullptr;
}

Sound::~Sound()
{
	if (sound)
		sound->release();

	if (system)
	{
		system->close();
		system->release();
	}
}

void Sound::LoadSoundFile(std::string path, bool loop)
{
	// 조건식 ? 값1 : 값, true = 값1 false = 값2
	FMOD_MODE mode = loop ? FMOD_LOOP_NORMAL : FMOD_LOOP_OFF;
	FMOD_RESULT result = system->createSound(path.c_str(), mode, nullptr, &sound);
	if (result != FMOD_OK)
	{
		std::cerr << "Error" << std::endl;
	}
}

void Sound::Playsound()
{
	if (sound)
	{
		system->playSound(sound, nullptr, false, &channel);
	}
}

void Sound::StopSound()
{
	if (channel)
	{
		channel->stop();
	}
}

void Sound::Update()
{
	system->update();
}
