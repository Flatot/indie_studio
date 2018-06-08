//
// EPITECH PROJECT, 2018
// Explosion.hpp
// File description:
// Explosion class
//

#pragma once

#include <chrono>
#include "IEntity.hpp"

namespace bbm {
	class Bomb;

	class Explosion : public IEntity {
	public:
		Explosion(Match &match, float z, float x, Bomb *owner);
		~Explosion();
		void spawn() override;
		void die() override;
		void update() override;
		void random_bonus(int);
	private:
		Bomb *_owner;
		std::chrono::steady_clock::time_point _timePoint;
	};
}
