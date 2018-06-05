//
// EPITECH PROJECT, 2018
// indie
// File description:
// in game menu
//

#pragma once

#include "Game.hpp"
#include "IMenu.hpp"

namespace bbm {
	class MenuInGame : public IMenu {
		public:
			MenuInGame(Game &game);
			~MenuInGame();
			virtual bool OnEvent(const irr::SEvent &event) override;
			virtual bool run();
			virtual void draw();

		protected:
		private:
	};
}
