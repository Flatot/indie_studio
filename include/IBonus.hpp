//
// EPITECH PROJECT, 2018
// IBonus.hpp
// File description:
// IBonus interface
//

#pragma once

#include "IEntity.hpp"

namespace bbm {
	class IBonus : public IEntity {
	public:
		IBonus(Match &match, float z, float x, bool isTraversable);
		virtual void spawn() = 0;
		virtual void die() = 0;
		virtual void update() = 0;

	private:
	};
}
