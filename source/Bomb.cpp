//
// EPITECH PROJECT, 2018
// Bomb.cpp
// File description:
// Bomb implementation
//

#include <iostream>
#include "Bomb.hpp"
#include "Map.hpp"
#include "Match.hpp"
#include "Game.hpp"

bbm::Bomb::Bomb(Match &match, float z, float x, IPlayer *owner) :
	IEntity(match, z, x, false),
	_owner(owner),
	_power(_owner->getPower()),
	_timePoint(std::chrono::steady_clock::now()),
	_map(match.getMap()),
	_exploded(false),
	_explosions()
{
	_idEntity = BOMB;
	_texturePath = "./assets/model3D/bomb/Bomb_obj/Albedo.png";
	_meshPath = "./assets/model3D/bomb/Bomb_obj/Bomb.obj";
	setCoefs(1.5f, 1.5f, 1.5f);
	x = std::floor(x);
	z = std::floor(z);
	auto position = irr::core::vector3df(x, 0.5, z);
	auto rotation = irr::core::vector3df(0, 0, 0);
	auto scale = irr::core::vector3df(_coefX, _coefY, _coefZ);
	auto scene = _match.getGraphic().getScene();
	auto driver = _match.getGraphic().getDriver();
	auto mesh = scene->getMesh(_meshPath.c_str());

	_mesh = scene->addAnimatedMeshSceneNode(mesh, 0, -1, position, rotation, scale);
	_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_mesh->setMaterialTexture(0, driver->getTexture(_texturePath.c_str()));
	particlesImplementation(x, z);
}

bbm::Bomb::~Bomb()
{
	if (_p)
		_p->remove();
	std::cout << "bomb destructor" << std::endl;
}

void bbm::Bomb::particlesImplementation(int x, int z)
{
	_p = _match.getGraphic().getScene()->addParticleSystemSceneNode(false);	
	irr::scene::IParticleEmitter* emitter = _p->createBoxEmitter(
	irr::core::aabbox3d<irr::f32>(x - 0.2, 0, z - 0.2, x, 1, z),
	irr::core::vector3df(0.0f,0.006f,0.0f),
	80,100,	irr::video::SColor(0,0,0,0),
	irr::video::SColor(0,255,255,255), 90, 90, 0,
	irr::core::dimension2df(0.1f,0.1f),
	irr::core::dimension2df(0.5f,0.5f));
	_p->setEmitter(emitter);
	emitter->drop();
	_p->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_p->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
	_p->setMaterialTexture(0, _match.getGraphic().getDriver()->
		getTexture("assets/model3D/spec_effect/smoke2.bmp"));
	_p->setMaterialType(irr::video::EMT_SOLID);
	irr::scene::IParticleAffector* affector =
	_p->createFadeOutParticleAffector(
	irr::video::SColor(0,0,0,0),3);
	_p->addAffector(affector);
}

void bbm::Bomb::spawn()
{

}

void bbm::Bomb::die()
{
	_mesh->remove();
	_mesh = nullptr;
	_owner->incBombCount();
	_p->remove();
	_p = nullptr;
	_match.getGame().getAudio().playBombeExplode();
	explode();
	_exploded = true;
	_timePoint = std::chrono::steady_clock::now(); 
}

void bbm::Bomb::update()
{
	auto timePoint = std::chrono::steady_clock::now();
	auto diff = std::chrono::duration_cast<std::chrono::seconds>
		(timePoint - _timePoint);

	if (!_exploded && diff.count() >= 3)
		die();	
	if (_exploded)
		for (int i = 0, lastSize = _explosions.size(); 
				i < _explosions.size(); ++i) {
			_explosions[i]->update();
			if (_explosions.size() != lastSize) {
				lastSize = _explosions.size();
				--i;
			}
		}
	if (_exploded && !_explosions.size()) {
		_match.removeBomb(this);
		_map.removeEntity(this);
		delete this;
	} 

}

int bbm::Bomb::getPower() const
{
	return _power;
}

void bbm::Bomb::explode()
{
	bool directions[4] = {true, true, true, true};

	_x = std::floor(_x);
	_z = std::floor(_z);
	addExplosion(new Explosion(_match, _z, _x, this));
	for (int i = 1; i <= _power; ++i) {
		if (directions[0])
			directions[0] = explodeLine(_z + i, _x);
		if (directions[1])
			directions[1] = explodeLine(_z - i, _x);
		if (directions[2])
			directions[2] = explodeLine(_z, _x + i);
		if (directions[3])
			directions[3] = explodeLine(_z, _x - i);
	}
}

bool bbm::Bomb::explodeLine(int z, int x)
{
	auto entities = _map.getFromPos(z, x);
	auto idEntities = _map.getEntitiesFromPos(z, x);
	bool ret = true;
	bool kill = false;
	std::vector<IEntity *> toKill;

	if ((idEntities & UNBREAKABLE_BLOCK))
		return false;
	if ((idEntities & BREAKABLE_BLOCK)) {
		if (!(idEntities & EXPLOSION)) {
			auto block = _map.getEntity(z, x, BREAKABLE_BLOCK);
			if (block)
				block->getMesh()->setVisible(false);
			addExplosion(new Explosion(_match, z, x, this));
		}
		return false;
	}
	if ((idEntities & BOMB)) {
		if (!(idEntities & EXPLOSION)) {
			for (auto it = entities.begin(); it != entities.end(); ++it, entities = _map.getFromPos(z, x))
				if (!(*it)->is(BOMB))
					(*it--)->die();
			entities[0]->die();
		}
		return false;
	}
	addExplosion(new Explosion(_match, z, x, this));
	return true;
}

void bbm::Bomb::addExplosion(Explosion *explo)
{
	_explosions.push_back(explo);
	_map.addEntity(explo);
	std::cout << _map << std::endl;
}

void bbm::Bomb::removeExplosion(Explosion *explo)
{
	for (auto it = _explosions.begin(); it != _explosions.end();)
		if (*it == explo)
			it = _explosions.erase(it);
		else
			++it;
	_map.removeEntity(explo);
}
