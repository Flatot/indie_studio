//
// EPITECH PROJECT, 2018
// UnbreakableBlock.cpp
// File description:
// Unbreakable block implementation
//

#include <iostream>
#include "UnbreakableBlock.hpp"
#include "Match.hpp"

bbm::UnbreakableBlock::UnbreakableBlock(Match &match, float z, float x) :
	IBlock(match, x, z, false)
{
	_idEntity = UNBREAKABLE_BLOCK;
	_texturePath = "./assets/model3D/Cube/unbreakable.jpg";
	setCoefs(1.f, 1.f, 1.f);
	auto position = irr::core::vector3df(x * _coefX, _coefY, z * _coefZ);
	auto rotation = irr::core::vector3df(90, 0, 0);
	auto scale = irr::core::vector3df(_coefX, _coefY, _coefZ);
	auto scene = _match.getGraphic().getScene();
	auto driver = _match.getGraphic().getDriver();

	_mesh = scene->addCubeSceneNode(1.f, 0, -1, position, rotation, scale);
	_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_mesh->setMaterialTexture(0, driver->getTexture(_texturePath.c_str()));
}

void bbm::UnbreakableBlock::spawn()
{
	std::cout << "Unbreakable Block spawned" << std::endl;
}

void bbm::UnbreakableBlock::die()
{
	std::cout << "Unbreakable Block died" << std::endl;
}

void bbm::UnbreakableBlock::update()
{
	std::cout << "Unbreakable Block updated" << std::endl;
}
