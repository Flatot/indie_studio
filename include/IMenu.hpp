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
#include "Definer.hpp"
#include "Button.hpp"

namespace bbm {
	class Game;

	class IMenu : public IMyEventReceiver {
	public:
		IMenu(Game &game);
		virtual bool OnEvent(const irr::SEvent &event) = 0;
		virtual bool run() = 0;
		virtual void draw() = 0;
		void previousOne();
		void nextOne();
		EventManager *getEventManager();
	protected:
		Game &_game;
		EventManager *_evManager;
		Graphic &_graphic;
		std::map<std::wstring, IMenu *> _menus;
		// std::vector<irr::gui::IGUIButton *>	_buttons;
		int	_focused;
		irr::video::ITexture	*_background;
		std::vector<bbm::Button *>	_btns;
		irr::video::ITexture	*_white;
		bool	_scene;

	};
}
