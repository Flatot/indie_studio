//
// EPITECH PROJECT, 2018
// Player.hpp
// File description:
// Player class
//

#pragma once

#include "IEventReceiver.h"

#include "IPlayer.hpp"
#include "Match.hpp"

namespace bbm {
	class Player : public IPlayer, irr::IEventReceiver {
	public: 
		Player(Match &match, float x, float y, bool isTraversable);
		virtual void spawn() override;
		virtual void die() override;
		virtual void update() override;
		virtual bool OnEvent(const irr::SEvent &event) override;

	private:
	};
}
