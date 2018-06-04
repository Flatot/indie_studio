/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Map.cpp
*/

#include <sstream>
#include "Map.hpp"
#include "UnbreakableBlock.hpp"

bbm::Map::Map(Match &match) :
	_match(match),
	_height(0),
	_width(0),
	_map()
{
	std::cout << "Map constructed" << std::endl;
}

void bbm::Map::loadMap(std::vector<std::vector<int>> map)
{
	_height = map.size();
	if (!_height)
		return;
	_width = map[0].size();
	for (int i = 0; i < _height; ++i) {
		_map.push_back(std::vector<std::vector<IEntity *>>());
		for (int j = 0; j < _width; ++j) {
			_map[i].push_back(std::vector<IEntity *>());
			if (map[i][j] & UNBREAKABLE_BLOCK)
				_map[i][j].push_back(new UnbreakableBlock(_match, 
							i, j));
//			if (map[i][j] & BREAKABLE_BLOCK)
//				_map[i][j].push_back();
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
