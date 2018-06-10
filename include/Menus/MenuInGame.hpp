//
// EPITECH PROJECT, 2018
// indie
// File description:
// in game menu
//

#pragma once

#include "Game.hpp"
#include "IMenu.hpp"
#include "MenuSettings.hpp"

namespace bbm {
	class MenuInGame : public IMenu {
		public:
			MenuInGame(Game &game);
			~MenuInGame();
			virtual bool OnEvent(const irr::SEvent &) override;
			virtual bool run();
			virtual void draw();
			void	enableButtons(bool);
			bool	takeActions(irr::s32);
			void	setupButtons(
				const irr::core::dimension2du& screenSize,
				const irr::core::dimension2du& buttonSize);
			void	actionsClosing(irr::s32 id);
			bool	keysHandling(const irr::SEvent &);
			void	goBack();

		protected:
			IMenu *_settingsMenu;
		private:
	};
}
