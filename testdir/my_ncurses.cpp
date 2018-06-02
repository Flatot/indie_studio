//
// EPITECH PROJECT, 2018
// ncurse part
// File description:
// ncurse part
//

#include <curses.h>
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

int MyCurses::mySetLoop(std::vector<std::vector<int> > mmap)
{
    int exit = 0;
    int y;
    int x;
    bbm::Ia ia(6, 8);
    mmap[6][8] = bbm::Entites::PLAYER_1;
    mmap[4][8] = bbm::Entites::BOMB;
    mmap[6][7] = bbm::Entites::BOMB;
    mmap[7][7] = bbm::Entites::BOMB;
    ia.analyseMap(mmap);
    myAffMapCurse(mmap);
    while (exit == 0)
    {
        wrefresh(stdscr);
        mmap = gameEventsCurse(mmap);
        ia.analyseMap(mmap);
        mmap = ia.moveAllPlayer(ia.rec[0], mmap);
        getyx(stdscr, y, x);
        myAffMapCurse(mmap);
        wmove(stdscr, y, x);

    }
    return (exit);
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
//    curs_set(0);
    keypad(stdscr, true);
    nodelay(stdscr, TRUE);
    mySetLoop(mmap);
    return (0);
}