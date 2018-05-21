//
// EPITECH PROJECT, 2018
// main.cpp
// File description:
// main
//

#include "irrlicht.h"
#include "Game.hpp"

int main()
{
	irr::IrrlichtDevice *device = irr::createDevice(
					irr::video::EDT_SOFTWARE, 
					irr::core::dimension2d<irr::u32>(640, 480), 
					32, false, false, false, 0
					);
	irr::video::IVideoDriver *driver = device->getVideoDriver();
	irr::scene::ISceneManager *smgr = device->getSceneManager();
	irr::gui::IGUIEnvironment *guienv = device->getGUIEnvironment();
		
	device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");

	guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!",
			irr::core::rect<irr::s32>(10,10,260,22), false);


	while(device->run()) {
		driver->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));
		
		guienv->drawAll();
		driver->endScene();
	}
	device->drop();

	return 0;
}
