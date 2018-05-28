/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Map.cpp
*/

#include "Map.hpp"

bbm::Map::Map(int length, int width, std::vector<std::vector<int>> map) :
	_length(length),
	_width(width),
	_map(map)
{
	std::cout << "Map constructed" << std::endl;
}