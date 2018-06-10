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
#include "Match.hpp"

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
		int getPower() const;
	private:
		bool explodeBomb(int entities,
			std::vector<bbm::IEntity *> idEntities,
			std::pair<int, int> p);
		bool explodeLine(int z, int x);
		void particlesImplementation(int x, int z);

		IPlayer *_owner;
		int _power;
		std::chrono::steady_clock::time_point _timePoint;
		Map &_map;
		bool _exploded;
		std::vector<Explosion *> _explosions;
		irr::scene::IParticleSystemSceneNode* _p;
	};
}
