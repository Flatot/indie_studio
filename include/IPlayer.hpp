//
// EPITECH PROJECT, 2018
// IPlayer.hpp
// File description:
// IPlayer.hpp
//

#pragma once

#include <chrono>
#include "IMyEventReceiver.hpp"
#include "IEntity.hpp"

namespace bbm {
	class Match;

	enum Move {
		LEFT = 1,
		RIGHT = 2,
		TOP = 4,
		BOTTOM = 8
	};

	class IPlayer : public IEntity {
	public:
		IPlayer(Match &match, float x, float z, Entities playerNum);
		virtual void spawn() = 0;
		virtual void die() = 0;
		virtual void update() = 0;
		void move();
		void moveLeft();
		void moveRight();
		void moveTop();
		void moveBottom();
		void putBomb();

	protected:
		int _move;
		std::chrono::steady_clock::time_point _timePoint;
		unsigned int power;
		unsigned int nbBombMax;
		unsigned int nbBombUsed;
	};
}
