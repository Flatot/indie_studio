//
// EPITECH PROJECT, 2018
// Match.hpp
// File description:
// Match class
//

#pragma once

#include <vector>

#include "IEventReceiver.h"
<<<<<<< HEAD
=======
#include "ISceneNode.h"
>>>>>>> source and include

#include "IEntity.hpp"
#include "IPlayer.hpp"
#include "Map.hpp"
// #include "IBonus.hpp"
// #include "IBomb.hpp"

namespace bbm {
	class Game;

<<<<<<< HEAD
	class Match : public irr::IEventReceiver {
	public:
		Match(Game &game);
		void init();
		virtual bool OnEvent(const irr::SEvent &event);
=======
	class Match : public irr::IEventReceiver, irr::scene::ISceneNode {
	public:
		Match(Game &game);
		void init();
		bool OnEvent(irr::SEvent &event);
>>>>>>> source and include
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
