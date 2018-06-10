//
// EPITECH PROJECT, 2018
// indie
// File description:
// menu new game
//

#pragma once

#include "Game.hpp"
#include "IMenu.hpp"
#include "MenuLobby.hpp"

namespace bbm {
	class MenuNewGame : public IMenu {
		public:
			MenuNewGame(Game &game);
			~MenuNewGame();
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
			bool	keysHandling(const irr::SEvent &event);
			bool	changeAttr();
			void	drawAttr(const irr::core::dimension2du&);
			void	drawBackground(const irr::core::dimension2du&);
			void	setupAttrs();
			irr::video::ITexture *getImageByAttr(bbm::AttrEntity);
			void	drawImage(bbm::ButtonInfos &,
			irr::video::ITexture *);
			void	startGame();
			void	setupTeams();
			void	drawTeams(const irr::core::dimension2du&);
			void	drawTeamColor(int idx, bbm::ButtonInfos &);
			void	goBack();

		protected:
			std::vector<bbm::AttrEntity>	_attrs;
			std::vector<bbm::TeamColor>	_teams;
			std::vector<std::pair<bbm::AttrEntity,
			irr::video::ITexture *>>	_attrimgs;
			MenuLobby	*_lobby;
		private:
	};
}
