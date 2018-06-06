//
// EPITECH PROJECT, 2018
// Floor.hpp
// File description:
// Floor class
//

#pragma once

#include <string>
#include "Graphic.hpp"

namespace bbm {
	class Floor {
	public:
		Floor(Graphic &graphic);
	private:
		std::string _meshPath;
		std::string _texturePath;
		float _coefX;
		float _coefY;
		float _coefZ;
	};
}
