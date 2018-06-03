/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Ia.cpp
*/

#include "Ia.hpp"
#include <curses.h>
#include <unistd.h>

bbm::Ia::Ia(int y, int x) :
		PlayerCurse(y, x)
{
	std::cout << "IA constructed" << std::endl;
}

bbm::Ia::~Ia()
{
}

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
	ym = _y;
	xm = _x;
	f = 1;
	objectif = 0;
	ite = 0;
    while (f != 0 && f != 2) {
        rec.clear();
        pathFindingDefensive();
        objectif++;
		if (objectif == 12){
			f = 2;
			rec.push_back(5);
		}
    }
}

bool bbm::Ia::checkAllBreakable(int dir, int y, int x)
{
	if (dir == 0){
		if (map[y - 1][x] == bbm::Entites::BREAKABLE_BLOCK)
			return (true);
		return (false);
	}
	if (dir == 1){
		if (map[y][x + 1] == bbm::Entites::BREAKABLE_BLOCK)
			return (true);
		return (false);
	}
	if (dir == 2){
		if (map[y + 1][x] == bbm::Entites::BREAKABLE_BLOCK)
			return (true);
		return (false);
	}
	if (dir == 3){
		if (map[y][x - 1] == bbm::Entites::BREAKABLE_BLOCK)
			return (true);
		return (false);
	}
}

bool bbm::Ia::aliveIfBomb()
{
	std::vector<int> tmp;
	std::vector<std::vector<int>> mem_map;

	printw("? ");
	map[_y][_x] = bbm::Entites::BOMB;
	mem_map = d_map;
	generateDMap();
	map[_y][_x] = bbm::Entites::PLAYER_1;
	defensive_mode();
	//d_map = mem_map;
	if (f == 0){
		rec.clear();
		printw("bomb ");
		d_map = mem_map;
		return (true);
	}
	if (f == 2){
		sleep(10);
		endwin();
		for (int y = 0; y < map.size(); y++) {
			for (int x = 0; x < map[0].size(); x++) {
				std::cout << d_map[y][x];
			}
			std::cout << std::endl;
		}
		exit(0);
	}
	d_map = mem_map;
	return (false);
}

void bbm::Ia::changeDMapToBMap()
{
	printw("move active ");
	for (int j = 0; j < map.size(); j++){
		for (int i = 0; i < map[0].size(); i++){
			if (d_map[j][i] == 0){
				if (!checkAllBreakable(i, j, i)) {
					d_map[j][i] = 4;
				} else
					printw("objective found ");
			}
		}
	}
	defensive_mode();
	if (rec[0] < 4 && rec[0] >= 0)
		printw("dir ");
	else
		printw("nodir");
}

void	bbm::Ia::active_mode()
{
	rec.clear();
	for (int j = 0; j < map.size(); j++){
		for (int i = 0; i < map[0].size(); i++){
			if (map[j][i] == bbm::Entites::BOMB) {
				rec.push_back(5);
				printw("stop ");
				return;
			}
		}
	}
	printw("active ");
	for (int i = 0; i < 4; i++){
		if (checkAllBreakable(i, _y, _x) && aliveIfBomb()) {
			rec.push_back(4);
			return;
		}
	}
	changeDMapToBMap();
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
	int	bombLen = 2;

	for (int y = 0; y < map.size(); y++) {
		for (int x = 0; x < map[0].size(); x++) {
			if (map[y][x] == bbm::Entites::BOMB) {
				bombLen = 2;
				fill_dangerosity(bombLen, y, x);
			}
		}
	}
}

void bbm::Ia::generateDMap()
{
	std::vector<int> tmp;

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
}

void    bbm::Ia::analyseMap(std::vector<std::vector<int>> mmap)
{
	rec.clear();
	map = mmap;
	generateDMap();
	if (d_map[_y][_x] == 2) {
	    defensive_mode();
    }
	else {
		active_mode();
	}
}