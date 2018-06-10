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
	_evManager->addEventReceiver(this);
}

bbm::EventManager *bbm::IMenu::getEventManager()
{
	return _evManager;
}

void	bbm::IMenu::previousOne()
{
	// _game.getGraphic().getGuienv()->
	// removeFocus(_btns[_focused]->getButton());
	_focused = _focused - 1;
	if (_focused < 0)
		_focused = _btns.size() - 1;
	_game.getGraphic().getGuienv()->
	setFocus(_btns[_focused]->getButton());
}

void	bbm::IMenu::nextOne()
{
	// _game.getGraphic().getGuienv()->
	// removeFocus(_btns[_focused]->getButton());
	_focused = _focused + 1;
	if (_focused >= _btns.size())
		_focused = 0;
	_game.getGraphic().getGuienv()->
	setFocus(_btns[_focused]->getButton());
}
