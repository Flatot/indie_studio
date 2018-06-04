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
	setCoefs(0.02f, 0.02f, 0.02f);
	auto position = irr::core::vector3df(x * _coefX, 0, z * _coefZ);
	auto rotation = irr::core::vector3df(0, 0, 0);
	auto scale = irr::core::vector3df(_coefX, _coefY, _coefZ);
	auto scene = _match.getGraphic().getScene();
	auto mesh = scene->getMesh("./assets/model3D/player/BaymaxWhiteOBJ/"
			"Bigmax_White_OBJ.obj");

	if (!mesh) {
		std::cerr << "IPlayer constructor, "
			"scene->getMesh return nullptr" << std::endl;
		exit(84);
	}
	_mesh = scene->addAnimatedMeshSceneNode(mesh, 0, -1, position,
			rotation, scale);
	_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
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
