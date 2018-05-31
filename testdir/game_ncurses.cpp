//
// Created by ryudi on 31/05/18.
//

#include <curses.h>
#include "mapgen.hpp"
#include "header_curses.hpp"

std::vector<std::vector<int>> MyCurses::moveCursor(
        int c, int right, int down, std::vector<std::vector<int>> mmap)
{
    int y;
    int x;
    getyx(stdscr, y, x);
    if (c == KEY_LEFT && x != 0)
        wmove(stdscr, y, x - 1);
    if (c == KEY_RIGHT && x != right - 1)
        wmove(stdscr, y, x + 1);
    if (c == KEY_UP && y != 0)
        wmove(stdscr, y - 1, x);
    if (c == KEY_DOWN && x != down)
        wmove(stdscr, y + 1, x);
    if (c == 'b') {
        mvwaddch(stdscr, y, x, 'B');
        mmap[y][x] = bbm::Entites::BOMB;
    }
    return (mmap);
}

std::vector<std::vector<int>> MyCurses::gameEventsCurse(std::vector<std::vector<int>> mmap)
{
    int c = getch();
    if (c == KEY_UP || c == KEY_DOWN || c == KEY_RIGHT || c == KEY_LEFT || c == 'b')
        mmap = moveCursor(c, mmap[0].size(), mmap.size(), mmap);
    return (mmap);
}