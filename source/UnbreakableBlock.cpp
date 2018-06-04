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
	irr::core::vector3df pos(x * _coefX, 0, z * _coefZ);
	setMesh(match.getGraphic().getScene()->addCubeSceneNode(
				0.4f, 0, -1, pos));
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
