//
// EPITECH PROJECT, 2018
// Map.hpp
// File description:
// Map class
//

#pragma once

#include <vector>
#include "IEntity.hpp"
#include <iostream>
#include <fstream>

namespace bbm {
	class Map {
	public:
		Map(Match &match);
		void loadMap(std::vector<std::vector<int>> map);
		void save();
		void load();
		int getHeight() const;
		int getWidth() const;
		std::vector<IEntity *> &getFromPos(int y, int x);
		int getEntitiesFromPos(int y, int x) const;

	private:
		std::vector<int> getVecFromLine(std::string line, 
				std::string delimiter) const;

		Match &_match;
		int _height;
		int _width;
		std::vector<std::vector<std::vector<IEntity *>>> _map;
	};

}
std::ostream& operator<< (std::ostream& stream, bbm::Map const& map);
