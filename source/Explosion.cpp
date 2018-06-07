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
	_timePoint(std::chrono::steady_clock::now()),
	_alive(true)
{
	_idEntity = EXPLOSION;
	_texturePath = "./assets/model3D/Cube/fire.jpg";
	setCoefs(2.f, 2.f, 2.f);
	auto position = irr::core::vector3df(x * _coefX, _coefY, z * _coefZ);
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
	std::cout << "EXPLOSION DESTRUCTOR" << std::endl;
}

void bbm::Explosion::spawn()
{
	
}

void bbm::Explosion::die()
{
	std::cout << "Explosion die()" << std::endl;
	_owner->removeExplosion(this);
	_alive = false;
	delete this;
}

void bbm::Explosion::update()
{
	auto entities = _match.getMap().getFromPos(_z, _x);
	auto timePoint = std::chrono::steady_clock::now();
	auto diff = std::chrono::duration_cast<std::chrono::seconds>
		(timePoint - _timePoint);

	for (int i = 0; i < entities.size(); ++i)
		if (!entities[i]->is(EXPLOSION) && !entities[i]->is(BOMB))
			entities[i--]->die();
	if (diff.count() >= 1)
		die();
}

bool bbm::Explosion::isAlive()
{
	return _alive;
}
