//
// EPITECH PROJECT, 2018
// Player.hpp
// File description:
// Player class
//

#pragma once

#include "IMyEventReceiver.hpp"

#include "IEntity.hpp"
#include "IPlayer.hpp"
#include "Match.hpp"
#include "PlayerConfig.hpp"

namespace bbm {
	class Player : public IPlayer, public IMyEventReceiver {
	public:
		Player(Match &match, float z, float x, Entities playerNum,
				TeamColor team);
		~Player();
		virtual void spawn() override;
		virtual void die() override;
		virtual void update() override;
		virtual bool OnEvent(const irr::SEvent &event) override;
	private:
		PlayerConfig &getPlayerConfig();
		bool checkCollision(int, int);

		PlayerConfig &_playerConfig;
	};
}
