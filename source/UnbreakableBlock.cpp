//
// EPITECH PROJECT, 2018
// UnbreakableBlock.cpp
// File description:
// Unbreakable block implementation
//

#include <iostream>
#include "UnbreakableBlock.hpp"
#include "Match.hpp"

bbm::UnbreakableBlock::UnbreakableBlock(Match &match, float x, float z) :
	IBlock(match, x, z, false)
{
	_idEntity = UNBREAKABLE_BLOCK;
	setCoefs(0.4f, 0.4f, 0.4f);
	auto pos = irr::core::vector3df(x * _coefX, _coefY, z * _coefZ);
	auto scene = _match.getGraphic().getScene();

	_mesh = scene->addCubeSceneNode(0.4f, 0, -1, pos);
	_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
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
