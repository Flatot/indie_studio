/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** IBlock.cpp
*/

#include "IBlock.hpp"

bbm::IBlock::IBlock(Match &match, float x, float y, bool isTraversable) :
	IEntity(match, x, y, isTraversable)
{
	std::cout << "IBlock constructed" << std::endl;
}