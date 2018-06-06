/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** IBonus.cpp
*/

#include "IBonus.hpp"
#include "Match.hpp"

bbm::IBonus::IBonus(Match &match, float z, float x, bool isTraversable) :
	IEntity(match, x, z, isTraversable)
{
	std::cout << "IBonus created" << std::endl;
}