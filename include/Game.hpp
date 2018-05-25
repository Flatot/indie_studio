//
// EPITECH PROJECT, 2018
// Game.hpp
// File description:
// Game class
//

#pragma once

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
		IMenu *mainMenu;
		IMenu *inGameMenu;
		Match match;
	
		Graphic graphic;
	
		PlayerConfig playersConfig[4];
	};
}
