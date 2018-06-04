/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** IPlayer.cpp
*/

#include "IPlayer.hpp"
#include "Match.hpp"

bbm::IPlayer::IPlayer(Match &match, float x, float z, Entities playerNum) :
	IEntity(match, x, z, true)
{
	_idEntity = playerNum;
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
