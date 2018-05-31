/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Match.cpp
*/

#include <iostream>
#include "Match.hpp"

bbm::Match::Match(Game &game) :
	_game(game)
{
	std::cout << "Match constructed" << std::endl;
}

void bbm::Match::init()
{
	
}

bool bbm::Match::OnEvent(const irr::SEvent &event)
{
	return true;
}

void bbm::Match::draw()
{

}

bool bbm::Match::run()
{
	return true;
}

void bbm::Match::update()
{

}
