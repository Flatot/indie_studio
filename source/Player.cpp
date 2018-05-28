/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Player.cpp
*/

#include "Player.hpp"

bbm::Player::Player(Match &match, float x, float y, bool isTraversable) :
	bbm::IPlayer(match, x, y, isTraversable)
{
	std::cout << "Player constructed" << std::endl;
}