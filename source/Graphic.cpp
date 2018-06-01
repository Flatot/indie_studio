//
// EPITECH PROJECT, 2018
// Graphic.cpp
// File description:
// Graphic implementation
//

#include "Graphic.hpp"

bbm::Graphic::Graphic(int width, int height, bool fullscreen, 
		IMyEventReceiver *evReceiver) :
	_width(width),
	_height(height),
	_fullscreen(fullscreen)
{
	_device = irr::createDevice(irr::video::EDT_SOFTWARE /*EDT_OPENGL*/, irr::core::dimension2d<irr::u32>(_width, _height), 32, _fullscreen, false, false, evReceiver);
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
