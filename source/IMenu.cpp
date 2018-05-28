/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** IMenu.cpp
*/

#include <iostream>
#include "IMenu.hpp"

bbm::IMenu::IMenu(Game &game) :
	_game(game)
{
	std::cout << "IMenu constructed" << std::endl;
}

virtual void	bbm::IMenu::draw()
{
	
}
