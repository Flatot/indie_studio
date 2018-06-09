//
// EPITECH PROJECT, 2018
// Game.hpp
// File description:
// Game class
//

#pragma once

#include <iostream>

#include "IMyEventReceiver.hpp"
#include "EventManager.hpp"

#include "Config.hpp"
#include "Graphic.hpp"
#include "IMenu.hpp"
#include "Match.hpp"
#include "MenuMain.hpp"
#include "MenuInGame.hpp"
#include "MenuSettings.hpp"
// #include "PlayerConfig.hpp"

namespace bbm {
	class Game : public IMyEventReceiver {
	public:
		Game(Config &config);

		Graphic &getGraphic();
		Config &getConfig();
		Config &getConfig() const;

		virtual bool OnEvent(const irr::SEvent &event) override;
		bool run();
		bool launchMatch(std::vector<bbm::AttrEntity> attrs,
			std::vector<bbm::TeamColor> teams);
	
		bool launchInGameMenu();
		bool launchMainMenu();
		IMenu *getMenuInGame() const;
	
		// Save le match
		void save();
		// Save les playerConfig
		void saveConfig();

	private:
		Config &_config;	
		EventManager *_evManager;
		Graphic _graphic;
		IMenu *_mainMenu;
		IMenu *_inGameMenu;
		Match _match;
		bool _matchLaunched;
	};
}
