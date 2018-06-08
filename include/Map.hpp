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
		~Map();
		void loadMap(std::vector<std::vector<int>> map);
		void save();
		void load();
		int getHeight() const;
		int getWidth() const;
		std::vector<IEntity *> &getFromPos(int y, int x);
		int getEntitiesFromPos(int y, int x) const;
		IEntity *getEntity(int y, int x, Entities entity);
		void clear();
		void addEntity(IEntity *entity);
		std::pair<std::vector<IEntity *>::iterator, 
			std::vector<IEntity *>::iterator> 
				getItEntity(IEntity *entity);
		void removeEntity(IEntity *entity);
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
