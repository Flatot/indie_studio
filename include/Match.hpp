//
// EPITECH PROJECT, 2018
// Match.hpp
// File description:
// Match class
//

#pragma once

#include <vector>

#include "ICameraSceneNode.h"

#include "IMyEventReceiver.hpp"
#include "EventManager.hpp"

#include "Graphic.hpp"
#include "IEntity.hpp"
#include "IPlayer.hpp"
#include "Map.hpp"
#include "Floor.hpp"
#include "UnbreakableBlock.hpp"
#include "IBonus.hpp"
#include "Bomb.hpp"
#include "Definer.hpp"

namespace bbm {
	class Game;

	class Match : public IMyEventReceiver {
	public:
		Match(Game &game);
		void init(std::vector<bbm::AttrEntity> attrs,
			std::vector<bbm::TeamColor> teams);
		virtual bool OnEvent(const irr::SEvent &event);
		virtual void draw();
		virtual bool run();
		void update();
		void print_skybase();
		EventManager *getEventManager();
		Game &getGame();
		Graphic &getGraphic();
		Map &getMap();
		bool hasSave();
		void save();
		void load();
		void addBomb(Bomb *bomb);
		void removeBomb(Bomb *bomb);
		void addPlayer(IPlayer *player);
		void removePlayer(IPlayer *player);
		void drawStarter();
		std::vector<irr::video::ITexture *>	createCounter();
		irr::video::ITexture	*getCurrentCounter(
			std::vector<irr::video::ITexture *> list, float count);
		void drawImageBack(const irr::core::dimension2du& screenSize,
			irr::video::ITexture *img);
		TeamColor getWinner();
		void drawWinner();
		irr::video::ITexture *getWinnerColor(TeamColor color);
		void drawWinnerRec(const irr::core::dimension2du& screenSize,
			irr::video::ITexture *img);
		bool isFinished();

	private:
		void handleLine(std::string line, int i, IPlayer **player);
		bool isValuable(std::string str);
		void doWithTokens(std::string tok1, std::string tok2, bbm::IPlayer **player);
		IPlayer *loadIPlayer(int nbPlayer);
		IPlayer *createPlayer(std::string line);
		bbm::TeamColor strToTeamColor(std::string str);
		Game &_game;
		Graphic &_graphic;
		EventManager *_evManager;
		Floor _floor;
		Map _map;
		std::vector<Bomb *> _bombs;
		std::vector<IPlayer *> _players;
		irr::scene::ICameraSceneNode *_camera;
		bool _menuReturn;
		bool _counting;
	};
}

static std::string valuable[4] = {
	"0",
	"1",
	"2",
	"3"
};

static bbm::Entities entities[4] = {
	bbm::PLAYER_1,
	bbm::PLAYER_2,
	bbm::PLAYER_3,
	bbm::PLAYER_4
};
