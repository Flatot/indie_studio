/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** IMenu.cpp
*/

#include <iostream>
#include "IMenu.hpp"
#include "Game.hpp"

bbm::IMenu::IMenu(Game &game) :
	IMyEventReceiver(),
	_game(game),
	_evManager(new EventManager()),
	_graphic(game.getGraphic()),
	_menus()
{

}

bbm::EventManager *bbm::IMenu::getEventManager()
{
	return _evManager;
}
