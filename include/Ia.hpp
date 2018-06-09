//
// EPITECH PROJECT, 2018
// Ia.hpp
// File description:
// ia class
//

#pragma once

#include <vector>
#include "IEntity.hpp"
#include "IPlayer.hpp"
#include "Match.hpp"

namespace bbm {
	class Ia : public IPlayer {
	public:
		Ia(Match &match, float z, float x, Entities playerNum);
		~Ia();
		virtual void spawn() override;
		virtual void die() override;
		virtual void update() override;
		virtual void analyseMap() override;
	protected:
		void fill_dangerosity_bis(int bombLen, int y, int x);
		void fill_dangerosity(int bombLen, int y, int x);
		void scaleBomb();
		void move_to_rec();
		void move_to_center();
		// void active_mode();
		void defensive_mode();
		// void affDmap();
		void moveAllDefensive(int dir);
		void pathFindingDefensive();
		bool checkAllDefensive(int dir);
		bool seeAllMoveDefensive(int dir);
		// bool checkAllBreakable(int dir, int y, int x);
		// bool aliveIfBomb();
		// void changeDMapToBMap();
		std::vector<std::vector<int>> generateDMap();
	private:
		// std::vector<std::vector<int> > _direction;
		std::vector<std::vector<int>> d_map;
		// std::vector<std::vector<int>> a_map;
		// std::vector<std::vector<int>> f_map;
		std::vector<int> rec;
		int ym;
		int xm;
		int f;
		int objectif;
		int ite;
	};
}
