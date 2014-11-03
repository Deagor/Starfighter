#pragma once
class AudioManager
{
public:
	static AudioManager* instance()
	{
		static AudioManager* mInstance = 0;

		if (mInstance == 0)
		{
			mInstance = new AudioManager();
		}

		return mInstance;
	}

	std::vector<sf::SoundBuffer>buffers;
	std::vector<sf::Sound>sounds;
	void LoadSounds();

private:
	AudioManager();
	
	~AudioManager();
};

