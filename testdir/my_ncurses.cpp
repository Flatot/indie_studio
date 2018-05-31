//
// EPITECH PROJECT, 2018
// ncurse part
// File description:
// ncurse part
//

#include <curses.h>
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

int MyCurses::mySetLoop(std::vector<std::vector<int>> mmap)
{
    int exit = 0;
    bbm::PlayerCurse Ia(1, 1);
    mmap[1][1] = bbm::Entites::PLAYER_1;

    myAffMapCurse(mmap);
    while (exit == 0)
    {
        wrefresh(stdscr);
        gameEventsCurse(mmap);
    }
    return (exit);
}

bbm::PlayerCurse::PlayerCurse(int y, int x)
{
    this->y = y;
    this->x = x;
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