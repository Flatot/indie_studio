//
// EPITECH PROJECT, 2018
// MapGeneratorerator.cpp
// File description:
// MapGeneratorerator implementation
//

#include <fstream>
#include "MapGenerator.hpp"
#include "IEntity.hpp"

std::vector<std::vector<int>> bbm::MapGenerator::_map = 
					std::vector<std::vector<int>>(); 

std::vector<std::vector<int>> bbm::MapGenerator::generate(std::string path)
{
	_map.clear();
	getMapFromFile(path);
	createBreakable();
	return _map;
}

void bbm::MapGenerator::getMapFromFile(std::string path)
{
	std::vector<int> tmp;
	std::string stock;
	std::fstream fs;
	bool isFirstLine = true;

	fs.open(path, std::fstream::in);
	while (getline(fs, stock)) {
		if (isFirstLine) {
			_map.push_back(getVectorUnbreakableBlock(stock.size()));
			isFirstLine = false;
		}
		tmp.push_back(bbm::Entities::UNBREAKABLE_BLOCK);
		for (int i = 0; i < stock.size(); ++i)
			tmp.push_back(translate(stock[i]));
		tmp.push_back(bbm::Entities::UNBREAKABLE_BLOCK);
		_map.push_back(tmp);
		tmp.clear();
	}
	_map.push_back(_map[0]);
	fs.close();
}

std::vector<int> bbm::MapGenerator::getVectorUnbreakableBlock(
		unsigned long size)
{
	std::vector<int> tmp;
	
	for (unsigned long i = 0; i != size + 2; ++i)
		tmp.push_back(bbm::Entities::UNBREAKABLE_BLOCK);
	return (tmp);
}

int bbm::MapGenerator::translate(char c)
{
	if (c == '*')
		return (bbm::Entities::BLANK);
	if (c == 'x')
		return (bbm::Entities::UNBREAKABLE_BLOCK);
	else
		return (bbm::Entities::BLANK);
}


void bbm::MapGenerator::createBreakable()
{
	int i = 0;
	int j = 0;
	int r;

	srand(time(NULL));
	while (j != _map.size()) {
		while (i != _map[j].size()) {
			r = rand() % 10;
			if (_map[j][i] == bbm::Entities::BLANK && 
					(r != 1 & r != 2 & r != 3))
				_map[j][i] = bbm::Entities::BREAKABLE_BLOCK;
			i++;
		}
		i = 0;
		j++;
	}
	return (myStarts());
}

void bbm::MapGenerator::changeAllBlank(int y, int x, int dir)
{
	switch (dir) {
	case 0:
		_map[y - 1][x] = bbm::Entities::BLANK;
		break;
	case 1:
		_map[y][x + 1] = bbm::Entities::BLANK;
		break;
	case 2:
		_map[y + 1][x] = bbm::Entities::BLANK;
		break;
	case 3:
		_map[y][x - 1] = bbm::Entities::BLANK;
		break;
	}
}

void bbm::MapGenerator::lastChange(int y, int x)
{
	int r = rand();
	if (twoGood(y, x) > 1)
		return;
	while (!checkAllBreak(y, x, r % 4))
		r++;
	changeAllBlank(y, x, r % 4);
}

void bbm::MapGenerator::cleanStart(int y, int x)
{
	int r = rand();

	if (twoGood(y, x) == 0) {
		while (!checkAllBreak(y, x, r % 4))
			r++;
		changeAllBlank(y, x, r % 4);
	}
	r = rand();
	while (!checkAll(y, x, r % 4))
		r++;
	if ((r % 4) == 0)
		y--;
	else if ((r % 4) == 1)
		x++;
	else
		if ((r % 4) == 2)
			y++;
		else
			x--;
	lastChange(y, x);
}

void bbm::MapGenerator::myStarts()
{
	_map[1][1] = bbm::Entities::BLANK;
	if (twoGood(1, 1) < 2)
		cleanStart(1, 1);
	_map[1][_map[0].size() - 2] = bbm::Entities::BLANK;
	if (twoGood(1, _map[0].size() - 2) < 2)
		cleanStart(1, _map[0].size() - 2);
	_map[_map.size() - 2][1] = bbm::Entities::BLANK;
	if (twoGood(_map.size() - 2, 1) < 2)
		cleanStart(_map.size() - 2, 1);
	_map[_map.size() - 2][_map[0].size() - 2] = bbm::Entities::BLANK;
	if (twoGood(_map.size() - 2, _map[0].size() - 2) < 2)
		cleanStart(_map.size() - 2, _map[0].size() - 2);
}

bool bbm::MapGenerator::checkLeft(int y, int x)
{
	return (_map[y][x - 1] == bbm::Entities::BLANK);
}

bool bbm::MapGenerator::checkRight(int y, int x)
{
	return (_map[y][x + 1] == bbm::Entities::BLANK);
}

bool bbm::MapGenerator::checkDown(int y, int x)
{
	return (_map[y + 1][x] == bbm::Entities::BLANK);
}

bool bbm::MapGenerator::checkUp(int y, int x)
{
	return (_map[y - 1][x] == bbm::Entities::BLANK);
}

bool bbm::MapGenerator::checkAll(int y, int x, int dir)
{
	if (dir == 0)
		return (_map[y - 1][x] == bbm::Entities::BLANK);
	if (dir == 1)
		return (_map[y][x + 1] == bbm::Entities::BLANK);
	if (dir == 2)
		return (_map[y + 1][x] == bbm::Entities::BLANK);
	return (_map[y][x - 1] == bbm::Entities::BLANK);
}



bool bbm::MapGenerator::checkAllBreak(int y, int x, int dir)
{
	if (dir == 0)
		return (_map[y - 1][x] == bbm::Entities::BREAKABLE_BLOCK);
	if (dir == 1)
		return (_map[y][x + 1] == bbm::Entities::BREAKABLE_BLOCK);
	if (dir == 2)
		return (_map[y + 1][x] == bbm::Entities::BREAKABLE_BLOCK);
	return (_map[y][x - 1] == bbm::Entities::BREAKABLE_BLOCK);
}

int bbm::MapGenerator::twoGood(int y, int x)
{
	int s = 0;
	int i = 0;

	while (i != 4) {
		if (checkAll(y, x, i))
			s++;
		i++;
	}
	return (s);
}
