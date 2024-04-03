//
// Created by raha1 on 03/04/2024.
//
#include "Clear_Screen.h"

void Clear ::clear_screen() {
    // ANSI escape code to clear screen
#ifdef _WIN32
    std::system("cls");
#else
    // Assume Unix-like system
        std::system("clear");
#endif
}