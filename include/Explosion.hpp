//
// EPITECH PROJECT, 2018
// Explosion.hpp
// File description:
// Explosion class
//

#pragma once

#include <chrono>
#include "IEntity.hpp"
#include "Graphic.hpp"

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
		void particlesImplementation(int x, int z);
	private:
		Bomb *_owner;
		std::chrono::steady_clock::time_point _timePoint;
		irr::scene::IParticleSystemSceneNode* _p;
	};
}
