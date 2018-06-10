//
// EPITECH PROJECT, 2018
// Game.hpp
// File description:
// Game class
//

#pragma once

#include <iostream>

#include "EventManager.hpp"

#include "Config.hpp"
#include "Graphic.hpp"
#include "IMenu.hpp"
#include "Match.hpp"
#include "MenuMain.hpp"
#include "MenuInGame.hpp"
#include "MenuSettings.hpp"
#include "Audio.hpp"

namespace bbm {
	class Game {
	public:
		Game(Config &config);

		Graphic &getGraphic();
		Config &getConfig();
		Config &getConfig() const;
		Match &getMatch();
		Audio &getAudio();

		bool run();
		bool launchMatch(std::vector<bbm::AttrEntity> attrs,
			std::vector<bbm::TeamColor> teams);

		bool launchInGameMenu();
		bool launchMainMenu();
		IMenu *getMenuInGame() const;
		bool hasSave();

		void save();
		void saveConfig();

	private:
		Config &_config;
		EventManager *_evManager;
		Graphic _graphic;
		IMenu *_mainMenu;
		IMenu *_inGameMenu;
		Match _match;
		bool _matchLaunched;
		Audio _audio;
	};
}
