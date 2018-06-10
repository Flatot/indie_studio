/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Game.cpp
*/

#include "Game.hpp"

bbm::Game::Game(Config &config) :
	_config(config),
	_evManager(new EventManager()),
	_graphic(config.getScreenWidth(), config.getScreenHeight(),
			config.getFullscreen(), _evManager),
	_mainMenu(new bbm::MenuMain(*this)),
	_inGameMenu(new bbm::MenuInGame(*this)),
	_match(*this),
	_matchLaunched(false),
	_audio(config.getVolumeGeneral(), config.getVolumeEffect())
{
	_evManager->setRoot(true);
	_evManager->addEventReceiver(_match.getEventManager());
	_evManager->addEventReceiver(_mainMenu->getEventManager());
	_evManager->addEventReceiver(_inGameMenu->getEventManager());
}

bbm::Graphic &bbm::Game::getGraphic()
{
	return _graphic;
}

bbm::Config &bbm::Game::getConfig()
{
	return _config;
}

bbm::Config &bbm::Game::getConfig() const
{
	return _config;
}

bbm::IMenu *bbm::Game::getMenuInGame() const
{
	return _inGameMenu;
}

bbm::Match &bbm::Game::getMatch()
{
	return _match;
}

bbm::Audio &bbm::Game::getAudio()
{
	return _audio;
}

bool bbm::Game::run()
{
	_audio.playMenuMusic();
	_mainMenu->run();
	_graphic.getDevice()->drop();
	_audio.stopMenuMusic();
	return true;
}

bool bbm::Game::launchMatch(std::vector<bbm::AttrEntity> attrs,
	std::vector<bbm::TeamColor> teams)
{
	_match.init(attrs, teams);
	_match.run();
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

bool bbm::Game::hasSave()
{
	std::ifstream file("PlayerMatch.cfg");

	if (!file)
		return false;
	file.close();
	return true;
}

void bbm::Game::save()
{

}

void bbm::Game::saveConfig()
{

}
