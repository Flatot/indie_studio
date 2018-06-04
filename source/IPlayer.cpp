/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** IPlayer.cpp
*/

#include "IPlayer.hpp"
#include "Match.hpp"

bbm::IPlayer::IPlayer(Match &match, float x, float z, Entities playerNum) :
	IEntity(match, x, z, true),
	_move(0),
	_timePoint(std::chrono::steady_clock::now())
{
	_idEntity = playerNum;
	setCoefs(.3f, .3f, .3f);
	auto position = irr::core::vector3df(x, 0, z);
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
	std::cout << "MoveLeft" << std::endl;
	_mesh->setRotation(irr::core::vector3df(0.f, -90.f, 0.f));
	_x -= 0.1f;
}

void	bbm::IPlayer::moveRight()
{
	std::cout << "MoveRight" << std::endl;
	_mesh->setRotation(irr::core::vector3df(0.f, 90.f, 0.f));
	_x += 0.1f;
}

void	bbm::IPlayer::moveTop()
{
	std::cout << "MoveTop" << std::endl;
	_mesh->setRotation(irr::core::vector3df(0.f, 0.f, 0.f));
	_z += 0.2f;
}

void	bbm::IPlayer::moveBottom()
{
	std::cout << "MoveBottom" << std::endl;
	_mesh->setRotation(irr::core::vector3df(0.f, 180.f, 0.f));
	_z -= 0.2f;
}

void	bbm::IPlayer::putBomb()
{

}
