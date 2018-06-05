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
			MenuAudio(Game &game);
			~MenuAudio();
			virtual bool OnEvent(const irr::SEvent &event) override;
			virtual bool run();
			virtual void draw();

		protected:
		private:
	};
}
