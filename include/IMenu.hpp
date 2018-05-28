//
// EPITECH PROJECT, 2018
// IMenu.hpp
// File description:
// IMenu interface
//

#pragma once

#include <string>
#include <map>

#include "IEventReceiver.h"
#include "IGUIElement.h"

// #include "Graphic.hpp"

namespace bbm {
	class Game;

	class IMenu : public irr::IEventReceiver, irr::gui::IGUIElement {
	public:
		IMenu(Game &game);
		virtual bool OnEvent(irr::SEvent &event) = 0;
		virtual bool run() = 0;
		virtual void draw() = 0;
	protected:
		Game &_game;
		// Graphic &_graphic;
		bool _isActive;
		std::map<std::wstring, IMenu *> _menus;
	};
}
