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
		IPlayer(Match &match, float z, float x, Entities playerNum);
		virtual ~IPlayer();
		virtual void spawn() = 0;
		virtual void die() override;
		virtual void update() = 0;
		virtual void analyseMap();
		void move();
		void putBomb();

		int getPower();
		void incBombCount();
		void decBombCount();
	private:
		void getTexture();
		bool checkCollision(int new_z, int new_x);
		std::string _texture;
	protected:
        void getBonus();
		void moveLeft();
		void moveRight();
		void moveTop();
		void moveBottom();
		int _move;
		std::chrono::steady_clock::time_point _timePoint;
		int _speed;
		int _power;
		int _bombCount;
		bool _passWall;
	};
}
