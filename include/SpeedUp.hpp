//
// EPITECH PROJECT, 2018
// SpeedUp.hpp
// File description:
// SpeedUp class
//

#pragma once

#include "IBonus.hpp"
#include "Match.hpp"

namespace bbm {
	class SpeedUp : public IBonus {
	public: 
		SpeedUp(Match &match, float z, float x, bool isTraversable);
		virtual void spawn() override;
		virtual void die() override;
		virtual void update() override;

	private:
	};
}
