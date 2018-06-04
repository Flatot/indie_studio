//
// EPITECH PROJECT, 2018
// Map.hpp
// File description:
// Map class
//

#pragma once

#include <vector>
#include <iostream>
#include <fstream>

namespace bbm {
	class Map {
	public:
		Map();
		Map(std::vector<std::vector<int> > map);
		void save();
		void load();
		void display();
		std::vector<std::vector<int>> getMap() const{ return _map ;};
	private:
		std::vector<int> getVecFromLine(std::string line, std::string delimiter) const;
		int _length;
		int _width;
		std::vector<std::vector<int> > _map;
	};

}
std::ostream& operator<< (std::ostream& stream, bbm::Map const& map);
