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

#include "Game.hpp"
#include "Graphic.hpp"

namespace bbm {
	class IMenu : public irr::IEventReceiver, irr::gui::IGUIElement {
	public:
		IMenu(Game &game);
		virtual bool OnEvent(irr::SEvent &event) = 0;
		virtual bool run() = 0;
		virtual void draw() override;
	protected:
		Game &game;
		Graphic &graphic;
		bool isActive;
		std::map<std::wstring, IMenu *> menus;
	};
}
