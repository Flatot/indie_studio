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
#include "Definer.hpp"

namespace bbm {
	class Match;

	enum Move {
		LEFT = 1,
		RIGHT = 2,
		TOP = 4,
		BOTTOM = 8
	};

	enum PlayerType {
		AI,
		PLAYER
	};

	class IPlayer : public IEntity {
	public:
		IPlayer(Match &match, float z, float x, Entities playerNum, 
				TeamColor team);
		virtual ~IPlayer();
		virtual void spawn() = 0;
		virtual void die() override;
		virtual void update() = 0;
		virtual void analyseMap();
		void move();
		void putBomb();

		PlayerType getType() const;
		int getPower();
		void setPower(int power);
		void incPower();
		void decPower();
		int getBombCount() const;
		void setBombCount(int bombCount);
		void incBombCount();
		void decBombCount();
		int getSpeed() const;
		void setSpeed(int speed);
		void incSpeed();
		void decSpeed();
		bool getWallPass() const;
		void setWallPass(bool wallPass);
		std::string typeToStr();
		std::string entitiesToInt();
		TeamColor getTeam();
		std::string teamToStr();

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
		void setFrameMyLoop(int begin, int end);

		PlayerType _type;
		int _move;
		std::chrono::steady_clock::time_point _timePoint;
		int _speed;
		int _power;
		int _bombCount;
		bool _passWall;
		TeamColor _team;

	};
}
std::ostream& operator<< (std::ostream& stream, bbm::IPlayer *player);
