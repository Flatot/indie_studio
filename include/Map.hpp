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
		Map();
		Map(std::vector<std::vector<int> > map);
		void display();
	private:
		int _length;
		int _width;
		std::vector<std::vector<int> > _map;
	};
}
