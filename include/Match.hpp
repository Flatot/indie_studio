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
// #include "IBonus.hpp"
// #include "IBomb.hpp"

namespace bbm {
	class Game;

	class Match : public IMyEventReceiver {
	public:
		Match(Game &game);
		void init();
		virtual bool OnEvent(const irr::SEvent &event);
		virtual void draw();
		virtual bool run();
		void update();
		EventManager *getEventManager();
		Graphic &getGraphic();
		Map &getMap();

	private:
		Game &_game;
		Graphic &_graphic;
		EventManager *_evManager;
		Floor _floor;
		Map _map;
		std::vector<UnbreakableBlock> _unbreakableBlocks;
		// std::vector<IBonus *> _bonus;
		// std::vector<IBomb *> _bombs;
		std::vector<IPlayer *> _players;
		
		irr::scene::ICameraSceneNode *_camera;
	};
}
