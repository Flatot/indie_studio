/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** IEntity.cpp
*/

#include "IEntity.hpp"

bbm::IEntity::IEntity(Match &match, float x, float z, bool isTraversable) :
	_match(match),
	_x(x),
	_z(z),
	_isTraversable(isTraversable),
	_meshPath(),
	_texturePath(),
	_coefX(1.0f),
	_coefY(1.0f),
	_coefZ(1.0f)
{
	std::cout << "IEntity constructed" << std::endl;
}

int bbm::IEntity::getIdEntity()
{
	return _idEntity;
}

void bbm::IEntity::setCoefs(float coefX, float coefY, float coefZ)
{
	_coefX = coefX;
	_coefY = coefY;
	_coefZ = coefZ;
}

void bbm::IEntity::setMesh(irr::scene::IMeshSceneNode *mesh)
{
	_mesh = mesh;
}

void bbm::IEntity::setTexturePath(std::string &path)
{
	_texturePath = path;
}
