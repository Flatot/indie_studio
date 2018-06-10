/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Ia.cpp
*/

#include "Ia.hpp"
#include "Bomb.hpp"

bbm::Ia::Ia(Match &match, float z, float x, Entities playerNum, 
		TeamColor team) : 
	IPlayer(match, x, z, playerNum, team)
{
	_type = PlayerType::AI;
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
		d_map[n][x] = BOOM;
	}
	for (int n = y; n < (y + bombLen); n++) {
		entities = _match.getMap().getEntitiesFromPos(n, x);
		if (n > _match.getMap().getHeight() || 
			(entities & BREAKABLE_BLOCK) || 
			(entities & UNBREAKABLE_BLOCK))
			break ;
		d_map[n][x] = BOOM;
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
		d_map[y][n] = BOOM;
	}
	for (int n = x; n > (x - bombLen); n--) {
		entities = _match.getMap().getEntitiesFromPos(y, n);
		if (n < 0 || (entities & BREAKABLE_BLOCK) || 
			(entities & UNBREAKABLE_BLOCK))
			break ;
		d_map[y][n] = BOOM;
	}
	fill_dangerosity_bis(bombLen, y, x);
}

void	bbm::Ia::scaleBomb()
{
	int	bLen = 2;

	for (int y = 0; y < _match.getMap().getHeight(); y++) {
		for (int x = 0; x < _match.getMap().getWidth(); x++) {
			auto ent = _match.getMap().getEntitiesFromPos(y, x);
			if (d_map[y][x] == BOOM) {
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
				tmp.push_back(NOGO);
			else if ((entities & BOMB))
				tmp.push_back(BOOM);
			else
				tmp.push_back(GOAL);
		}
		newMap.push_back(tmp);
		tmp.clear();
	}
	return newMap;
}

bool bbm::Ia::checkAllDefensive(int dir)
{
	if (dir == 0) {
		if (d_map[ym - 1][xm] == GOAL)
			return (true);
		return (false);
	}
	if (dir == 1) {
		if (d_map[ym][xm + 1] == GOAL)
			return (true);
		return (false);
	}
	if (dir == 2) {
		if (d_map[ym + 1][xm] == GOAL)
			return (true);
		return (false);
	}
	if (d_map[ym][xm - 1] == GOAL)
		return (true);
	return (false);
}

bool bbm::Ia::seeAllMoveDefensive(int dir)
{
	if (dir == 0) {
		if (d_map[ym - 1][xm] != NOGO) {
            return (true);
        }
		return (false);
	}
	if (dir == 1) {
		if (d_map[ym][xm + 1] != NOGO)
			return (true);
		return (false);
	}
	if (dir == 2) {
		if (d_map[ym + 1][xm] != NOGO) {
           return (true);
        }
		return (false);
	}
	if (d_map[ym][xm - 1] != NOGO)
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
		setFrameMyLoop(0, 13);
		return ;
	}
	if (rec[0] == 1) {
		moveRight();
		setFrameMyLoop(0, 13);
		return ;
	}
	if (rec[0] == 2) {
		moveTop();
		setFrameMyLoop(0, 13);
		return ;
	}
	if (rec[0] == 3) {
		moveLeft();
		setFrameMyLoop(0, 13);
		return;
	}
	if (rec[0] == 4){
		putBomb();
		setFrameMyLoop(206, 250);
		return;
	}
	return;
}

void bbm::Ia::move_to_center()
{
	if (_z > std::floor(_z) + 0.5) {
		moveBottom();
		setFrameMyLoop(0, 13);
	}
	if (_z < std::floor(_z) + 0.5) {
		moveTop();
		setFrameMyLoop(0, 13);
	}
	if (_x > std::floor(_x) + 0.5) {
		moveLeft();
		setFrameMyLoop(0, 13);
	}
	if (_x < std::floor(_x) + 0.5) {
		moveRight();
		setFrameMyLoop(0, 13);
	}
}

void bbm::Ia::changeBoomTo(int zone)
{
    for(int j = 0; j < d_map.size(); j++){
        for (int i = 0; i < d_map[0].size(); i++){
            if (d_map[j][i] == BOOM)
                d_map[j][i] = zone;
        }
    }
}

void bbm::Ia::analyseMap()
{
	d_map = generateDMap();
	scaleBomb();
    changeBoomTo(DANGER);
	rec.push_back(4);
	if (d_map[_z][_x] == DANGER || d_map[_z][_x] == 4) {
		rec.clear();
		defensive_mode();
		move_to_rec();
        std::cout << "defensive" << std::endl;
        d_map.clear();
    }
	else {
        std::cout << "active" << std::endl;
        active_mode();
        if (rec[0] == 5)
            move_to_center();
        move_to_rec();
        getBonus();
	}
}

void	bbm::Ia::active_mode()
{
 	rec.clear();

    d_map = generateDMap();
    scaleBomb();
    changeBoomTo(NOGO);
    if (searchBonus()) {
        std::cout << "search bonus" << std::endl;
        return;
    }
	else {
		for (int i = 0; i < 4; i++) {
			if (checkAllBreakable(i, std::floor(_z), std::floor(_x)) && aliveIfBomb(4) && _bombCount != 0) {
				rec.clear();
				rec.push_back(4);
                std::cout << "bomb puting" << std::endl;
                return;
			}
		}
        if (wallCount() > 10) {
            findBreakable();
		setFrameMyLoop(206, 250);
            std::cout << "searching something to break" << std::endl;
        }
        else {
            timeToFight();
            std::cout << "fighting" << rec[0] << std::endl;
        }
    }
    return;
}

void bbm::Ia::timeToFight()
{
    std::vector<std::vector<int>> mem;
    mem = d_map;
    d_map = generateFMap();
    scaleBomb();
    changeBoomTo(1);
    for (int j = 0; j < d_map.size(); j++){
        for (int i = 0; i < d_map[0].size(); i++){
            std::cout << d_map[j][i];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    defensive_mode();
    if (f == 0 && objectif > 4) {
        std::cout << "trying to find ennemy player" << std::endl;
        return;
    }
    d_map = mem;
    std::cout << "objectif is at " << objectif << std::endl;
    if (objectif != 12 && aliveIfBomb(5) && _bombCount != 0) {
        rec.clear();
        rec.push_back(4);
        std::cout << "puting a bomb here because it's fun and i want to put a bomb" << std::endl;
    }
    else {
        rec.clear();
        rec.push_back(5);
	setFrameMyLoop(206, 250);
        std::cout << "idle" << std::endl;
    }
}

std::vector<std::vector<int>> bbm::Ia::generateFMap()
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
                tmp.push_back(NOGO);
            else if ((entities & BOMB))
                tmp.push_back(BOOM);
            else if ((entities & PLAYER_1) ||
                    (entities & PLAYER_2) ||
                    (entities & PLAYER_3) ||
                    (entities & PLAYER_4)) {
                tmp.push_back(GOAL);
            }
            else
                tmp.push_back(DANGER);
        }
        newMap.push_back(tmp);
        tmp.clear();
    }
    newMap[std::floor(_z)][std::floor(_x)] = DANGER;
    return newMap;
}

int bbm::Ia::wallCount()
{
    int count = 0;

    for (int y = 0; y < _match.getMap().getHeight(); y++) {
        for (int x = 0; x < _match.getMap().getWidth(); x++) {
            if (_match.getMap().getEntitiesFromPos(y, x) & BREAKABLE_BLOCK)
                count++;
        }
    }
    return (count);
}

void bbm::Ia::findBreakable()
{
    d_map = generateMMap();
    scaleBomb();
    changeBoomTo(NOGO);
    for (int j = 0; j < d_map.size(); j++){
        for (int i = 0; i < d_map[0].size(); i++){
            if (d_map[j][i] == 3)
                changeAllBreakableGoal(j, i);
        }
    }
    for (int j = 0; j < d_map.size(); j++){
        for (int i = 0; i < d_map[0].size(); i++){
            if (j == std::floor(_z) && i == std::floor(_x))
                std::cout << "P";
            else
                std::cout << d_map[j][i];
        }
        std::cout << std::endl;
    }
    if (checkAllNogo(std::floor(_z), std::floor(_x))){
        rec.clear();
        rec[0] = 5;
    }

    if (d_map[std::floor(_z)][std::floor(_x)] != 0) {
        defensive_mode();
        if (f != 0)
            rec[0] = 5;
    }
}

bool bbm::Ia::checkAllNogo(int y, int x)
{
    if (d_map[y - 1][x] == NOGO &&
            d_map[y + 1][x] == NOGO &&
            d_map[y][x - 1] == NOGO &&
            d_map[y][x + 1] == NOGO)
        return (true);
    return (false);
}

void bbm::Ia::changeAllBreakableGoal(int y, int x) {
    if (d_map[y - 1][x] == 2)
        d_map[y - 1][x] = GOAL;
    if (d_map[y + 1][x] == 2)
        d_map[y + 1][x] = GOAL;
    if (d_map[y][x - 1] == 2)
        d_map[y][x - 1] = GOAL;
    if (d_map[y][x + 1] == 2)
        d_map[y][x + 1] = GOAL;
    d_map[y][x] = NOGO;
}

bool bbm::Ia::searchBonus()
{
    std::vector<std::vector<int>> mem;
    mem = d_map;
	d_map = generateBMap();
    scaleBomb();
    changeBoomTo(NOGO);
	rec.clear();
	defensive_mode();
    if (f == 0){
        d_map = mem;
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
                    (entities & EXPLOSION))
                tmp.push_back(NOGO);
			else if ((entities & BONUS))
				tmp.push_back(GOAL);
            else if ((entities & BOMB))
                tmp.push_back(BOOM);
			else
				tmp.push_back(DANGER);
		}
		newMap.push_back(tmp);
		tmp.clear();
	}
	return newMap;
}

std::vector<std::vector<int>> bbm::Ia::generateMMap()
{
    std::vector<std::vector<int>> newMap;
    std::vector<int> tmp;
    int entities;

    for (int y = 0; y < _match.getMap().getHeight(); y++) {
        for (int x = 0; x < _match.getMap().getWidth(); x++) {
            entities = _match.getMap().getEntitiesFromPos(y, x);
            if ((entities & UNBREAKABLE_BLOCK) ||
                (entities & EXPLOSION))
                tmp.push_back(1);
            else if ((entities & BREAKABLE_BLOCK))
                tmp.push_back(3);
            else if ((entities & BOMB))
                tmp.push_back(BOOM);
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
 	return (false);
}

bool bbm::Ia::aliveIfBomb(int distance)
{
    std::vector<int> tmp;
 	std::vector<std::vector<int>> mem_map;

    mem_map = d_map;
    d_map[std::floor(_z)][std::floor(_x)] = 2;
    fill_dangerosity( _power + 1,std::floor(_z), std::floor(_x));
    defensive_mode();
 	if (f == 0 && objectif < distance){
 		rec.clear();
 		d_map = mem_map;
 		return (true);
 	}
 	d_map = mem_map;
 	return (false);
}
