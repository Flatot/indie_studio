//
// EPITECH PROJECT, 2018
// indie
// File description:
// main menu header
//

#pragma once

#include "Game.hpp"
#include "IMenu.hpp"

namespace bbm {
	class MenuMain : public IMenu {
		public:
			MenuMain(Game &game);
			~MenuMain();
			virtual bool OnEvent(const irr::SEvent &event) override;
			virtual bool run();
			virtual void draw();
			void	quitGame(void);

		protected:
		private:
	};
}