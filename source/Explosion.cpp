//
// EPITECH PROJECT, 2018
// Explosion.cpp
// File description:
// Explosion implementation
//

#include "Explosion.hpp"
#include "Bomb.hpp"
#include "Match.hpp"

bbm::Explosion::Explosion(Match &match, float z, float x, Bomb *owner) :
	IEntity(match, z, x, true),
	_owner(owner),
	_timePoint(std::chrono::steady_clock::now())
{
	_idEntity = EXPLOSION;
	_texturePath = "./assets/model3D/Cube/fire.jpg";
	setCoefs(1.f, 1.f, 1.f);
	auto position = irr::core::vector3df(x, _coefY, z);
	auto rotation = irr::core::vector3df(0, 0, 0);
	auto scale = irr::core::vector3df(_coefX, _coefY, _coefZ);
	auto scene = _match.getGraphic().getScene();
	auto driver = _match.getGraphic().getDriver();

	_mesh = scene->addCubeSceneNode(1.f, 0, -1, position, rotation, scale);
	_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_mesh->setMaterialTexture(0, driver->getTexture(_texturePath.c_str()));
}

bbm::Explosion::~Explosion()
{

}

void bbm::Explosion::spawn()
{
	
}

void bbm::Explosion::die()
{
	auto entities = _match.getMap().getFromPos(_z, _x);
	auto idEntities = _match.getMap().getEntitiesFromPos(_z, _x);

	_owner->removeExplosion(this);
	if (idEntities & BREAKABLE_BLOCK)
		for (int i = 0; i < entities.size(); ++i, 
				entities = _match.getMap().getFromPos(_z, _x))
			if (entities[i] != this && !entities[i]->is(BOMB))
				entities[i--]->die();
	delete this;
}

void bbm::Explosion::update()
{
	auto entities = _match.getMap().getFromPos(_z, _x);
	auto timePoint = std::chrono::steady_clock::now();
	auto diff = std::chrono::duration_cast<std::chrono::seconds>
		(timePoint - _timePoint);

	for (int i = 0; i < entities.size(); ++i, 
			entities = _match.getMap().getFromPos(_z, _x))
		if (entities[i] != this && !entities[i]->is(BOMB) && 
				!entities[i]->is(BREAKABLE_BLOCK))
			entities[i--]->die();
	if (diff.count() >= 1)
		die();
}
