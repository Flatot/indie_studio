//
// EPITECH PROJECT, 2018
// indie
// File description:
// menu video
//

#pragma once

#include "Game.hpp"
#include "IMenu.hpp"

namespace bbm {
	class MenuVideo : public IMenu {
		public:
			MenuVideo(Game &game, bool scene = false);
			~MenuVideo();
			virtual bool OnEvent(const irr::SEvent &) override;
			virtual bool run();
			virtual void draw();
			void	enableButtons(bool);
			bool	takeActions(irr::s32);
			void	setupButtons(
				const irr::core::dimension2du& screenSize,
				const irr::core::dimension2du& buttonSize);
			bool	keysHandling(const irr::SEvent &event);
			bool	changeResolution();
			void	drawRes(const irr::core::dimension2du&);
			void	drawBackground(const irr::core::dimension2du&);
			void	drawSceneBackground(
				const irr::core::dimension2du&);
			void	updateResolution();
			void	setupResolution(
				const irr::core::dimension2du&);
			void	goBack();
			void	lookForResolution();

		protected:
		private:
			int	_idxres;
			std::vector<std::pair<int, int>>	_resolutions;
			irr::gui::IGUIStaticText	*_res;
	};
}
