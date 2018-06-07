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

bbm::Bomb::Bomb(Match &match, float z, float x, IPlayer *owner) :
	IEntity(match, z, x, false),
	_owner(owner),
	_power(_owner->getPower()),
	_timePoint(std::chrono::steady_clock::now()),
	_map(match.getMap()),
	_exploded(false),
	_explosions()
{
	std::cout << "NEW BOMB" << std::endl;
	_idEntity = BOMB;
	_texturePath = "./assets/model3D/bomb/Bomb_obj/Albedo.png";
	_meshPath = "./assets/model3D/bomb/Bomb_obj/Bomb.obj";
	setCoefs(3.f, 3.f, 3.f);
	auto position = irr::core::vector3df(x * _coefX, _coefY, z * _coefZ);
	auto rotation = irr::core::vector3df(0, 0, 0);
	auto scale = irr::core::vector3df(_coefX, _coefY, _coefZ);
	auto scene = _match.getGraphic().getScene();
	auto driver = _match.getGraphic().getDriver();
	auto mesh = scene->getMesh(_meshPath.c_str());

	_mesh = scene->addAnimatedMeshSceneNode(mesh, 0, -1, position, rotation, scale);
	_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_mesh->setMaterialTexture(0, driver->getTexture(_texturePath.c_str()));
}

bbm::Bomb::~Bomb()
{
	std::cout << "Bomb destructor" << std::endl;
}

void bbm::Bomb::spawn()
{

}

void bbm::Bomb::die()
{
	std::cout << "Bomb die()" << std::endl;
	_mesh->remove();
	_mesh = nullptr;
	_owner->incBombCount();
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

void bbm::Bomb::explode()
{
	bool directions[4] = {true, true, true, true};

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
	std::cout << "ExplodeLine" << std::endl;
	auto entities = _map.getFromPos(z, x);
	bool ret = true;
	bool kill = false;
	std::vector<IEntity *> toKill;

	for (auto it = entities.begin(); it != entities.end(); ++it) {
		if ((*it)->is(UNBREAKABLE_BLOCK) || (*it)->is(EXPLOSION)) {
			return false;
		} else if (!kill && (*it)->is(BREAKABLE_BLOCK)) {
			toKill.push_back(*it);
		} else if ((*it)->is(BOMB)) {
			(*it--)->die();
			return false;
		} 
		if (kill) {
			toKill.push_back(*it);
		} else {
			ret = true;
		}
	}
	if (kill)
		for (; toKill.size() > 0;)
			toKill[0]->die();
	if (ret)
		addExplosion(new Explosion(_match, z, x, this));
	return ret;
}

void bbm::Bomb::addExplosion(Explosion *explo)
{
	std::cout << "EXPLOSION ADDED" << std::endl;
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
