/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Map.cpp
*/

#include <iostream>
#include "Map.hpp"

bbm::Map::Map() :
	_length(0),
	_width(0),
	_map()
{
	std::cout << "Map constructed" << std::endl;
}

bbm::Map::Map(std::vector<std::vector<int>> map) :
	_length(map.size()),
	_width(map[0].size()),
	_map(map)
{
	std::cout << "Map constructed" << std::endl;
}

void bbm::Map::display() {
	for (int j = 0; j < _map.size(); j++) {
		for (int i = 0; i < _map[0].size(); i++)
			std::cout << _map[j][i];
		std::cout << std::endl;
	}
}
