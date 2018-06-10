//
// EPITECH PROJECT, 2018
// WallPass.hpp
// File description:
// WallPass class
//

#pragma once

#include "IBonus.hpp"
#include "Match.hpp"

namespace bbm {
	class WallPass : public IBonus {
	public:
		WallPass(Match &match, float z, float x, bool isTraversable);
		virtual void spawn() override;
		virtual void die() override;
		virtual void update() override;

	private:
	};
}
