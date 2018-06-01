/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Game.cpp
*/

#include "Game.hpp"

bbm::Game::Game(Config &config) :
	IMyEventReceiver(),
	_config(config),
	_evManager(new EventManager()),
	_graphic(config.getScreenWidth(), config.getScreenHeight(), 
			config.getFullscreen(), _evManager),
	_mainMenu(nullptr),
	_inGameMenu(nullptr),
	_match(*this),
	_matchLaunched(false)
{
	_evManager->setRoot(true);
	_evManager->addEventReceiver(this);
	_evManager->addEventReceiver(_match.getEventManager());
	//_evManager->addEventReceiver(_mainMenu->getEventManager());
	//_evManager->addEventReceiver(_inGameMenu->getEventManager());
}

bbm::Graphic &bbm::Game::getGraphic()
{
	return _graphic;
}

bool bbm::Game::OnEvent(const irr::SEvent &event)
{
	IMyEventReceiver::OnEvent(event);
	static int i = 0;

	std::cout << "[OnEvent - Game]" << std::endl;
	if (isKeyPressed(irr::KEY_KEY_Q, NONE)) {
		_graphic.getDevice()->closeDevice();		
		return true;
	}
	if (isKeyPressed(irr::KEY_KEY_T, NONE)) {
		_matchLaunched = true;
		std::cout << "MatchLaunched" << std::endl;
		resetKey(irr::KEY_KEY_T, NONE);
		return true;
	}

	return false;
}

bool bbm::Game::run()
{
	activate();
	_graphic.getDevice()->setWindowCaption(L"Game loop");
	
	_graphic.getGuienv()->addStaticText(L"Hello Game! This is the Irrlicht Software renderer!",
			irr::core::rect<irr::s32>(10,10,260,22), false);
	while(_graphic.getDevice()->run()) {
		_graphic.getDriver()->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));
		
		_graphic.getGuienv()->drawAll();
		_graphic.getDriver()->endScene();
		launchMatch();
	}
	_graphic.getDevice()->drop();
	deactivate();
	return true;
}

bool bbm::Game::launchMatch()
{
	if (_matchLaunched) {
		deactivate();
		_match.run();
		activate();
	}
	_matchLaunched = false;
	return true;
}

bool bbm::Game::launchInGameMenu()
{
	return true;
}

bool bbm::Game::launchMainMenu()
{
	return true;
}

void bbm::Game::save()
{

}

void bbm::Game::saveConfig()
{

}

