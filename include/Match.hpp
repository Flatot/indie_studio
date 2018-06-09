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
		void addBomb(Bomb *bomb);
		void removeBomb(Bomb *bomb);
		void addPlayer(IPlayer *player);
		void removePlayer(IPlayer *player);

	private:
		Game &_game;
		Graphic &_graphic;
		EventManager *_evManager;
		Floor _floor;
		Map _map;
		std::vector<Bomb *> _bombs;
		std::vector<IPlayer *> _players;
		
		irr::scene::ICameraSceneNode *_camera;
	};
}
