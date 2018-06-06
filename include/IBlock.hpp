//
// EPITECH PROJECT, 2018
// IBlock.hpp
// File description:
// IBlock interface
//

#pragma once

#include "IEntity.hpp"

namespace bbm {
	class IBlock : public IEntity {
	public:
		IBlock(Match &match, float z, float x, bool isTraversable);
		virtual void spawn() = 0;
		virtual void die() = 0;
		virtual void update() = 0;

	private:

	};
}
