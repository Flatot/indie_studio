//
// EPITECH PROJECT, 2018
// indie
// File description:
// menu controls
//

#pragma once

#include "Game.hpp"
#include "IMenu.hpp"

namespace bbm {
	class MenuControls : public IMenu {
		public:
			MenuControls(Game &game, bool scene = false);
			~MenuControls();
			virtual bool OnEvent(const irr::SEvent &) override;
			virtual bool run();
			virtual void draw();
			void	enableButtons(bool);
			bool	takeActions(irr::s32);
			void	setupButtons(
				const irr::core::dimension2du& screenSize,
				const irr::core::dimension2du& buttonSize);
			void	setupOtherButtons(
				const irr::core::dimension2du& screenSize,
				const irr::core::dimension2du& buttonSize);
			void	drawControls(const irr::core::dimension2du&);
			bool	keysHandling(const irr::SEvent &event);
			bool	changePlayer();
			void	drawBackground(const irr::core::dimension2du&);
			void	drawSceneBackground(
				const irr::core::dimension2du&);
			void	setupPlayerButton();
			void	changeControl(const irr::SEvent &);
			int	getIndexById(irr::s32);
			void	setupControls(const irr::core::dimension2du&);
			void	setControlsVisible(bool visible);
			const wchar_t	*getCharByCode(irr::EKEY_CODE);
			void	initializeControls();
			void	pimgInitialize(irr::video::IVideoDriver *);

		protected:
			int	_player;
			std::vector<irr::video::ITexture *>	_pimg;
			bool	_changing;
			std::vector<irr::gui::IGUIStaticText *>	_controls;
			std::vector<bbm::playerctrl>	_pctrl;
		private:
	};
}
