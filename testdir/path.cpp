//
// EPITECH PROJECT, 2018
// path
// File description:
// map generator
//

#include "mapgen.hpp"

std::vector<std::vector<int>> bbm::MapGen::changeAllBlank(
        std::vector<std::vector<int>> mmap, int y, int x, int dir)
{
    if (dir == 0) {
        mmap[y - 1][x] = bbm::Entites::BLANK;
        return (mmap);
    }
    if (dir == 1) {
        mmap[y][x + 1] = bbm::Entites::BLANK;
        return (mmap);
    }
    if (dir == 2){
        mmap[y + 1][x] = bbm::Entites::BLANK;
        return (mmap);
    }
    if (dir == 3) {
        mmap[y][x - 1] = bbm::Entites::BLANK;
        return (mmap);
    }
}

std::vector<std::vector<int>> bbm::MapGen::lastChange(
        std::vector<std::vector<int>> mmap, int y, int x)
{
    int r = rand();
    if (twoGood(mmap, y, x) > 1)
        return (mmap);
    while (!checkAllBreak(mmap, y, x, r % 4))
        r++;
    return(changeAllBlank(mmap, y, x, r % 4));
}

std::vector<std::vector<int>> bbm::MapGen::cleanStart(
        std::vector<std::vector<int>> mmap, int y, int x)
{
    int r = rand();
    if (twoGood(mmap, y, x) == 0){
        while (!checkAllBreak(mmap, y, x, r % 4))
            r++;
        mmap = changeAllBlank(mmap, y, x, r % 4);
    }
    r = rand();
    while (!checkAll(mmap, y, x, r % 4))
        r++;
    if (r % 4 == 0)
        y--;
    if (r % 4 == 1)
        x++;
    if (r % 4 == 2)
        y++;
    if (r % 4 == 3)
        x--;
    return (lastChange(mmap, y, x));
}

std::vector<std::vector<int>> bbm::MapGen::myStarts(
        std::vector<std::vector<int>> mmap)
{
    mmap[1][1] = bbm::Entites::BLANK;
    if (twoGood(mmap, 1, 1) < 2)
        mmap = cleanStart(mmap, 1, 1);
    mmap[1][mmap[0].size() - 2] = bbm::Entites::BLANK;
    if (twoGood(mmap, 1, mmap[0].size() - 2) < 2)
        mmap = cleanStart(mmap, 1, mmap[0].size() - 2);
    mmap[mmap.size() - 2][1] = bbm::Entites::BLANK;
    if (twoGood(mmap, mmap.size() - 2, 1) < 2)
        mmap = cleanStart(mmap, mmap.size() - 2, 1);
    mmap[mmap.size() - 2][mmap[0].size() - 2] = bbm::Entites::BLANK;
    if (twoGood(mmap, mmap.size() - 2, mmap[0].size() - 2) < 2)
        mmap = cleanStart(mmap, mmap.size() - 2, mmap[0].size() - 2);
    return (mmap);
}

std::vector<std::vector<int>> bbm::MapGen::createBreakable(
        std::vector<std::vector<int>> mmap)
{
    int i = 0;
    int j = 0;
    int r;

    srand(time(NULL));
    while (j != mmap.size()) {
        while (i != mmap[j].size()) {
            r = rand() % 10;
            if (mmap[j][i] == bbm::Entites::BLANK && (r != 1 & r != 2 & r != 3))
                mmap[j][i] = bbm::Entites::BREAKABLE_BLOCK;
            i++;
        }
        i = 0;
        j++;
    }
    return (myStarts(mmap));
}

std::vector<int> bbm::MapGen::myAddLine(unsigned long size)
{
    std::vector<int> tmp;
    unsigned long i = 0;

    while (i != size + 2)
    {
        tmp.push_back(bbm::Entites::UNBREAKABLE_BLOCK);
        i++;
    }
    return (tmp);
}