//
// EPITECH PROJECT, 2018
// IBlock.hpp
// File description:
// IBlock interface
//

#pragma once

#include "IBlock.hpp"

namespace bbm {
	class IBlock : public IEntity {
	public:
		IBlock(Match &match, float x, float y);
		virtual void spawn() = 0;
		virtual void die() = 0;
		virtual void update() = 0;

	private:

	};
}
