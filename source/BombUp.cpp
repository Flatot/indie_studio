/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** BombUp.cpp
*/

#include "BombUp.hpp"

bbm::BombUp::BombUp(Match &match, float z, float x, bool isTraversable) :
	bbm::IBonus(match, x, z, isTraversable)
{
	_idEntity = BONUS;
	_texturePath = "./assets/model3D/Bonus/bomb.jpg";
	setCoefs(1.f, 1.f, 1.f);
	auto position = irr::core::vector3df(x * _coefX, _coefY, z * _coefZ);
	auto rotation = irr::core::vector3df(0, 0, 0);
	auto scale = irr::core::vector3df(_coefX, _coefY, _coefZ);
	auto scene = _match.getGraphic().getScene();
	auto driver = _match.getGraphic().getDriver();

	_mesh = scene->addCubeSceneNode(1.f, 0, -1, position, rotation, scale);
	_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_mesh->setMaterialTexture(0, driver->getTexture(_texturePath.c_str()));
}

void bbm::BombUp::spawn()
{

}

void bbm::BombUp::die()
{

}

void bbm::BombUp::update()
{

}