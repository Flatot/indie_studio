//
// EPITECH PROJECT, 2018
// Bomb.hpp
// File description:
// Bomb class
//

#pragma once

#include "IEntity.hpp"
#include "IPlayer.hpp"
#include "Map.hpp"
#include "Explosion.hpp"

namespace bbm {
	class Bomb : public IEntity {
	public:
		Bomb(Match &match, float z, float x, IPlayer *player);
		~Bomb();
		virtual void spawn() override;
		virtual void die() override;
		virtual void update() override;
		void explode();
		void addExplosion(Explosion *explo);
		void removeExplosion(Explosion *explo);

	private:
		bool explodeLine(int z, int x);
		
		IPlayer *_owner;
		int _power;
		std::chrono::steady_clock::time_point _timePoint;
		Map &_map;
		bool _exploded;
		std::vector<Explosion *> _explosions;
	};
}
