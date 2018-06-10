//
// EPITECH PROJECT, 2018
// Explosion.cpp
// File description:
// Explosion implementation
//

#include "Explosion.hpp"
#include "Bomb.hpp"
#include "Match.hpp"
#include "BombUp.hpp"
#include "SpeedUp.hpp"
#include "FireUp.hpp"
#include "WallPass.hpp"

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
	particlesImplementation(_x, _z);
}

bbm::Explosion::~Explosion()
{
	if (_p)
		_p->remove();
}

void bbm::Explosion::particlesImplementation(int x, int z)
{
	_p = _match.getGraphic().getScene()->addParticleSystemSceneNode(false);
	irr::scene::IParticleEmitter* emitter = _p->createBoxEmitter(
	irr::core::aabbox3d<irr::f32>(x - 0.5, 0, z - 0.5, x + 0.5, 2, z + 0.5),
	irr::core::vector3df(0.0f,0.002f,0.0f),
	80,100,	irr::video::SColor(0,0,0,0),
	irr::video::SColor(0,255,255,255), 90, 90, 0,
	irr::core::dimension2df(0.1f,0.1f),
	irr::core::dimension2df(0.4f,0.4f));
	_p->setEmitter(emitter);
	emitter->drop();
	_p->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_p->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
	_p->setMaterialTexture(0, _match.getGraphic().getDriver()->
		getTexture("assets/model3D/spec_effect/fire.bmp"));
	_p->setMaterialType(irr::video::EMT_SOLID);
	irr::scene::IParticleAffector* affector =
	_p->createFadeOutParticleAffector(
	irr::video::SColor(0,0,0,0),3);
	_p->addAffector(affector);
}

void bbm::Explosion::spawn()
{
	
}

void bbm::Explosion::random_bonus(int random)
{
	if (random >= 0 && random <= 5) {
		auto *bonus = new WallPass(_match, _z, _x, true);
		_match.getMap().addEntity(bonus);
	}
	else if (random >= 6 && random <= 35) {
		auto *bonus = new FireUp(_match, _z, _x, true);
		_match.getMap().addEntity(bonus);
	}
	if (random >= 36 && random <= 65) {
		auto *bonus = new BombUp(_match, _z, _x, true);
		_match.getMap().addEntity(bonus);
	}
	if (random >= 66 && random <= 100) { //56
		auto *bonus = new FireUp(_match, _z, _x, true);
		_match.getMap().addEntity(bonus);
	}
}

void bbm::Explosion::die()
{
	auto entities = _match.getMap().getFromPos(_z, _x);
	auto idEntities = _match.getMap().getEntitiesFromPos(_z, _x);
	int random;

	_owner->removeExplosion(this);
	if (idEntities & BREAKABLE_BLOCK) {
		auto breakableBlock = _match.getMap().getEntity(_z, _x, 
				BREAKABLE_BLOCK);
		if (breakableBlock)
			breakableBlock->die();
		random = rand() % 100;
		if (random >= 0 && random <= 40) {
			random = rand() % 100;
			random_bonus(random);
		}
	}
	_p->remove();
	_p = nullptr;
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
	if (diff.count() >= 0.75)
		die();
}
