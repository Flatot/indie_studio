//
// EPITECH PROJECT, 2018
// UnbreakableBlock.hpp
// File description:
// Unbreakable block class
//

#pragma once

#include "IBlock.hpp"

namespace bbm {
	class Match;

	class UnbreakableBlock : public IBlock {
	public:
		UnbreakableBlock(Match &match, float z, float x);
		virtual void spawn() override;
		virtual void die() override;
		virtual void update() override;

	private:
	};
}
