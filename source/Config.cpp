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
	_volumeEffect(50)
{

}

void bbm::Config::loadConfig()
{
	
}

int bbm::Config::getScreenWidth()
{
	return _screenWidth;
}

int bbm::Config::getScreenHeight()
{
	return _screenHeight;
}

bool bbm::Config::getFullscreen()
{
	return _fullscreen;
}
