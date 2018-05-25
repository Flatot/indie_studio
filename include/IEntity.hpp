//
// EPITECH PROJECT, 2018
// IEntity.hpp
// File description:
// IEntity interface
//

#pragma once

#include "Match.hpp"

namespace bbm {
	class IEntity {
	public:
		IEntity(Match &match, float x, float y);
		virtual void spawn() = 0;
		virtual void die() = 0;
		virtual void update() = 0;

	protected:
		Match &match;
		bool isTraversable;
		float x;
		float y;
	};
}
