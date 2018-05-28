//
// EPITECH PROJECT, 2018
// Game.hpp
// File description:
// Game class
//

#pragma once

#include <iostream>

#include "IMenu.hpp"
#include "Match.hpp"
// #include "Graphic.hpp"
// #include "PlayerConfig.hpp"

namespace bbm {
	class Game {
	public:
		Game();
		bool run();
		bool launchMatch();
	
		bool launchInGameMenu();
		bool launchMainMenu();
	
		// Save le match
		void save();
		// Save les playerConfig
		void saveConfig();
	private:
		IMenu *_mainMenu;
		IMenu *_inGameMenu;
		Match _match;
	
		// Graphic _graphic;
	
		// PlayerConfig _playersConfig[4];
	};
}
