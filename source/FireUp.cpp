//
// EPITECH PROJECT, 2018
// IndieStudio
// File description:
// FireUp.cpp
//

#include "FireUp.hpp"

bbm::FireUp::FireUp(Match &match, float z, float x, bool isTraversable) :
	bbm::IBonus(match, x, z, isTraversable)
{
	_idEntity = BONUS;
	_texture = "./assets/model3D/Bonus/fire_up.jpg";
	setCoefs(1.f, 1.f, 1.f);
	auto pos = irr::core::vector3df(x * _coefX, _coefY, z * _coefZ);
	auto rotation = irr::core::vector3df(0, 0, 0);
	auto scale = irr::core::vector3df(_coefX, _coefY, _coefZ);
	auto scene = _match.getGraphic().getScene();
	auto driver = _match.getGraphic().getDriver();

	_mesh = scene->addCubeSceneNode(1.f, 0, -1, pos, rotation, scale);
	_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_mesh->setMaterialTexture(0, driver->getTexture(_texture.c_str()));
	_type = FIREUP;
}

void bbm::FireUp::spawn()
{

}

void bbm::FireUp::die()
{
	std::cout << "FireUp died" << std::endl;
	_match.getMap().removeEntity(this);
	delete this;
}

void bbm::FireUp::update()
{

}
