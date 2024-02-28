//
// Created by חי כרמי on 13/02/2024.
//

#ifndef YESODOT_PROJECT_MYMAIN_H
#define YESODOT_PROJECT_MYMAIN_H
#include <iostream>
#include <map>
using namespace std;

class MyMain {
public:
    void print_Menu_login_registration();
    MyMain();    // Class constructor
    void print_Menu_player_field_manger();
//Clears the buffer
static void clear_the_buffer() {
        while (getchar() != '\n') {
        }
    }

    void runMenu();
    static void print_Menu(const std::map<int, std::string>& menuOptions);

    static void loginMenu();
    static void P_login();
    static void FM_login();
    void retrieve_field_managers_from_db();
};


#endif //YESODOT_PROJECT_MYMAIN_H
