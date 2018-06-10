//
// EPITECH PROJECT, 2018
// indie
// File description:
// menu audio
//

#pragma once

#include "Game.hpp"
#include "IMenu.hpp"

namespace bbm {
	class MenuAudio : public IMenu {
		public:
			MenuAudio(Game &game, bool scene = false);
			~MenuAudio();
			virtual bool OnEvent(const irr::SEvent &) override;
			virtual bool run();
			virtual void draw();
			void	enableButtons(bool);
			bool	takeActions(irr::s32);
			void	setupButtons(
				const irr::core::dimension2du& screenSize,
				const irr::core::dimension2du& buttonSize);
			void	drawScaleSound(bbm::ButtonInfos &, int);
			void	drawSounds(const irr::core::dimension2du&);
			bool	keysHandling(const irr::SEvent &event);
			bool	changeVolume();
			void	drawBackground(const irr::core::dimension2du&);
			void	drawSceneBackground(
				const irr::core::dimension2du&);
			void	goBack();

		protected:
		private:
	};
}
