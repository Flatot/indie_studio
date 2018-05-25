//
// EPITECH PROJECT, 2018
// MainMenu.hpp
// File description:
// MainMenu class
//

#pragma once

#include "IMenu.hpp"

namespace bbm {
	class MainMenu : public IMenu {
	public:
		MainMenu(Game &game);
		virtual bool OnEvent(irr::SEvent &event) override;
		virtual bool run() override;
		virtual void draw();
	private:

	};
}
