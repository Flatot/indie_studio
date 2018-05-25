//
// EPITECH PROJECT, 2018
// Map.hpp
// File description:
// Map class
//

#pragma once

#include <vector>

namespace bbm {
	class Map {
	public:
		Map(int length, int width, std::vector<std::vector<int>> map);
	private:
		int length;
		int width;
		std::vector<std::vector<int>> map;
	};
}
