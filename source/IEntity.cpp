/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** IEntity.cpp
*/

#include "IEntity.hpp"

bbm::IEntity::IEntity(Match &match, float x, float y, bool isTraversable) :
	_match(match),
	_x(x),
	_y(y),
	_isTraversable(isTraversable)
{
	std::cout << "IEntity constructed" << std::endl;
}