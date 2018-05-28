//
// EPITECH PROJECT, 2018
// Match.hpp
// File description:
// Match class
//

#pragma once

#include <vector>

#include "IEventReceiver.h"
#include "ISceneNode.h"

#include "IEntity.hpp"
#include "IPlayer.hpp"
#include "Map.hpp"
// #include "IBonus.hpp"
// #include "IBomb.hpp"

namespace bbm {
	class Game;

	class Match : public irr::IEventReceiver, irr::scene::ISceneNode {
	public:
		Match(Game &game);
		void init();
		bool OnEvent(irr::SEvent &event);
		virtual void draw();
		virtual bool run();
		void update();

	private:
		Game &_game;
		// Graphic &_graphic;
		Map _map;
		bool _isActive;
		std::vector<IEntity *> _blocks;
		// std::vector<IBonus *> _bonus;
		// std::vector<IBomb *> _bombs;
		std::vector<IPlayer *> _players;
	};
}
