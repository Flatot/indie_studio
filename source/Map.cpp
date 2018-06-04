/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Map.cpp
*/

#include <sstream>
#include "Map.hpp"

bbm::Map::Map() :
	_length(0),
	_width(0),
	_map()
{
	std::cout << "Map constructed" << std::endl;
}

bbm::Map::Map(std::vector<std::vector<int>> map) :
	_length(map.size()),
	_width(map[0].size()),
	_map(map)
{
	std::cout << "Map constructed" << std::endl;

}

void bbm::Map::display() {
	for (int j = 0; j < _map.size(); j++) {
		for (int i = 0; i < _map[0].size(); i++)
			std::cout << _map[j][i];
		std::cout << std::endl;
	}
}


std::ostream& operator<< (std::ostream& stream, bbm::Map const& map) {
	std::vector<std::vector<int>> _map = map.getMap();
	for (int j = 0; j < _map.size(); j++) {
		for (int i = 0; i < _map[0].size(); i++) {
			stream << _map[j][i];
			if (i != _map[j].size() - 1)
				stream << ",";
		}
		stream << std::endl;
	}
	return stream;
}

void bbm::Map::save()
{
	std::ofstream myfile;
	myfile.open("MapSave.txt");
	if (myfile.is_open() == false)
		return;
	myfile << *this;
	myfile.close();
}

void bbm::Map::load()
{
	std::ifstream infile("MapSave.txt");
	std::string line;
	std::string delimiter = ",";
	std::vector<std::vector<int>> finalvec;

	while (std::getline(infile, line))
	{
		finalvec.push_back(this->getVecFromLine(line, delimiter));
	}
	this->_map = finalvec;
}

std::vector<int> bbm::Map::getVecFromLine(std::string line, std::string delimiter) const {
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
