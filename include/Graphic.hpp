//
// EPITECH PROJECT, 2018
// Graphic.hh
// File description:
// Graphic class
//

#pragma once

#include "irrlicht.h"

namespace bbm {
	class Graphic {
	public:
		Graphic(int width, int height);
		Graphic(bool fullscreen);
	private:
		irr::IrrlichtDevice *_device;
		irr::video::IVideoDriver *_driver;
		irr::scene::ISceneManager *_scene;
		irr::gui::IGUIEnvironment *_guienv;
	};
}
