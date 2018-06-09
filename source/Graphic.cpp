//
// EPITECH PROJECT, 2018
// Graphic.cpp
// File description:
// Graphic implementation
//

#include <iostream>
#include "Graphic.hpp"

bbm::Graphic::Graphic(int width, int height, bool fullscreen, 
		IMyEventReceiver *evReceiver) :
	_width(width),
	_height(height),
	_fullscreen(fullscreen),
	_evReceiver(evReceiver)
{
	// _driverType = irr::driverChoiceConsole();
	_driverType = irr::video::EDT_OPENGL;
	setupDevice();
}

void	bbm::Graphic::clearDevice()
{
	_device->drop();
}

void	bbm::Graphic::setupDevice()
{
	_device = irr::createDevice(_driverType, irr::core::dimension2d<irr::u32>(_width, _height), 32, _fullscreen, false, false, _evReceiver);
	_device->setResizable(false);
}

irr::IrrlichtDevice *bbm::Graphic::getDevice()
{
	return _device;
}

irr::video::IVideoDriver *bbm::Graphic::getDriver()
{
	return _device->getVideoDriver();
}

irr::scene::ISceneManager *bbm::Graphic::getScene()
{
	return _device->getSceneManager();
}

irr::gui::IGUIEnvironment *bbm::Graphic::getGuienv()
{
	return _device->getGUIEnvironment();
}
	
irr::ILogger *bbm::Graphic::getLogger()
{
	return _device->getLogger();
}

void	bbm::Graphic::setDevice(irr::IrrlichtDevice *device)
{
	_device = device;
}

irr::video::E_DRIVER_TYPE	bbm::Graphic::getDriverType() const
{
	return _driverType;
}

void	bbm::Graphic::setWidth(int width)
{
	_width = width;
}

void	bbm::Graphic::setHeight(int height)
{
	_height = height;
}

void	bbm::Graphic::setFullscreen(bool fullscreen)
{
	_fullscreen = fullscreen;
}

void bbm::Graphic::setWindowCaption(const irr::core::vector3df &posCam, 
		const wchar_t *str)
{
	wchar_t title[256] = {0};
	static int lastFps = 0;
	int fps = getDriver()->getFPS();

	if (lastFps != fps)
		lastFps = fps;
	swprintf(title, 256, L"[%ls] X: [%f] Y: [%f] Z: [%f] FPS: [%d]", str, 
			posCam.X, posCam.Y, posCam.Z, fps);
	_device->setWindowCaption(title);
}

void bbm::Graphic::setWindowCaption(const irr::core::vector3df &posCam)
{
	setWindowCaption(posCam, L"");
}

void bbm::Graphic::setWindowCaption(const wchar_t *str)
{
	wchar_t title[256] = {0};
	static int lastFps = 0;
	int fps = getDriver()->getFPS();

	if (lastFps != fps)
		lastFps = fps;
	swprintf(title, 256, L"[%ls] FPS: [%d]", str, fps);
	_device->setWindowCaption(title);
}

void bbm::Graphic::setWindowCaption()
{
	setWindowCaption(L"");
}
