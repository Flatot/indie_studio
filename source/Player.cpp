/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Player.cpp
*/

#include "Player.hpp"

bbm::Player::Player(Match &match, float z, float x, Entities playerNum) :
	bbm::IPlayer(match, x, z, playerNum)
{
	std::cout << "Player constructed" << std::endl;
	activate();
}

void bbm::Player::spawn()
{

}

void bbm::Player::die()
{

}

void bbm::Player::update()
{
	_mesh->setPosition(irr::core::vector3df(_x, 0.f, _z * 2));
}

bool bbm::Player::OnEvent(const irr::SEvent &event)
{
	IMyEventReceiver::OnEvent(event);

	std::cout << "[OnEvent - Player]" << std::endl;
	_move = (isKeyPressed(irr::KEY_KEY_A, NONE)) ? 
		_move | LEFT : _move & ~LEFT;
	_move = (isKeyPressed(irr::KEY_KEY_W, NONE)) ? 
		_move | TOP : _move & ~TOP;
	_move = (isKeyPressed(irr::KEY_KEY_D, NONE)) ? 
		_move | RIGHT : _move & ~RIGHT;
	_move = (isKeyPressed(irr::KEY_KEY_S, NONE)) ? 
		_move | BOTTOM : _move & ~BOTTOM;
	if (isKeyPressed(irr::KEY_KEY_L, NONE))
		++_speed;
	return false;
}
