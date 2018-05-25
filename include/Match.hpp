//
// EPITECH PROJECT, 2018
// Match.hpp
// File description:
// Match class
//

#pragma once

#include <vector>

#include "IEventReceiver.hpp"
#include "ISceneNode.hpp"

#include "Game.hpp"
#include "IEntity.hpp"
#include "IBonus.hpp"
#include "IBomb.hpp"
#include "IPlayer.hpp"

namespace bbm {
	class Match : public irr::IEventReceiver, irr::scene::ISceneNode {
	public:
		Match(Game &game);
		void init();
		virtual bool OnEvent(irr::SEvent &event) override;	
		virtual void draw();
		bool run();
		void update();

	private:
		Game &game;
		Graphic &graphic;
		Map map;
		bool isActive;
		std::vector<IEntity *> blocks;
		std::vector<IBonus *> bonus;
		std::vector<IBomb *> bombs;
		std::vector<IPlayer *> players;
	};
}
