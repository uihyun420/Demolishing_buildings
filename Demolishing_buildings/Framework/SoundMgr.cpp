#include "stdafx.h"
#include "SoundMgr.h"

void SoundMgr::Init(int totalChannels)
{
	audioIds.push_back("sounds/attack.wav");
	audioIds.push_back("sounds/building.wav");
	audioIds.push_back("sounds/buildingbreak.wav");
	audioIds.push_back("sounds/click.wav");
	audioIds.push_back("sounds/specialattack.wav");
	audioIds.push_back("sounds/swish.wav");

	for (int i = 0; i < audioIds.size(); i++) {
		sf::SoundBuffer soundBuffer;
		soundBuffer.loadFromFile(audioIds[i]);
		soundBuffers.push_back(soundBuffer);
	}
	for (int i = 0; i < soundBuffers.size(); i++) {
		sf::Sound sound;
		sound.setBuffer(soundBuffers[i]);
		sounds.push_back(sound);
	}


	for (int i = 0; i < totalChannels; ++i)
	{
		sf::Sound* sound = new sf::Sound();
		sound->setVolume(sfxVolume);
		waiting.push_back(sound);
	}
}

void SoundMgr::Release()
{
	for (auto sound : waiting)
	{
		delete sound;
	}
	waiting.clear();
	for (auto sound : playing)
	{
		delete sound;
	}
	playing.clear();
}

void SoundMgr::Update(float dt)
{
	auto it = playing.begin();
	while (it != playing.end())
	{
		if ((*it)->getStatus() == sf::Sound::Stopped)
		{
			waiting.push_back(*it);
			playing.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void SoundMgr::PlayBgm(std::string id, bool loop)
{
	PlayBgm(SOUNDBUFFER_MGR.Get(id), loop);
}

void SoundMgr::PlayBgm(sf::SoundBuffer& buffer, bool loop)
{
	bgm.stop();
	bgm.setLoop(loop);
	bgm.setBuffer(buffer);
	bgm.play();
}

void SoundMgr::StopBgm()
{
	bgm.stop();
}

void SoundMgr::PlaySfx(std::string id, bool loop)
{
	PlaySfx(SOUNDBUFFER_MGR.Get(id), loop);
}

void SoundMgr::PlaySfx(sf::SoundBuffer& buffer, bool loop)
{
	sf::Sound* sound = nullptr;

	if (waiting.empty())
	{
		sound = playing.front();
		playing.pop_front();
		sound->stop();
	}
	else
	{
		sound = waiting.front();
		waiting.pop_front();
	}

	sound->setBuffer(buffer);
	sound->setLoop(loop);
	sound->play();
	playing.push_back(sound);
}

void SoundMgr::SetSfxVolume(float v)
{
	sfxVolume = v;
	for (auto sound : playing)
	{
		sound->setVolume(sfxVolume);
	}
}

void SoundMgr::StopAllSfx()
{
	for (auto sound : playing)
	{
		sound->stop();
		waiting.push_back(sound);
	}
	playing.clear();
}

void SoundMgr::Play(Audio id)
{
	sounds[(int)id].play();
}
