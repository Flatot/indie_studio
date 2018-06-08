/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** IEntity.cpp
*/

#include "IEntity.hpp"

bbm::IEntity::IEntity(Match &match, float z, float x, bool isTraversable) :
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

}

bbm::IEntity::~IEntity()
{
	if (_mesh)
		_mesh->remove();
}

int bbm::IEntity::getIdEntity() const
{
	return _idEntity;
}

int bbm::IEntity::getPosX() const
{
	return _x;
}

int bbm::IEntity::getPosZ() const
{
	return _z;
}

bool bbm::IEntity::is(Entities entity) const
{
	return _idEntity == entity;
}

void bbm::IEntity::setCoefs(float coefX, float coefY, float coefZ)
{
	_coefX = coefX;
	_coefY = coefY;
	_coefZ = coefZ;
}

void bbm::IEntity::setMesh(irr::scene::ISceneNode *mesh)
{
	_mesh = mesh;
}

void bbm::IEntity::setTexturePath(std::string &path)
{
	_texturePath = path;
}

irr::scene::ISceneNode *bbm::IEntity::getMesh()
{
	return _mesh;
}

bbm::Type bbm::IEntity::getType() const
{
	return _type;
}
