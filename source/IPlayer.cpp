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
	_speed(0)
{
	_idEntity = playerNum;
	setCoefs(.33f, .33f, .33f);
	auto position = irr::core::vector3df(_x * 2, 1, _z * 2);
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
	auto itPlayer = map.getItEntity(this);
	IEntity * player;
	float new_x;

	if (itPlayer.first == itPlayer.second)
		return;
	player = *itPlayer.first;
	std::cout << "MoveLeft" << std::endl;
	_mesh->setRotation(irr::core::vector3df(0.f, -90.f, 0.f));
	new_x = _x - (0.1f + (0.01f * _speed));
	if (std::floor(_x) != std::floor(new_x)) {
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
	auto itPlayer = map.getItEntity(this);
	IEntity * player;
	float new_x;

	if (itPlayer.first == itPlayer.second)
		return;
	player = *itPlayer.first;
	std::cout << "MoveRight" << std::endl;
	_mesh->setRotation(irr::core::vector3df(0.f, 90.f, 0.f));
	new_x = _x + (0.1f + (0.01f * _speed));
	if (std::floor(_x) != std::floor(new_x)) {
		std::cout << "before remove" << std::endl;
		map.removeEntity(this);
		std::cout << "after remove" << std::endl;
		_x = new_x;
		map.addEntity(this);
	} else
		_x = new_x;
	std::cout << map << std::endl;
}

void	bbm::IPlayer::moveTop()
{
	auto &map = _match.getMap();
	auto itPlayer = map.getItEntity(this);
	IEntity * player;
	float new_z;

	if (itPlayer.first == itPlayer.second)
		return;
	player = *itPlayer.first;
	std::cout << "MoveTop" << std::endl;
	_mesh->setRotation(irr::core::vector3df(0.f, 0.f, 0.f));
	new_z = _z + (0.1f + (0.01f * _speed));
	if (std::floor(_z) != std::floor(new_z)) {
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
	auto itPlayer = map.getItEntity(this);
	IEntity * player;
	float new_z;

	if (itPlayer.first == itPlayer.second)
		return;
	player = *itPlayer.first;
	std::cout << "MoveBottom" << std::endl;
	_mesh->setRotation(irr::core::vector3df(0.f, 180.f, 0.f));
	new_z = _z - (0.1f + (0.01f * _speed));
	if (std::floor(_z) != std::floor(new_z)) {
		map.removeEntity(this);
		_z = new_z;
		map.addEntity(this);
	} else
		_z = new_z;
	std::cout << map << std::endl;
}

void	bbm::IPlayer::putBomb()
{

}
