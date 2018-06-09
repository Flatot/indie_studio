/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Match.cpp
*/

#include <iostream>
#include "Match.hpp"
#include "Game.hpp"

bbm::Match::Match(Game &game) :
	IMyEventReceiver(),
	_game(game),
	_graphic(game.getGraphic()),
	_evManager(new EventManager()),
	_floor(game.getGraphic())
{
	_evManager->addEventReceiver(this);
	_camera = _graphic.getScene()->addCameraSceneNode(0, 
			irr::core::vector3df(1.3f, 2.6f, -3.4f), 
			irr::core::vector3df(1.2f, 0, 0));

}

void bbm::Match::init()
{
}

bool bbm::Match::OnEvent(const irr::SEvent &event)
{
	IMyEventReceiver::OnEvent(event);
	
	std::cout << "[OnEvent - Match]" << std::endl;
	if (isKeyPressed(irr::KEY_KEY_Q, NONE)) {
		deactivate();
		resetKey(irr::KEY_KEY_Q, NONE);
		return true;
	}
	return false;
}

void bbm::Match::draw()
{

}

bool bbm::Match::run()
{
	activate();

//	_graphic.getGuienv()->addStaticText(L"Hello Match! This is the Irrlicht Software renderer!",
//			irr::core::rect<irr::s32>(10,10,260,22), false);
	while(_graphic.getDevice()->run() && isActive()) {
		_graphic.setWindowCaption(_camera->getPosition(), L"Match loop");
		_graphic.getDriver()->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));
		_graphic.getScene()->drawAll();
//		_graphic.getGuienv()->drawAll();
		_graphic.getDriver()->endScene();
	}
	deactivate();
	return true;
}

void bbm::Match::update()
{

}

bbm::EventManager *bbm::Match::getEventManager()
{
	return _evManager;
}
