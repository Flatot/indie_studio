/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Ia.cpp
*/

#include "Ia.hpp"
#include "Bomb.hpp"

bbm::Ia::Ia(Match &match, float z, float x, Entities playerNum) : 
	IPlayer(match, x, z, playerNum)
{

}

bbm::Ia::~Ia()
{
}

void    bbm::Ia::spawn()
{

}

void    bbm::Ia::die()
{
	IPlayer::die();
}

void    bbm::Ia::update()
{
	analyseMap();
        float z = _z - 0.5;
	float x = _x - 0.5;

	_mesh->setPosition(irr::core::vector3df(x, 0.5f, z));
}

void	bbm::Ia::fill_dangerosity_bis(int bombLen, int y, int x)
{
	int entities;

	for (int n = y; n > (y - bombLen); n--) {
		entities = _match.getMap().getEntitiesFromPos(n, x);
		if (n < 0 || (entities & BREAKABLE_BLOCK) || 
			(entities & UNBREAKABLE_BLOCK))
			break ;
		d_map[n][x] = 2;
	}
	for (int n = y; n < (y + bombLen); n++) {
		entities = _match.getMap().getEntitiesFromPos(n, x);
		if (n > _match.getMap().getHeight() || 
			(entities & BREAKABLE_BLOCK) || 
			(entities & UNBREAKABLE_BLOCK))
			break ;
		d_map[n][x] = 2;
	}
}

void	bbm::Ia::fill_dangerosity(int bombLen, int y, int x)
{
	int entities;

	for (int n = x; n < (x + bombLen); n++) {
		entities = _match.getMap().getEntitiesFromPos(y, n);
		if (n > _match.getMap().getWidth() || 
			(entities & BREAKABLE_BLOCK) || 
			(entities & UNBREAKABLE_BLOCK))
			break ;
		d_map[y][n] = 2;
	}
	for (int n = x; n > (x - bombLen); n--) {
		entities = _match.getMap().getEntitiesFromPos(y, n);
		if (n < 0 || (entities & BREAKABLE_BLOCK) || 
			(entities & UNBREAKABLE_BLOCK))
			break ;
		d_map[y][n] = 2;
	}
	fill_dangerosity_bis(bombLen, y, x);
}

void	bbm::Ia::scaleBomb()
{
	int	bLen = 2;

	for (int y = 0; y < _match.getMap().getHeight(); y++) {
		for (int x = 0; x < _match.getMap().getWidth(); x++) {
			auto ent = _match.getMap().getEntitiesFromPos(y, x);
			if (d_map[y][x] == 2) {
				auto entites = _match.getMap().getFromPos(y, x);
				for (int i = 0; i < entites.size(); ++i) {
					if (entites[i]->is(BOMB)) {
						auto bomb = static_cast<Bomb *>(entites[i]);
						bLen = bomb->getPower() + 1;
						fill_dangerosity(bLen, y, x);
					}
				}
			}
		}
	}
}

std::vector<std::vector<int>> bbm::Ia::generateDMap()
{
	std::vector<std::vector<int>> newMap;
	std::vector<int> tmp;
	int entities;

	for (int y = 0; y < _match.getMap().getHeight(); y++) {
		for (int x = 0; x < _match.getMap().getWidth(); x++) {
			entities = _match.getMap().getEntitiesFromPos(y, x);
			if ((entities & BREAKABLE_BLOCK) ||
				(entities & UNBREAKABLE_BLOCK) ||
				(entities & EXPLOSION))
				tmp.push_back(1);
			else if ((entities & BOMB))
				tmp.push_back(2);
			else
				tmp.push_back(0);
		}
		newMap.push_back(tmp);
		tmp.clear();
	}
	return newMap;
}

bool bbm::Ia::checkAllDefensive(int dir)
{
	if (dir == 0) {
		if (d_map[ym - 1][xm] == 0)
			return (true);
		return (false);
	}
	if (dir == 1) {
		if (d_map[ym][xm + 1] == 0)
			return (true);
		return (false);
	}
	if (dir == 2) {
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
	if (dir == 0) {
		if (d_map[ym - 1][xm] != 1) {
            return (true);
        }
		return (false);
	}
	if (dir == 1) {
		if (d_map[ym][xm + 1] != 1)
			return (true);
		return (false);
	}
	if (dir == 2) {
		if (d_map[ym + 1][xm] != 1) {
           return (true);
        }
		return (false);
	}
	if (d_map[ym][xm - 1] != 1)
		return (true);
	return (false);
}

void bbm::Ia::moveAllDefensive(int dir)
{
	if (dir == 0)
		ym--;
	if (dir == 1)
		xm++;
	if (dir == 2)
		ym++;
	if (dir == 3)
		xm--;
}

void bbm::Ia::pathFindingDefensive()
{
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
		for (int i = 0; f != 0 && i < 4; i++) {
			if (seeAllMoveDefensive(i)) {
 				rec.push_back(i);
				moveAllDefensive(i);
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
	ym = _z;
	xm = _x;
	f = 1;
	objectif = 0;
	ite = 0;
    	while (f != 0 && f != 2) {
		rec.clear();
		pathFindingDefensive();
		objectif++;
		if (objectif == 12) {
			f = 2;
			rec.push_back(5);
		}
	}
}

void bbm::Ia::move_to_rec()
{
    std::cout << rec[0] << std::endl;
	if (rec[0] == 0) {
		moveBottom();
		return ;
	}
	if (rec[0] == 1) {
		moveRight();
		return ;
	}
	if (rec[0] == 2) {
		moveTop();
		return ;
	}
	if (rec[0] == 3) {
        moveLeft();
        return;
    }
    if (rec[0] == 4){
        putBomb();
        return;

    }
	return;
}

void bbm::Ia::move_to_center()
{
	if (_z > std::floor(_z) + 0.5)
		moveBottom();
	if (_z < std::floor(_z) + 0.5)
		moveTop();
	if (_x > std::floor(_x) + 0.5)
		moveLeft();
	if (_x < std::floor(_x) + 0.5)
		moveRight();
}

void bbm::Ia::analyseMap()
{
	d_map = generateDMap();
	scaleBomb();

	rec.push_back(4);
	if (d_map[_z][_x] == 2 || d_map[_z][_x] == 4) {
		rec.clear();
		defensive_mode();
		move_to_rec();
        std::cout << "defensive" << std::endl;
        d_map.clear();
    }
	else {
        active_mode();
        move_to_rec();
        std::cout << "active" << std::endl;
		//move_to_center();
	}
}

void	bbm::Ia::active_mode()
{
 	rec.clear();

    d_map = generateDMap();
    scaleBomb();
    if (searchBonus()) {
        return;
    }
	else {

		for (int i = 0; i < 4; i++) {
			if (checkAllBreakable(i, std::floor(_z), std::floor(_x)) && aliveIfBomb()) {
				rec.clear();
				rec.push_back(4);
                return;
			}
		}
        rec.clear();
		rec.push_back(5);
	}
    return;
}

bool bbm::Ia::searchBonus()
{
    std::vector<std::vector<int>> mem;
    mem = d_map;
	d_map = generateBMap();
    scaleBomb();
	rec.clear();
	defensive_mode();
    if (f == 0){
        d_map = mem;
        move_to_rec();
        getBonus();
        return (true);
	}
    d_map = mem;
	return(false);
}

std::vector<std::vector<int>> bbm::Ia::generateBMap()
{
	std::vector<std::vector<int>> newMap;
	std::vector<int> tmp;
	int entities;

	for (int y = 0; y < _match.getMap().getHeight(); y++) {
		for (int x = 0; x < _match.getMap().getWidth(); x++) {
			entities = _match.getMap().getEntitiesFromPos(y, x);
			if ((entities & BREAKABLE_BLOCK) ||
				(entities & UNBREAKABLE_BLOCK) ||
                    (entities & EXPLOSION) ||
                    (entities & BOMB))
				tmp.push_back(1);
			else if ((entities & BONUS))
				tmp.push_back(0);
			else
				tmp.push_back(2);
		}
		newMap.push_back(tmp);
		tmp.clear();
	}
	return newMap;
}

bool bbm::Ia::checkAllBreakable(int dir, int y, int x)
{
    std::cout << "dir = " << dir << std::endl;
    if (dir == 0){
 		if (_match.getMap().getEntitiesFromPos(y - 1, x) & BREAKABLE_BLOCK)
 			return (true);
 		return (false);
 	}
 	if (dir == 1){
 		if (_match.getMap().getEntitiesFromPos(y, x + 1) & BREAKABLE_BLOCK)
 			return (true);
        return (false);
 	}
 	if (dir == 2){
 		if (_match.getMap().getEntitiesFromPos(y + 1, x) & BREAKABLE_BLOCK)
 			return (true);
 		return (false);
 	}
 	if (dir == 3){
 		if (_match.getMap().getEntitiesFromPos(y, x - 1) & BREAKABLE_BLOCK)
 			return (true);
 		return (false);
 	}
}

bool bbm::Ia::aliveIfBomb()
{
    std::vector<int> tmp;
 	std::vector<std::vector<int>> mem_map;

    mem_map = d_map;
    d_map[std::floor(_z)][std::floor(_x)] = 2;
    fill_dangerosity( _power + 1,std::floor(_z), std::floor(_x));
    defensive_mode();
 	if (f == 0 && objectif < 8){
 		rec.clear();
 		d_map = mem_map;
 		return (true);
 	}
 	d_map = mem_map;
 	return (false);
}
