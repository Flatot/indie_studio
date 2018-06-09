//
// EPITECH PROJECT, 2018
// indie
// File description:
// main menu header
//

#pragma once

#include "Game.hpp"
#include "IMenu.hpp"
#include "MenuNewGame.hpp"

namespace bbm {
	class MenuMain : public IMenu {
		public:
			MenuMain(Game &game);
			~MenuMain();
			virtual bool OnEvent(const irr::SEvent &) override;
			virtual bool run();
			virtual void draw();
			void	quitGame(void);
			void	runSettings(void);
			void	runNewGame(void);
			void	enableButtons(bool);
			bool	takeActions(irr::s32);
			void	setupButtons(
				const irr::core::dimension2du& screenSize,
				const irr::core::dimension2du& buttonSize);
			void	drawBackground(const irr::core::dimension2du&);
			void	continueGame();
			void	initLoadImages();
			void	setupLoadButton();

		protected:
			IMenu *_settingsMenu;
			IMenu *_newGameMenu;
			irr::video::ITexture	*_bomberman;
			std::vector<irr::video::ITexture *> _loadImgs;
			bool	_gameToLoad;
		private:
	};
}