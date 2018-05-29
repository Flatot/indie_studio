/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Game.cpp
*/

#include "Game.hpp"

bbm::Game::Game() :
	_mainMenu(nullptr),
	_inGameMenu(nullptr),
	_match(*this)
{
	std::cout << "Game constructed" << std::endl;
}

bool	bbm::Game::run()
{
	return true;
}

bool	bbm::Game::launchMatch()
{
	return true;
}

bool	bbm::Game::launchInGameMenu()
{
	return true;
}

bool	bbm::Game::launchMainMenu()
{
	return true;
}

void	bbm::Game::save()
{
}

void	bbm::Game::saveConfig()
{
}
