//
// EPITECH PROJECT, 2018
// FireUp.hpp
// File description:
// FireUp class
//

#pragma once

#include "IBonus.hpp"
#include "Match.hpp"

namespace bbm {
	class FireUp : public IBonus {
	public:
		FireUp(Match &match, float z, float x, bool isTraversable);
		virtual void spawn() override;
		virtual void die() override;
		virtual void update() override;

	private:
	};
}
