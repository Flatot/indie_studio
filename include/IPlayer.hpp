//
// EPITECH PROJECT, 2018
// IPlayer.hpp
// File description:
// IPlayer.hpp
//

#pragma once

#include "IEntity.hpp"

namespace bbm {
	class Match;

	class IPlayer : public IEntity {
	public:
		IPlayer(Match &match, float x, float y, bool isTraversable);
		virtual void spawn() = 0;
		virtual void die() = 0;
		virtual void update() = 0;
		void moveLeft();
		void moveRight();
		void moveTop();
		void moveBottom();
		void putBomb();

	private:
		unsigned int power;
		unsigned int nbBombMax;
		unsigned int nbBombUsed;
	};
}
