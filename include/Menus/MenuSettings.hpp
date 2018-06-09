//
// EPITECH PROJECT, 2018
// indie
// File description:
// settings menu
//

#pragma once

#include "Game.hpp"
#include "IMenu.hpp"
#include "MenuAudio.hpp"
#include "MenuVideo.hpp"
#include "MenuControls.hpp"

namespace bbm {
	class MenuSettings : public IMenu {
		public:
			MenuSettings(Game &game, bool scene = false);
			~MenuSettings();
			virtual bool OnEvent(const irr::SEvent &) override;
			virtual bool run();
			virtual void draw();
			void	enableButtons(bool);
			bool	takeActions(irr::s32);
			void	setupButtons(
				const irr::core::dimension2du& screenSize,
				const irr::core::dimension2du& buttonSize);
			void	drawBackground(const irr::core::dimension2du&);
			void	drawSceneBackground(
				const irr::core::dimension2du&);

		protected:
			IMenu *_audioMenu;
			IMenu *_videoMenu;
			IMenu *_controlsMenu;
			irr::video::ITexture	*_bomberman;
		private:
	};
}
