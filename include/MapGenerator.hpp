//
// EPITECH PROJECT, 2018
// map gen
// File description:
// map generator
//

#pragma once

#include <iostream>
#include <vector>
#include "Map.hpp"

namespace bbm {
	class MapGenerator {
	public:
		static Map generate(std::string path);
	private:
		static void getMapFromFile(std::string path);
		static void createBreakable();
		static int translate(char c);
		static std::vector<int> getVectorUnbreakableBlock(
				unsigned long size);
		static void myStarts();
		static void cleanStart(int y, int x);
		static void lastChange(int y, int x);
		static bool checkLeft(int y, int x);
		static bool checkRight(int y, int x);
		static bool checkDown(int y, int x);
		static bool checkUp(int y, int x);
		static bool checkAll(int y, int x, int dir);
		static bool checkAllBreak(int y, int x, int dir);
		static int twoGood(int y, int x);
		static void changeAllBlank(int y, int x, int dir);


		static std::vector<std::vector<int>> _map; 
	};
}
