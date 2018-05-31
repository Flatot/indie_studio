//
// EPITECH PROJECT, 2018
// check
// File description:
// map generator
//

#include "mapgen.hpp"

bool bbm::MapGen::checkLeft(std::vector<std::vector<int>> mmap, int y, int x)
{
    if (mmap[y][x - 1] == bbm::Entites::BLANK)
        return (true);
}

bool bbm::MapGen::checkRight(std::vector<std::vector<int>> mmap, int y, int x)
{
    if (mmap[y][x + 1] == bbm::Entites::BLANK)
        return (true);
}

bool bbm::MapGen::checkDown(std::vector<std::vector<int>> mmap, int y, int x)
{
    if (mmap[y + 1][x] == bbm::Entites::BLANK)
        return (true);
}

bool bbm::MapGen::checkUp(std::vector<std::vector<int>> mmap, int y, int x)
{
    if (mmap[y - 1][x] == bbm::Entites::BLANK)
        return (true);
}

bool bbm::MapGen::checkAll(std::vector<std::vector<int>> mmap, int y, int x,
                           int dir)
{
    if (dir == 0)
        return (mmap[y - 1][x] == bbm::Entites::BLANK);
    if (dir == 1)
        return (mmap[y][x + 1] == bbm::Entites::BLANK);
    if (dir == 2)
        return (mmap[y + 1][x] == bbm::Entites::BLANK);
    return (mmap[y][x - 1] == bbm::Entites::BLANK);
}



bool bbm::MapGen::checkAllBreak(std::vector<std::vector<int>> mmap, int y,
                                int x, int dir)
{
    if (dir == 0)
        return (mmap[y - 1][x] == bbm::Entites::BREAKABLE_BLOCK);
    if (dir == 1)
        return (mmap[y][x + 1] == bbm::Entites::BREAKABLE_BLOCK);
    if (dir == 2)
        return (mmap[y + 1][x] == bbm::Entites::BREAKABLE_BLOCK);
    return (mmap[y][x - 1] == bbm::Entites::BREAKABLE_BLOCK);
}

int bbm::MapGen::twoGood(std::vector<std::vector<int>> mmap, int y, int x)
{
    int s = 0;
    int i = 0;

    while (i != 4) {
        if (checkAll(mmap, y, x, i))
            s++;
        i++;
    }
    return (s);
}
