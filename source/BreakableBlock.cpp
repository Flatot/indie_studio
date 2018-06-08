//
// EPITECH PROJECT, 2018
// BreakableBlock.cpp
// File description:
// Breakable block implementation
//

#include <iostream>
#include "BreakableBlock.hpp"
#include "Match.hpp"
#include "BombUp.hpp"

bbm::BreakableBlock::BreakableBlock(Match &match, float z, float x) :
	IBlock(match, x, z, true)
{
	_idEntity = BREAKABLE_BLOCK;
	_texturePath = "./assets/model3D/Cube/breakable.jpg";
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

void bbm::BreakableBlock::spawn()
{
	std::cout << "Breakable Block spawned" << std::endl;
}

void bbm::BreakableBlock::die()
{
	std::cout << "Breakable Block died" << std::endl;
	_match.getMap().removeEntity(this);
	delete this;
}

void bbm::BreakableBlock::update()
{
	std::cout << "Breakable Block updated" << std::endl;
}
