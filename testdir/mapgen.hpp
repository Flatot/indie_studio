//
// EPITECH PROJECT, 2018
// map gen
// File description:
// map generator
//

#pragma once

#include <iostream>
#include <vector>

namespace bbm {
    class Ia;

    enum Entites{
        BLANK = 0,
        PLAYER_1 = 1,
        PLAYER_2 = 2,
        PLAYER_3 = 4,
        PLAYER_4 = 8,
        UNBREAKABLE_BLOCK = 16,
        BREAKABLE_BLOCK = 32,
        BOMB = 64,
        BONUS = 128
    };

    class PlayerCurse {
    public:
        PlayerCurse(int y, int x);
        ~PlayerCurse();
        int _y;
        int _x;
        std::vector<std::vector<int>> moveAllPlayer(
                int dir, std::vector<std::vector<int>>);
    };

    class MapGen {
    public:
        static std::vector<std::vector<int>> generateMap(std::string path);
    private:
        static std::vector<std::vector<int>> createBreakable(std::vector<std::vector<int>> mmap);
        static int myTrad(char c);
        static std::vector<int> myAddLine(unsigned long size);
        static std::vector<std::vector<int>> myStarts(std::vector<std::vector<int>> mmap);
        static std::vector<std::vector<int>> cleanStart(std::vector<std::vector<int>> mmap, int y, int x);
        static std::vector<std::vector<int>> lastChange(std::vector<std::vector<int>> mmap, int y, int x);
        static bool checkLeft(std::vector<std::vector<int>> mmap, int y, int x);
        static bool checkRight(std::vector<std::vector<int>> mmap, int y, int x);
        static bool checkDown(std::vector<std::vector<int>> mmap, int y, int x);
        static bool checkUp(std::vector<std::vector<int>> mmap, int y, int x);
        static bool checkAll(std::vector<std::vector<int>> mmap, int y, int x, int dir);
        static bool checkAllBreak(std::vector<std::vector<int>> mmap, int y, int x, int dir);
        static int twoGood(std::vector<std::vector<int>> mmap, int y, int x);
        static std::vector<std::vector<int>> changeAllBlank(std::vector<std::vector<int>> mmap, int y, int x, int dir);
    };
}