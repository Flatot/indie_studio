//
// EPITECH PROJECT, 2018
// indie
// File description:
// lobby menu
//

#include "MenuLobby.hpp"
#include "Game.hpp"

bbm::MenuLobby::MenuLobby(bbm::Game &game) : _game(game)
{
	_camera = _game.getGraphic().getScene()->addCameraSceneNode(0,
			irr::core::vector3df(20.0f, 20.0f, 20.0f),
			irr::core::vector3df(90.0f, 0.0f, 90.0f));
	auto texture = _game.getGraphic().getDriver()->
	getTexture("./assets/model3D/Cube/unbreakable.jpg");

	initPilars();
	for (int i = 0; i < 8; i++) {
		_blocks[i]->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		_blocks[i]->setMaterialTexture(0, texture);
		_blocks[i]->setVisible(false);
	}
	initNinjas();
	initTextures();
	_skyTexture = _game.getGraphic().getDriver()->getTexture(
		"./assets/model3D/Sky/brouillard.jpg");
	_skyBox = _game.getGraphic().getScene()->addSkyBoxSceneNode(
		_skyTexture, _skyTexture, _skyTexture, _skyTexture,
		_skyTexture, _skyTexture);
	_skyBox->setVisible(false);
}

bbm::MenuLobby::~MenuLobby()
{
}

void	bbm::MenuLobby::initTextures()
{
	_textures.push_back(_game.getGraphic().getDriver()->getTexture(
		"./assets/model3D/player/blue.jpg"));
	_textures.push_back(_game.getGraphic().getDriver()->getTexture(
		"./assets/model3D/player/red.jpg"));
	_textures.push_back(_game.getGraphic().getDriver()->getTexture(
		"./assets/model3D/player/green.jpg"));
	_textures.push_back(_game.getGraphic().getDriver()->getTexture(
		"./assets/model3D/player/purple.jpg"));
}

void	bbm::MenuLobby::initNinjas()
{
	auto scale = irr::core::vector3df(0.15f, 0.15f, 0.15f);
	auto scene = _game.getGraphic().getScene();
	auto mesh = scene->getMesh("./assets/model3D/player/ninja.b3d");

	auto position = irr::core::vector3df(2, 2.5f, 3);
	_ninjas.push_back(scene->addAnimatedMeshSceneNode(mesh, 0, -1,
		position, irr::core::vector3df(0, 45, 0), scale));
	position = irr::core::vector3df(12, 2.5f, 3);
	_ninjas.push_back(scene->addAnimatedMeshSceneNode(mesh, 0, -1,
		position, irr::core::vector3df(0, 315, 0), scale));
	position = irr::core::vector3df(2, 2.5f, 9);
	_ninjas.push_back(scene->addAnimatedMeshSceneNode(mesh, 0, -1,
		position, irr::core::vector3df(0, 135, 0), scale));
	position = irr::core::vector3df(12, 2.5f, 9);
	_ninjas.push_back(scene->addAnimatedMeshSceneNode(mesh, 0, -1,
		position, irr::core::vector3df(0, 225, 0), scale));
	for (int i = 0; i < 4; i++) {
		_ninjas[i]->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		_ninjas[i]->setVisible(false);
	}

}

void	bbm::MenuLobby::initPilars()
{
	auto rot = irr::core::vector3df(90, 45, 0);
	auto scl = irr::core::vector3df(1, 1, 1);
	auto scene = _game.getGraphic().getScene();
	auto pos = irr::core::vector3df(2, 1, 3);

	_blocks.push_back(scene->addCubeSceneNode(1.f, 0, -1, pos, rot, scl));
	pos = irr::core::vector3df(2, 2, 3);
	_blocks.push_back(scene->addCubeSceneNode(1.f, 0, -1, pos, rot, scl));
	pos = irr::core::vector3df(12, 1, 3);
	_blocks.push_back(scene->addCubeSceneNode(1.f, 0, -1, pos, rot, scl));
	pos = irr::core::vector3df(12, 2, 3);
	_blocks.push_back(scene->addCubeSceneNode(1.f, 0, -1, pos, rot, scl));
	pos = irr::core::vector3df(2, 1, 9);
	_blocks.push_back(scene->addCubeSceneNode(1.f, 0, -1, pos, rot, scl));
	pos = irr::core::vector3df(2, 2, 9);
	_blocks.push_back(scene->addCubeSceneNode(1.f, 0, -1, pos, rot, scl));
	pos = irr::core::vector3df(12, 1, 9);
	_blocks.push_back(scene->addCubeSceneNode(1.f, 0, -1, pos, rot, scl));
	pos = irr::core::vector3df(12, 2, 9);
	_blocks.push_back(scene->addCubeSceneNode(1.f, 0, -1, pos, rot, scl));
}

void	bbm::MenuLobby::setVisible(bool visible)
{
	for (int i = 0; i < 8; i++)
		_blocks[i]->setVisible(visible);
}

void	bbm::MenuLobby::draw(std::vector<bbm::AttrEntity> attrs,
	std::vector<bbm::TeamColor> teams)
{
	setVisible(true);
	_skyBox->setVisible(true);
	for (int i = 0; i < 4; i++) {
		_ninjas[i]->setVisible(false);
		if (attrs[i] != bbm::ATTR_NONE) {
			_ninjas[i]->setVisible(true);
			_ninjas[i]->setMaterialTexture(0, _textures[teams[i]]);
		}
		if (_ninjas[i]->getStartFrame() != 206 &&
				_ninjas[i]->getEndFrame() != 250)
			_ninjas[i]->setFrameLoop(206, 250);
	}
	_game.getGraphic().getScene()->drawAll();
	for (int i = 0; i < 4; i++)
		_ninjas[i]->setVisible(false);
	setVisible(false);
	_skyBox->setVisible(false);
	std::cout << "Menu Lobby" << std::endl;
}