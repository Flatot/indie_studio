//
// EPITECH PROJECT, 2018
// BombUp.hpp
// File description:
// BombUp class
//

#pragma once

#include "IBonus.hpp"
#include "Match.hpp"

namespace bbm {
	class BombUp : public IBonus {
	public: 
		BombUp(Match &match, float z, float x, bool isTraversable);
		virtual void spawn() override;
		virtual void die() override;
		virtual void update() override;

	private:
	};
}
