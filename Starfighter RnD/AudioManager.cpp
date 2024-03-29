#include "stdafx.h"
#include "AudioManager.h"


AudioManager::AudioManager()
{
	buffers.push_back(sf::SoundBuffer());
	sounds.push_back(sf::Sound());
}


AudioManager::~AudioManager()
{
}

void AudioManager::LoadSounds()
{
	//buffer.loadFromFile("ASSETS/ship acceleration sound 2.wav");
	
	buffers.at(0).loadFromFile("ASSETS/Sounds/FX/shootSound3.wav");
	sounds.at(0).setBuffer(buffers.at(0));
	sounds.at(0).setVolume(10);
}
