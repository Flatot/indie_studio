/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Map.cpp
*/

#include <iostream>
#include "Map.hpp"
#include "UnbreakableBlock.hpp"

bbm::Map::Map(Match &match) :
	_match(match),
	_height(0),
	_width(0),
	_map()
{
	std::cout << "Map constructed" << std::endl;
}

void bbm::Map::loadMap(std::vector<std::vector<int>> map)
{
	_height = map.size();
	if (!_height)
		return;
	_width = map[0].size();
	for (int i = 0; i < _height; ++i) {
		_map.push_back(std::vector<std::vector<IEntity *>>());
		for (int j = 0; j < _width; ++j) {
			_map[i].push_back(std::vector<IEntity *>());
			if (map[i][j] & UNBREAKABLE_BLOCK)
				_map[i][j].push_back(new UnbreakableBlock(_match, 
							i, j));
//			if (map[i][j] & BREAKABLE_BLOCK)
//				_map[i][j].push_back();
		}
	}
}

void bbm::Map::display() {
/*	for (int j = 0; j < _map.size(); j++) {
		for (int i = 0; i < _map[0].size(); i++)
			std::cout << _map[j][i];
		std::cout << std::endl;
	}*/
}

int bbm::Map::getHeight()
{
	return _height;
}

int bbm::Map::getWidth()
{
	return _width;
}

std::vector<bbm::IEntity *> &bbm::Map::getFromPos(int y, int x)
{
	return _map[y][x];
}

int bbm::Map::getEntitiesFromPos(int y, int x)
{
	int values = 0;
	
	for (int i = 0; i < _map[y][x].size(); ++i)
		values += _map[y][x][i]->getIdEntity();
	return values;
}
