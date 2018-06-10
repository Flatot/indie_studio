//
// EPITECH PROJECT, 2018
// Floor.cpp
// File description:
// Floor implementation
//

#include "Floor.hpp"

bbm::Floor::Floor(Graphic &graphic) :
	_meshPath(""),
	_texture("./assets/model3D/floor/textures/tatami.jpg"),
	_coefX(1.f),
	_coefY(1.f),
	_coefZ(1.f)
{
	auto scene = graphic.getScene();
	auto driver = graphic.getDriver();

	for (int z = 0; z < 13; ++z) {
		for (int x = 0; x < 15; ++x) {
			auto position = irr::core::vector3df(x * _coefX, 0,
					z * _coefZ);
			auto rotation = irr::core::vector3df(0, 0, 0);
			auto scale = irr::core::vector3df(_coefX, _coefY,
					_coefZ);
			auto f = scene->addCubeSceneNode(1.f, 0, -1,
					position, rotation, scale);
			f->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			f->setMaterialTexture(0, driver->getTexture(
						_texture.c_str()));
		}
	}
}
