//
// EPITECH PROJECT, 2018
// Audio.cpp
// File description:
// Audio implementation
//

#include <iostream>
#include "Audio.hpp"

bbm::Audio::Audio(int generalVolume, int effectVolume)
{
	bool ret = true;

	ret &= _menuPlayer.openFromFile("./assets/sound/menu.ogg");
	ret &= _inGamePlayer.openFromFile("./assets/sound/inGame.ogg");
	ret &= _bBombExplode.loadFromFile("./assets/sound/bomb.ogg");
	ret &= _bPlayerDie.loadFromFile("./assets/sound/error.ogg");
	ret &= _bError.loadFromFile("./assets/sound/error.ogg");
	ret &= _bVolumeUp.loadFromFile("./assets/sound/error.ogg");
	ret &= _bVolumeDown.loadFromFile("./assets/sound/error.ogg");
	if (!ret) {
		std::cerr << "Sound load file error" << std::endl;
		exit(84);
	}
	_menuPlayer.setLoop(true);
	_inGamePlayer.setLoop(true);
	setGeneralVolume(generalVolume);
	setEffectVolume(effectVolume);
}

int bbm::Audio::getEffectVolume()
{
	return _soundEffect.getVolume();
}

int bbm::Audio::getGeneralVolume()
{
	return _menuPlayer.getVolume();
}

void bbm::Audio::setEffectVolume(int volume)
{
	_soundEffect.setVolume(volume);
}

void bbm::Audio::setGeneralVolume(int volume)
{
	_menuPlayer.setVolume(volume);
	_inGamePlayer.setVolume(volume);
}

void bbm::Audio::playMenuMusic()
{
	_menuPlayer.play();
}

void bbm::Audio::stopMenuMusic()
{
	_menuPlayer.stop();
}

void bbm::Audio::playInGameMusic()
{
	_inGamePlayer.play();
}

void bbm::Audio::stopInGameMusic()
{
	_inGamePlayer.stop();
}

void bbm::Audio::playBombeExplode()
{
	_soundEffect.setBuffer(_bBombExplode);
	_soundEffect.play();
}

void bbm::Audio::playPlayerDie()
{
	_soundEffect.setBuffer(_bPlayerDie);
	_soundEffect.play();
}

void bbm::Audio::playError()
{
	_soundEffect.setBuffer(_bError);
	_soundEffect.play();
}

void bbm::Audio::playVolumeUp()
{
	_soundEffect.setBuffer(_bVolumeUp);
	_soundEffect.play();
}

void bbm::Audio::playVolumeDown()
{
	_soundEffect.setBuffer(_bVolumeDown);
	_soundEffect.play();
}
