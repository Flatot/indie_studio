//
// EPITECH PROJECT, 2018
// Config.cpp
// File description:
// Config implementation
//

#include "Config.hpp"

bbm::Config::Config() :
	_fullscreen(false),
	_screenWidth(1280),
	_screenHeight(720),
	_volumeGeneral(50),
	_volumeEffect(90)
{

}

void bbm::Config::loadConfig()
{
	
}

int bbm::Config::getScreenWidth() const
{
	return _screenWidth;
}

int bbm::Config::getScreenHeight() const
{
	return _screenHeight;
}

void bbm::Config::setScreenWidth(int width)
{
	_screenWidth = width;
}

void bbm::Config::setScreenHeight(int height)
{
	_screenHeight = height;
}

bool bbm::Config::getFullscreen()
{
	return _fullscreen;
}

int	bbm::Config::getVolumeGeneral() const
{
	return _volumeGeneral;
}

void	bbm::Config::setVolumeGeneral(int volume)
{
	if (volume <= 0)
		_volumeGeneral = 0;
	else if (volume >= 100)
		_volumeGeneral = 100;
	else
		_volumeGeneral = volume;
}

int	bbm::Config::getVolumeEffect() const
{
	return _volumeEffect;
}

void	bbm::Config::setVolumeEffect(int volume)
{
	if (volume <= 0)
		_volumeEffect = 0;
	else if (volume >= 100)
		_volumeEffect = 100;
	else
		_volumeEffect = volume;
}
