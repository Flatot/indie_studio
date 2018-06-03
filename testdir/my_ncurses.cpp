//
// EPITECH PROJECT, 2018
// ncurse part
// File description:
// ncurse part
//

#include <curses.h>
#include <unistd.h>
#include "Ia.hpp"
#include "mapgen.hpp"
#include "header_curses.hpp"

char MyCurses::myTradCurse(int x)
{
    if (x == bbm::Entites::BLANK)
        return (' ');
    if (x == bbm::Entites::PLAYER_1)
        return ('P');
    if (x == bbm::Entites::UNBREAKABLE_BLOCK)
        return ('X');
    if (x == bbm::Entites::BREAKABLE_BLOCK)
        return ('o');
    if (x == bbm::Entites::BOMB)
        return ('B');
}

int MyCurses::myAffMapCurse(std::vector<std::vector<int>> mmap)
{
    int j = 0;
    int i = 0;

    while(j != mmap.size())
    {
        while (i != mmap[j].size())
        {
            mvaddch(j, i, myTradCurse(mmap[j][i]));
            i++;
        }
        i = 0;
        j++;
    }
    return (0);
}

void MyCurses::mySetLoop(std::vector<std::vector<int> > mmap)
{
    int exit = 0;
    int y;
    int x;
    bbm::Ia ia(1, 1);
    mmap[1][1] = bbm::Entites::PLAYER_1;
    myAffMapCurse(mmap);
    while (1)
    {
        wrefresh(stdscr);
        ia.analyseMap(mmap);
        if (ia.rec[0] == 4) {
            mmap[ia._y][ia._x] = bbm::Entites::BOMB;
            ia.analyseMap(mmap);
        }
        mmap = gameEventsCurse(mmap);
        mmap = ia.moveAllPlayer(ia.rec[0], mmap);
        getyx(stdscr, y, x);
        myAffMapCurse(mmap);
        wmove(stdscr, y, x);
        sleep(1);
    }
}

bbm::PlayerCurse::PlayerCurse(int y, int x) :
    _y(y),
    _x(x)
{
}

bbm::PlayerCurse::~PlayerCurse()
{
}

int MyCurses::myGameLaunch(std::vector<std::vector<int>> mmap)
{
    int i = 0;
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);
    nodelay(stdscr, TRUE);
    mySetLoop(mmap);
    return (0);
}