//
// Created by ryudi on 31/05/18.
//
#ifndef MYINDIE_TEST_HPP
#define MYINDIE_TEST_HPP

#include <vector>

class MyCurses {
public:
    static int myGameLaunch(std::vector<std::vector<int>> mmap);

private:
    static int mySetLoop(std::vector<std::vector<int>> mmap);
    static int myAffMapCurse(std::vector<std::vector<int>> mmap);
    static char myTradCurse(int x);
    static std::vector<std::vector<int>> gameEventsCurse(std::vector<std::vector<int>> mmap);
    static std::vector<std::vector<int>> moveCursor(
            int c, int right, int down, std::vector<std::vector<int>> mmap);
};

#endif //MYINDIE_TEST_HPP