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

namespace bbm {
	class Player : public IPlayer, IMyEventReceiver {
	public: 
		Player(Match &match, float x, float z, Entities playerNum);
		virtual void spawn() override;
		virtual void die() override;
		virtual void update() override;
		virtual bool OnEvent(const irr::SEvent &event) override;

	private:
	};
}
