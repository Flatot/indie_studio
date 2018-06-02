/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Ia.cpp
*/

#include "Ia.hpp"
#include <curses.h>

bbm::Ia::Ia(int y, int x) :
		PlayerCurse(y, x)
{
	std::cout << "IA constructed" << std::endl;
}

bbm::Ia::~Ia()
{
}

/*

void	find_best_way(int y, int x, int ite)
{
	if (distance_map[y][x] == ite) {
		if (map[y][x + 1] != 16 && map[y][x + 1] != 32) {
			distance[y][x + 1] = ite + 1;
		}
		if (map[y][x - 1] != 16 && map[y][x - 1] != 32) {
			distance[y][x - 1]= ite + 1;
		}
		if (map[y + 1][x] != 16 && map[y + 1][x] != 32) {
			distance[y + 1][x]= ite + 1;
		}
		if (map[y - 1][x] != 16 && map[y - 1][x] != 32) {
			distance[y - 1][x]= ite + 1;
		}
	}
}

void	Ia::fill_distance_map(int n, int i)
{
	for (int y = 0; y < 11; y++) {
		for (int x = 0; x < 13; x++) {
			if (y == n && x == 1)
				distance_map[y][x] = 0;
			else
				distance_map[y][x] = -1;
		}
	}
}
*/



bool bbm::Ia::checkAllDefensive(int dir) {
	if (dir == 0){
		if (d_map[ym - 1][xm] == 0)
			return (true);
		return (false);
	}
	if (dir == 1){
		if (d_map[ym][xm + 1] == 0)
			return (true);
		return (false);
	}
	if (dir == 2){
		if (d_map[ym + 1][xm] == 0)
			return (true);
		return (false);
	}
	if (d_map[ym][xm - 1] == 0)
		return (true);
	return (false);
}

bool bbm::Ia::seeAllMoveDefensive(int dir)
{
	if (dir == 0){
		if (map[ym - 1][xm] == bbm::Entites::BLANK)
			return (true);
		return (false);
	}
	if (dir == 1){
		if (map[ym][xm + 1] == bbm::Entites::BLANK)
			return (true);
		return (false);
	}
	if (dir == 2){
		if (map[ym + 1][xm] == bbm::Entites::BLANK)
			return (true);
		return (false);
	}
	if (map[ym][xm - 1] == bbm::Entites::BLANK)
		return (true);
	return (false);
}

bool bbm::Ia::seeAllMove(int dir)
{
	if (dir == 0){
		if (map[_y - 1][_x] == bbm::Entites::BLANK)
			return (true);
		return (false);
	}
	if (dir == 1){
		if (d_map[_y][_x + 1] == bbm::Entites::BLANK)
			return (true);
		return (false);
	}
	if (dir == 2){
		if (d_map[_y + 1][_x] == bbm::Entites::BLANK)
			return (true);
		return (false);
	}
	if (d_map[_y][_x - 1] == bbm::Entites::BLANK)
		return (true);
	return (false);
}

std::vector<int> bbm::Ia::moveAllDefensive(int dir)
{
	if (dir == 0){
		ym--;
		return (rec);
	}
	if (dir == 1){
		xm++;
		return (rec);
	}
	if (dir == 2){
		ym++;
		return (rec);
	}
	xm--;
	return (rec);
}

void bbm::Ia::pathFindingDefensive() {
	if (objectif == ite) {
		for (int i = 0; i < 4; i++){
			if (checkAllDefensive(i)) {
				f = 0;
				rec.push_back(i);
				return;
			}
		}
        return;
	}
    else {
        for (int i = 0; f != 0 && i < 4; i++){
            if (seeAllMoveDefensive(i)){
                moveAllDefensive(i);
                rec.push_back(i);
                ite++;
                pathFindingDefensive();
                ite--;
                moveAllDefensive((i + 2) % 4);
                if (f != 0)
                    rec.pop_back();
            }
        }
    }
    return;
}

void	bbm::Ia::defensive_mode()
{
	//rec.push_back(_y);
	//rec.push_back(_x);
	ym = _y;
	xm = _x;
	//rec.push_back(1);
	f = 1;
	//rec.push_back(0);
	//rec.push_back(0);
	objectif = 0;
	ite = 0;
    while (f != 0) {
        rec.clear();
        pathFindingDefensive();
        objectif++;
    }
        //for (unsigned i=0; i<rec.size(); i++)
	//	std::cout << rec[i] << std::endl;
}

void	bbm::Ia::active_mode()
{
	for (int i = 0; i < 10; i++){
		rec.push_back(5);
	}
}


void	bbm::Ia::fill_dangerosity(int bombLen, int y, int x)
{
	for (int n = x; n < (x + bombLen); n++) {
		if (n > map[0].size() || map[y][n] == bbm::Entites::BREAKABLE_BLOCK
			|| map[y][n] == bbm::Entites::UNBREAKABLE_BLOCK)
			break ;
		d_map[y][n] = 2;
	}
	for (int n = x; n > (x - bombLen); n--) {
		if (n < 0 || map[y][n] == bbm::Entites::BREAKABLE_BLOCK ||
				map[y][n] == bbm::Entites::UNBREAKABLE_BLOCK)
			break ;
		d_map[y][n] = 2;
	}
	for (int n = y; n > (y - bombLen); n--) {
		if (n < 0 || map[n][x] == bbm::Entites::BREAKABLE_BLOCK ||
				map[n][x] == bbm::Entites::UNBREAKABLE_BLOCK)
			break ;
		d_map[n][x] = 2;
	}
	for (int n = y; n < (y + bombLen); n++) {
		if (n > map.size() || map[n][x] == bbm::Entites::BREAKABLE_BLOCK ||
				map[n][x] == bbm::Entites::UNBREAKABLE_BLOCK)
			break ;
		d_map[n][x] = 2;
	}
}

void	bbm::Ia::scaleBomb()
{
	int	bombLen = 0;

	for (int y = 0; y < map.size(); y++) {
		for (int x = 0; x < map[0].size(); x++) {
			if (map[y][x] == bbm::Entites::BOMB) {
				bombLen = 3;
				fill_dangerosity(bombLen, y, x);
			}
		}
	}
}

void    bbm::Ia::analyseMap(std::vector<std::vector<int>> mmap)
{
	rec.clear();
	map = mmap;
	std::vector<int> tmp;

	//endwin();
	for (int y = 0; y < map.size(); y++) {
		for (int x = 0; x < map[0].size(); x++) {
			if (map[y][x] == bbm::Entites::BREAKABLE_BLOCK || map[y][x] == bbm::Entites::UNBREAKABLE_BLOCK)
				tmp.push_back(1);
			else if (map[y][x] == bbm::Entites::BOMB)
				tmp.push_back(2);
			else
				tmp.push_back(0);
		}
		d_map.push_back(tmp);
		tmp.clear();
	}
	scaleBomb();

	// d_map a fill a chaque fois qu'une bombe est posée
	if (d_map[_y][_x] == 2) {
        defensive_mode();
      //  exit(0);
	}
	else {
		active_mode();
	}
}