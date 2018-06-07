/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** IPlayer.cpp
*/

#include "IPlayer.hpp"
#include "Match.hpp"

bbm::IPlayer::IPlayer(Match &match, float z, float x, Entities playerNum) :
	IEntity(match, x, z, true),
	_move(0),
	_timePoint(std::chrono::steady_clock::now()),
	_speed(0),
	_power(1),
	_bombCount(1),
	_passWall(false)
{
	_idEntity = playerNum;
	setCoefs(.33f, .33f, .33f);
	auto position = irr::core::vector3df(_x, 0, _z * 2);
	auto rotation = irr::core::vector3df(0, 0, 0);
	auto scale = irr::core::vector3df(_coefX, _coefY, _coefZ);
	auto scene = _match.getGraphic().getScene();
	auto mesh = scene->getMesh("./assets/model3D/player/ninja.b3d");

	if (!mesh) {
		std::cerr << "IPlayer constructor, "
			"scene->getMesh return nullptr" << std::endl;
		exit(84);
	}
	_mesh = scene->addAnimatedMeshSceneNode(mesh, 0, -1, position,
			rotation, scale);
	_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	auto animatedMesh = static_cast<
		irr::scene::IAnimatedMeshSceneNode *>(_mesh);
	animatedMesh->setFrameLoop(0, 13);
	animatedMesh->setAnimationSpeed(15);
}

bbm::IPlayer::~IPlayer()
{
	std::cout << "IPLAYER DESTRUCTOR" << std::endl;
}

void bbm::IPlayer::die()
{
	_match.getMap().removeEntity(this);
	_match.removePlayer(this);
	delete this;
}

void bbm::IPlayer::move()
{
	auto timePoint = std::chrono::steady_clock::now();
	auto diff = std::chrono::duration_cast<std::chrono::nanoseconds>
		(timePoint - _timePoint);

	if (diff.count() < 10000000)
		return;
	_timePoint = std::chrono::steady_clock::now();
	if (_move & LEFT)
		moveLeft();
	if (_move & RIGHT)
		moveRight();
	if (1) {
		if (_move & TOP)
			moveTop();
		if (_move & BOTTOM)
			moveBottom();
	}
}

void	bbm::IPlayer::moveLeft()
{
	auto &map = _match.getMap();
	float new_x = _x - (0.1f + (0.01f * _speed));

	_mesh->setRotation(irr::core::vector3df(0.f, -90.f, 0.f));
	if (std::floor(_x) != std::floor(new_x)) {
		if (!checkCollision(_z, new_x))
			return;
		map.removeEntity(this);
		_x = new_x;
		map.addEntity(this);
	} else
		_x = new_x;
	std::cout << map << std::endl;
}

void	bbm::IPlayer::moveRight()
{
	auto &map = _match.getMap();
	float new_x = _x + (0.1f + (0.01f * _speed));

	_mesh->setRotation(irr::core::vector3df(0.f, 90.f, 0.f));
	if (std::floor(_x) != std::floor(new_x)) {
		if (!checkCollision(_z, new_x))
			return;
		map.removeEntity(this);
		_x = new_x;
		map.addEntity(this);
	} else
		_x = new_x;
	std::cout << map << std::endl;
}

void	bbm::IPlayer::moveTop()
{
	auto &map = _match.getMap();
	float new_z = _z + (0.1f + (0.01f * _speed));;

	_mesh->setRotation(irr::core::vector3df(0.f, 0.f, 0.f));
	if (std::floor(_z) != std::floor(new_z)) {
		if (!checkCollision(new_z, _x))
			return;
		map.removeEntity(this);
		_z = new_z;
		map.addEntity(this);
	} else
		_z = new_z;
	std::cout << map << std::endl;
}

void	bbm::IPlayer::moveBottom()
{
	auto &map = _match.getMap();
	float new_z = _z - (0.1f + (0.01f * _speed));

	_mesh->setRotation(irr::core::vector3df(0.f, 180.f, 0.f));
	if (std::floor(_z) != std::floor(new_z)) {
		if (!checkCollision(new_z, _x))
			return;
		map.removeEntity(this);
		_z = new_z;
		map.addEntity(this);
	} else
		_z = new_z;
	std::cout << map << std::endl;
}

void	bbm::IPlayer::putBomb()
{
	if (_bombCount <= 0)
		return;
	decBombCount();
	IEntity *bomb = new Bomb(_match, _z, _x, this);
	_match.addBomb(static_cast<Bomb *>(bomb));
	_match.getMap().addEntity(bomb);
}

int bbm::IPlayer::getPower()
{
	return _power;
}

void bbm::IPlayer::incBombCount()
{
	++_bombCount;
}

void bbm::IPlayer::decBombCount()
{
	--_bombCount;
}

bool bbm::IPlayer::checkCollision(int new_z, int new_x)
{
	int entities = _match.getMap().getEntitiesFromPos(new_z, new_x);

	if (entities & UNBREAKABLE_BLOCK)
		return false;
	if ((entities & BREAKABLE_BLOCK) || (entities & BOMB))
		return _passWall;
	return true;
}
