//
// EPITECH PROJECT, 2018
// map gen
// File description:
// map generator
//

#include <iostream>
#include <vector>
#include <fstream>
#include "mapgen.hpp"
#include "header_curses.hpp"

int affMap(std::vector<std::vector<int>> mmap)
{
    int i = 0;
    int j = 0;

    while (j != mmap.size())
    {
        while (i != mmap[j].size())
        {
            if (mmap[j][i] == bbm::Entites::BLANK)
                std::cout << " ";
            if (mmap[j][i] == bbm::Entites::PLAYER_1 ||
                    mmap[j][i] == bbm::Entites::PLAYER_2 ||
                    mmap[j][i] == bbm::Entites::PLAYER_3 ||
                    mmap[j][i] == bbm::Entites::PLAYER_4)
                std::cout << "P";
            if (mmap[j][i] == bbm::Entites::UNBREAKABLE_BLOCK)
                std::cout << "X";
            if (mmap[j][i] == bbm::Entites::BREAKABLE_BLOCK)
                std::cout << "0";
            i++;
        }
        std::cout << "|" << std::endl;
        i = 0;
        j++;
    }
    return (0);
}

int main() {
    std::vector<std::vector<int>> mmap;
    mmap = bbm::MapGen::generateMap("other.txt");
    //affMap(mmap);
    MyCurses::myGameLaunch(mmap);
    return (0);
}