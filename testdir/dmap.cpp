//
// Created by ryudi on 01/06/18.
//

#include "Ia.hpp"
#include <curses.h>

void bbm::Ia::affDmap() {
    endwin();
    for (int j = 0; j < d_map.size(); j++) {
        for (int i = 0; i < d_map[0].size(); i++) {
            if (d_map[j][i] == 0)
                std::cout << '0';
            else if (d_map[j][i] == 1)
                std::cout << '1';
            else if (d_map[j][i] == 2)
                std::cout << '2';
        }
        std::cout << std::endl;
    }
    exit (0);
}