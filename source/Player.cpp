/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Player.cpp
*/

#include "Player.hpp"

bbm::Player::Player(Match &match, float x, float y, bool isTraversable) :
	bbm::IPlayer(match, x, y, isTraversable), irr::IEventReceiver()
{
	std::cout << "Player constructed" << std::endl;
}

void bbm::Player::spawn()
{

}

void bbm::Player::die()
{

}

void bbm::Player::update()
{

}

bool bbm::Player::OnEvent(const irr::SEvent &event)
{
	return false;
}
