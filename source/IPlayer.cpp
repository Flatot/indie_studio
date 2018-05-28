/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** IPlayer.cpp
*/

#include "IPlayer.hpp"

bbm::IPlayer::IPlayer(Match &match, float x, float y, bool isTraversable) :
	IEntity(match, x, y, isTraversable)
{
	std::cout << "IPlayer constructed" << std::endl;
}

void	bbm::IPlayer::moveLeft()
{

}

void	bbm::IPlayer::moveRight()
{

}

void	bbm::IPlayer::moveTop()
{

}

void	bbm::IPlayer::moveBottom()
{

}

void	bbm::IPlayer::putBomb()
{

}