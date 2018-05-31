/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Ia.cpp
*/

#include "Ia.hpp"

Ia::Ia(Match &match, float x, float y) : _match(match), _x(x), _y(y)
{
	std::cout << "IA constructed" << std::endl;
}

Ia::~Ia()
{
}

void    Ia::spawn()
{

}

void    Ia::die()
{
        
}

void    Ia::update()
{
        
}

void	Ia:fill_dangerosity(int bombLen, int y, int x)
{
	for (int n = x; n < (x + bombLen); n++) {
		if (n > 13 || map[y][n] == 16 || map[y][n] == 32)
			break ;
		d_map[y][n] = 2;
	}
	for (n = x; n > (x - bombLen); n--) {
		if (n < 0 || map[y][n] == 16 || map[y][n] == 32)
			break ;
		d_map[y][n] = 2;
	}
	for (n = y; n > (y - bombLen); n--) {
		if (n < 0 || map[n][x] == 16 || map[n][x] == 32)
			break ;
		d_map[n][x] = 2;
	}
	for (n = y; n < (y + bombLen); n++) {
		if (n > 11 || map[n][x] == 16 || map[n][x] == 32)
			break ;
		d_map[n][x] = 2;
	}
}

void	Ia::scaleBomb()
{
	int	bombLen = 0;

	for (int y = 0; y < 11; y++) {
		for (int x = 0; x < 13; x++) {
			if (map[y][x] == 64) {
				bombLen = getPower(y, x);
				fill_dangerosity(bombLen, y, x);
			}
		}
	}
}

void	find_best_way(int y, int x, int ite)
{
	if (distance_map[y][x] == ite) {
		if (map[y][x + 1] != 16 && map[y][x + 1] != 32) {
			_direction[y][x + 1] = direction[y][x];
			distance[y][x + 1] = d + 1;
		}
		if (map[y][x + 1] != 16 && map[y][x + 1] != 32) {
			direction[y][x - 1] = direction[y][x];
			distance[y][x - 1]= d + 1;
		}
		if (map[y][x + 1] != 16 && map[y][x + 1] != 32) {
			direction[y+1][x] = direction[y][x];
			distance[y + 1][x]= d + 1;
		}
		if (map[y][x + 1] != 16 && map[y][x + 1] != 32) {
			direction[y-1][x] = direction[y][x];
			distance[y - 1][x]= d + 1;
		}
	}
}

void	Ia::defensive_mode(int ite)
{
	fill_distance_map(_y, _x);
	for (int y = 0; y < 11; y++) {
		for (int x = 0; x < 13; x++) {
			find_best_way(y, x, ite);
		}
	}
	defensive_mode(ite + 1);
}

void	Ia::fill_distance_map(int n, int i)
{
	for (int y = 0; y < 11; y++) {
		for (int x = 0; x < 13; x++) {
			if (y == n && x == 1)
				distance_map[y][x] = 0;
			else
				distance_map[y][x] = -1;
			_direction[y][x] = -1;
		}
	}
}

void	Ia::active_mode()
{

}

void    Ia::analysMap()
{
	for (int y = 0; y < 11; y++) {
		for (int x = 0; x < 13; x++) {
			if (map[y][x] == 16 || map[y][x] == 32)
				d_map[y][x] = 1;
			if (map[y][x] == 64)
				d_map[y][x] = 2;
			else
				d_map[y][x] = 0;
		}
	}
	scaleBomb();
	// d_map a fill a chaque fois qu'une bombe est posée
	if (d_map[_y][_x] == 2) {
		defensive_mode(0);
	}
	else {
		active_mode();
	}
}