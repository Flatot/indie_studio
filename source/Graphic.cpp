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
	_fullscreen(fullscreen)
{
	_device = irr::createDevice(irr::video::/*EDT_SOFTWARE*/ EDT_OPENGL, irr::core::dimension2d<irr::u32>(_width, _height), 32, _fullscreen, false, false, evReceiver);
	_driver = _device->getVideoDriver();
	_scene = _device->getSceneManager();
	_guienv = _device->getGUIEnvironment();
}

irr::IrrlichtDevice *bbm::Graphic::getDevice()
{
	return _device;
}

irr::video::IVideoDriver *bbm::Graphic::getDriver()
{
	return _driver;
}

irr::scene::ISceneManager *bbm::Graphic::getScene()
{
	return _scene;
}

irr::gui::IGUIEnvironment *bbm::Graphic::getGuienv()
{
	return _guienv;
}
	
irr::ILogger *bbm::Graphic::getLogger()
{
	return _device->getLogger();
}

void bbm::Graphic::setWindowCaption(const irr::core::vector3df &posCam, 
		const wchar_t *str)
{
	wchar_t title[256] = {0};
	static int lastFps = 0;
	int fps = _driver->getFPS();

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
	int fps = _driver->getFPS();

	if (lastFps != fps)
		lastFps = fps;
	swprintf(title, 256, L"[%ls] FPS: [%d]", str, fps);
	_device->setWindowCaption(title);
}

void bbm::Graphic::setWindowCaption()
{
	setWindowCaption(L"");
}
