//
// EPITECH PROJECT, 2018
// indie
// File description:
// settings menu
//

#pragma once

#include "Game.hpp"
#include "IMenu.hpp"

namespace bbm {
	class MenuSettings : public IMenu {
		public:
			MenuSettings(Game &game);
			~MenuSettings();
			virtual bool OnEvent(const irr::SEvent &event) override;
			virtual bool run();
			virtual void draw();

		protected:
		private:
	};
}
