/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** IBlock.cpp
*/

#include "IBlock.hpp"

bbm::IBlock::IBlock(Match &match, float z, float x, bool isTraversable) :
	IEntity(match, x, z, isTraversable)
{

}

bbm::IBlock::~IBlock()
{

}
