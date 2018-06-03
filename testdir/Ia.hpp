//
// EPITECH PROJECT, 2018
// Ia.hpp
// File description:
// ia class
//

#pragma once

#include <fstream>
#include "mapgen.hpp"

namespace bbm {
	class Ia : public PlayerCurse {
	public:
		Ia(int y, int x);
		~Ia();
		void	analyseMap(std::vector<std::vector<int>>);
		std::vector<int> rec;
		int ym;
		int xm;
		int f;
		int objectif;
		int ite;
		bool seeAllMove(int dir);
		bool seeAllMoveDefensive(int dir);
	protected:
		void fill_dangerosity(int bombLen, int y, int x);
		void scaleBomb();
		void active_mode();
		void defensive_mode();
		void affDmap();
		void pathFindingDefensive();
		bool checkAllDefensive(int dir);
		bool checkAllBreakable(int dir, int y, int x);
		bool aliveIfBomb();
		void changeDMapToBMap();
		void generateDMap();
	private:
		std::vector<std::vector<int>>	d_map;
		std::vector<std::vector<int>> a_map;
		std::vector<std::vector<int>> f_map;
		std::vector<std::vector<int>>	map;
		std::vector<int> moveAllDefensive(int dir);
	};
}
