//
// EPITECH PROJECT, 2018
// base of generation
// File description:
// base of generation
//

#include "mapgen.hpp"
#include <fstream>

int bbm::MapGen::myTrad(char c)
{
    if (c == '*')
        return (bbm::Entites::BLANK);
    if (c == 'x')
        return (bbm::Entites::UNBREAKABLE_BLOCK);
    else
        return (bbm::Entites::BLANK);
}

std::vector<std::vector<int>> bbm::MapGen::generateMap(std::string path)
{
    std::vector<std::vector<int>> mmap;
    std::vector<int> tmp;
    std::string stock;
    std::fstream fs;
    int i = 0;

    fs.open(path, std::fstream::in);
    while (getline(fs, stock)) {
        if (i == 0)
            mmap.push_back(myAddLine(stock.size()));
        tmp.push_back(bbm::Entites::UNBREAKABLE_BLOCK);
        i = 0;
        while (i != stock.size())
            tmp.push_back(myTrad(stock[i++]));
        tmp.push_back(bbm::Entites::UNBREAKABLE_BLOCK);
        mmap.push_back(tmp);
        tmp.clear();
    }
    mmap.push_back(mmap[0]);
    fs.close();
    return(bbm::MapGen::createBreakable(mmap));
}