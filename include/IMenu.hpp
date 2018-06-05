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

	struct	ButtonInfos {
		int	startX;
		int	startY;
		int	endX;
		int	endY;
	};

	struct Position {
		int	index;
		int	total;
	};

	struct PositionMultiple {
		int	index;
		int	total;
		int	top;
	};

	enum IdButton {
		GUI_BUTTON_QUIT = 101,
		GUI_BUTTON_SAVEQUIT,
		GUI_BUTTON_SETTINGS,
		GUI_BUTTON_VIDEO,
		GUI_BUTTON_CONTROLS,
		GUI_BUTTON_AUDIO,
		GUI_BUTTON_RESUME,
		GUI_BUTTON_END,
		GUI_BUTTON_CONTINUE,
		GUI_BUTTON_NEWGAME,
		GUI_BUTTON_BACK
	};

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
		std::vector<irr::gui::IGUIButton *>	_buttons;
		int	_focused;

	};
}
