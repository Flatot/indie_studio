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
	_menus(),
	_focused(0)
{

}

bbm::EventManager *bbm::IMenu::getEventManager()
{
	return _evManager;
}

void	bbm::IMenu::previousOne()
{
	_focused = _focused - 1;
	if (_focused < 0)
		_focused = _buttons.size() - 1;
}

void	bbm::IMenu::nextOne()
{
	_focused = _focused + 1;
	if (_focused >= _buttons.size())
		_focused = 0;
}