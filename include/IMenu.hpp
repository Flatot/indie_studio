//
// EPITECH PROJECT, 2018
// IMenu.hpp
// File description:
// IMenu interface
//

#pragma once

#include <string>
#include <map>

#include "IMyEventReceiver.hpp"
#include "EventManager.hpp"
#include "Graphic.hpp"

namespace bbm {
	class Game;

	class IMenu : public IMyEventReceiver {
	public:
		IMenu(Game &game);
		virtual bool OnEvent(const irr::SEvent &event) = 0;
		virtual bool run() = 0;
		virtual void draw() = 0;
		EventManager *getEventManager();
	protected:
		Game &_game;
		EventManager *_evManager;
		Graphic &_graphic;
		std::map<std::wstring, IMenu *> _menus;

	};
}
