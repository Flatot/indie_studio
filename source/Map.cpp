/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Map.cpp
*/

#include <sstream>
#include <iostream>
#include <algorithm>
#include "Map.hpp"
#include "UnbreakableBlock.hpp"
#include "BreakableBlock.hpp"
#include "Player.hpp"

bbm::Map::Map(Match &match) :
	_match(match),
	_height(0),
	_width(0),
	_map()
{
	std::cout << "Map constructed" << std::endl;
}

bbm::Map::~Map()
{

}

void bbm::Map::loadMap(std::vector<std::vector<int>> map)
{
	_height = map.size();
	if (!_height)
		return;
	_width = map[0].size();
	for (int y = 0; y < _height; ++y) {
		_map.push_back(std::vector<std::vector<IEntity *>>());
		for (int x = 0; x < _width; ++x) {
			_map[y].push_back(std::vector<IEntity *>());
			if (map[y][x] & UNBREAKABLE_BLOCK)
				_map[y][x].push_back(new UnbreakableBlock(_match, 
							y, x));
			if (map[y][x] & BREAKABLE_BLOCK)
				_map[y][x].push_back(new BreakableBlock(_match,
							y, x));
			if (map[y][x] & PLAYER_1)
				_map[y][x].push_back(new Player(_match, y, x, PLAYER_1));
			if (map[y][x] & PLAYER_2)
				_map[y][x].push_back(new Player(_match, y, x, PLAYER_2));
			if (map[y][x] & PLAYER_3)
				_map[y][x].push_back(new Player(_match, y, x, PLAYER_3));
			if (map[y][x] & PLAYER_4)
				_map[y][x].push_back(new Player(_match, y, x, PLAYER_4));
		}
	}
}

int bbm::Map::getHeight() const
{
	return _height;
}

int bbm::Map::getWidth() const
{
	return _width;
}

std::vector<bbm::IEntity *> &bbm::Map::getFromPos(int y, int x)
{
	return _map[y][x];
}

int bbm::Map::getEntitiesFromPos(int y, int x) const
{
	int values = 0;
	
	for (int i = 0; i < _map[y][x].size(); ++i)
		values += _map[y][x][i]->getIdEntity();
	return values;
}

bbm::IEntity *bbm::Map::getEntity(int y, int x, Entities entity)
{
	auto vec = _map[y][x];

	for (int i = 0; i < vec.size(); ++i)
		if (vec[i]->is(entity))
			return vec[i];
	return nullptr;
}

std::ostream& operator<< (std::ostream& stream, bbm::Map const& map) 
{
	for (int j = 0; j < map.getHeight(); j++) {
		for (int i = 0; i < map.getWidth(); i++) {
			stream << map.getEntitiesFromPos(j, i);
			if (i != map.getWidth() - 1)
				stream << ",";
		}
		stream << std::endl;
	}
	return stream;
}

void bbm::Map::save()
{
	std::ofstream myfile;

	myfile.open("./MapSave.txt");
	if (myfile.is_open() == false)
		return;
	myfile << *this;
	myfile.close();
}

void bbm::Map::load()
{
	std::ifstream infile("./MapSave.txt");
	std::string line;
	std::string delimiter = ",";
	std::vector<std::vector<int>> finalMap;

	while (std::getline(infile, line))
		finalMap.push_back(getVecFromLine(line, delimiter));
	loadMap(finalMap);
}

std::vector<int> bbm::Map::getVecFromLine(std::string line, 
		std::string delimiter) const 
{
	std::vector<int> tmp;
	size_t pos = 0;
	std::string token;
	std::string::size_type sz;

	while ((pos = line.find(delimiter)) != std::string::npos) {
		token = line.substr(0, pos);
		tmp.push_back(std::stoi(token, &sz));
		line.erase(0, pos + delimiter.length());
	}
	tmp.push_back(std::stoi(line, &sz));
	return tmp;
}

void bbm::Map::clear()
{
	for (int z = 0; z < getHeight(); ++z)
		for (int x = 0; x < getWidth(); ++x)
			for (int i = 0; i < _map[z][x].size(); ++i)
				delete _map[z][x][i];
//	 _map[z][x][i]->die();
	_map.clear();
}

void bbm::Map::addEntity(IEntity *entity)
{
	if (!entity) {
		std::cerr << "Map::addEntity, entity == nullptr" << std::endl;
		exit(84);
	}
	_map[entity->getPosZ()][entity->getPosX()].push_back(entity);
}

void bbm::Map::removeEntity(IEntity *entity)
{
	auto &vec = _map[entity->getPosZ()][entity->getPosX()];
	
	vec.erase(std::remove(vec.begin(), vec.end(), entity), vec.end());
}

std::pair<std::vector<bbm::IEntity *>::iterator, 
	std::vector<bbm::IEntity *>::iterator> 
	bbm::Map::getItEntity(IEntity *entity)
{
	auto vec = _map[entity->getPosZ()][entity->getPosX()];

	for (auto it = vec.begin(); it != vec.end(); ++it)
		if ((*it)->getIdEntity() == entity->getIdEntity())
			return std::make_pair(it, vec.end());
	return std::make_pair(vec.end(), vec.end());
}
