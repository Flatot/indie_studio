//
// EPITECH PROJECT, 2018
// BreakableBlock.hpp
// File description:
// Breakable Block class
//

#pragma once

#include "IBlock.hpp"

namespace bbm {
	class Match;

	class BreakableBlock : public IBlock {
	public:
		BreakableBlock(Match &match, float z, float x);
		~BreakableBlock();
		virtual void spawn() override;
		virtual void die() override;
		virtual void update() override;
	private:
	};
}
