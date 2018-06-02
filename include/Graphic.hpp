//
// EPITECH PROJECT, 2018
// Graphic.hh
// File description:
// Graphic class
//

#pragma once

#include "irrlicht.h"
#include "IMyEventReceiver.hpp"

namespace bbm {
	class Graphic {
	public:
		Graphic(int width, int height, bool fullscreen, 
				IMyEventReceiver *evReceiver);
		irr::IrrlichtDevice *getDevice();
		irr::video::IVideoDriver *getDriver();
		irr::scene::ISceneManager *getScene();
		irr::gui::IGUIEnvironment *getGuienv();
		irr::ILogger *getLogger();
		void setWindowCaption(const irr::core::vector3df &posCam, 
				const wchar_t *str);
		void setWindowCaption(const irr::core::vector3df &posCam);
		void setWindowCaption(const wchar_t *str);
		void setWindowCaption();
				

	private:
		int _width;
		int _height;
		bool _fullscreen;
		irr::IrrlichtDevice *_device;
		irr::video::IVideoDriver *_driver;
		irr::scene::ISceneManager *_scene;
		irr::gui::IGUIEnvironment *_guienv;

	};
}
