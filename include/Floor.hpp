//
// EPITECH PROJECT, 2018
// Floor.hpp
// File description:
// Floor class
//

#pragma once

#include "Graphic.hpp"

namespace bbm {
	class Floor {
	public:
		Floor(Graphic &graphic);
	private:
		const char *_meshPath;
		const char *_texturePath;
		float _coefX;
		float _coefY;
		float _coefZ;
	};
}
