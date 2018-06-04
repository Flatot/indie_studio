//
// EPITECH PROJECT, 2018
// Map.hpp
// File description:
// Map class
//

#pragma once

#include <vector>
#include "IEntity.hpp"

namespace bbm {
	class Map {
	public:
		Map(Match &match);
		void loadMap(std::vector<std::vector<int>> map);
		void display();
		int getHeight();
		int getWidth();
		std::vector<IEntity *> &getFromPos(int y, int x);
		int getEntitiesFromPos(int y, int x);

	private:
		Match &_match;
		int _height;
		int _width;
		std::vector<std::vector<std::vector<IEntity *>> > _map;
	};
}
