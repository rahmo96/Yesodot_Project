//
// Created by raha1 on 03/04/2024.
//
#include "Clear_Screen.h"

void Clear ::clear_screen() {
    // ANSI escape code to clear screen
    std::cout << "\033[2J\033[1;1H";
}