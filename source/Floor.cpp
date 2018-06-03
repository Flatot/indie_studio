//
// EPITECH PROJECT, 2018
// Floor.cpp
// File description:
// Floor implementation
//

#include "Floor.hpp"

bbm::Floor::Floor(Graphic &graphic) :
	_meshPath("./assets/model3D/floor/Sci-Fi-Floor-1-OBJ.obj"),
	_texturePath("./assets/model3D/floor/textures/Sci-Fi-Floor-Gloss.tga"),
	_coefX(0.2f),
	_coefY(0),
	_coefZ(0.2f)
{
	auto *scene = graphic.getScene();
	auto *driver = graphic.getDriver();

	for (int z = 0; z < 13; ++z) {
		for (int x = 0; x < 15; ++x) {
			auto pos = irr::core::vector3df(x * _coefX, _coefY, 
					z * _coefZ);
			auto *floor = scene->addAnimatedMeshSceneNode(
					scene->getMesh(_meshPath), 0, -1, pos, 
					irr::core::vector3df(0, 0, 0), 
					irr::core::vector3df(1.0f, 1.0f, 1.0f));
			floor->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			floor->setMaterialTexture(0, driver->getTexture(
						_texturePath));
		}
	}
}
