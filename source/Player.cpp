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
	auto scene = _match.getGraphic().getScene();
	auto mesh = scene->getMesh("./assets/model3D/player/ninja.b3d");
	auto animatedMesh = static_cast<
		irr::scene::IAnimatedMeshSceneNode *>(_mesh);
	activate();
}

bbm::Player::~Player()
{
	std::cout << "PLAYER DESTRUCTOR" << std::endl;
}

void bbm::Player::spawn()
{

}

void bbm::Player::die()
{
	deactivate();
	_match.getEventManager()->removeEventReceiver(this);
	IPlayer::die();
}

void bbm::Player::update()
{
	float z = _z - 0.5;
	float x = _x - 0.5;

	_mesh->setPosition(irr::core::vector3df(x, 0.5f, z));
}

bool bbm::Player::checkCollision(int new_z, int new_x)
{
	int entities = _match.getMap().getEntitiesFromPos(new_z, new_x);

	if (entities & UNBREAKABLE_BLOCK)
		return false;
	if ((entities & BREAKABLE_BLOCK) || (entities & BOMB))
		return _passWall;
	return true;
}


bool bbm::Player::OnEvent(const irr::SEvent &event)
{
	IMyEventReceiver::OnEvent(event);

	std::cout << "[OnEvent - Player]" << std::endl;
	_move = (isKeyPressed(irr::KEY_KEY_Q, NONE)) ? 
		_move | LEFT : _move & ~LEFT;
	_move = (isKeyPressed(irr::KEY_KEY_Z, NONE)) ? 
		_move | TOP : _move & ~TOP;
	_move = (isKeyPressed(irr::KEY_KEY_D, NONE)) ? 
		_move | RIGHT : _move & ~RIGHT;
	_move = (isKeyPressed(irr::KEY_KEY_S, NONE)) ? 
		_move | BOTTOM : _move & ~BOTTOM;
	if (isKeyPressed(irr::KEY_KEY_L, NONE))
		++_speed;
	if (isKeyPressed(irr::KEY_KEY_B, NONE))
		putBomb();
	return false;
}
