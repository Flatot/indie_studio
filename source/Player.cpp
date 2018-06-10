/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Player.cpp
*/

#include "Player.hpp"
#include "Game.hpp"

bbm::Player::Player(Match &match, float z, float x, Entities playerNum, 
		TeamColor team) :
	bbm::IPlayer(match, x, z, playerNum, team),
	_playerConfig(getPlayerConfig())
{
	_type = PlayerType::PLAYER;
	_passWall = true;
	_power = 5;
	_match.getEventManager()->addEventReceiver(this);
	activate();
}

bbm::PlayerConfig &bbm::Player::getPlayerConfig()
{
	switch (_idEntity) {
	case PLAYER_2:
		return _match.getGame().getConfig().getPlayerConfig(1);
	case PLAYER_3:
		return _match.getGame().getConfig().getPlayerConfig(2);
	case PLAYER_4:
		return _match.getGame().getConfig().getPlayerConfig(3);
	default:
		return _match.getGame().getConfig().getPlayerConfig(0);
	}
	std::cout << _playerConfig << std::endl;
	auto keyMap = _playerConfig.getMap();
	for (int i = 0; i < 5; ++i)
		std::cout << valuableControl[i] << keyMap[valuableControl[i]] << std::endl;
}

bbm::Player::~Player()
{
	_match.getEventManager()->removeEventReceiver(this);
}

void bbm::Player::spawn()
{

}

void bbm::Player::die()
{
	deactivate();
	IPlayer::die();
}

void bbm::Player::update()
{
	move();
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
	bool ret = IMyEventReceiver::OnEvent(event);
	auto keyMap = _playerConfig.getMap();

	std::cout << "[OnEvent - Player][" << _idEntity << "]" << std::endl;
	_move = (isKeyPressed(keyMap["LEFT"], NONE)) ? 
		_move | LEFT : _move & ~LEFT;
	_move = (isKeyPressed(keyMap["UP"], NONE)) ? 
		_move | TOP : _move & ~TOP;
	_move = (isKeyPressed(keyMap["RIGHT"], NONE)) ? 
		_move | RIGHT : _move & ~RIGHT;
	_move = (isKeyPressed(keyMap["DOWN"], NONE)) ? 
		_move | BOTTOM : _move & ~BOTTOM;
	if (isKeyPressed(keyMap["PUT_BOMB"], NONE))
		putBomb();
	return ret;
}
