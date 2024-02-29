//
// Created by חי כרמי on 13/02/2024.
//

#ifndef YESODOT_PROJECT_MYMAIN_H
#define YESODOT_PROJECT_MYMAIN_H
#include <iostream>
#include <map>
#include <string>
#include "Player.h"
#include "Field_manager.h"
#include "sqlite3.h"
using namespace std;

class MyMain {
public:
    friend class Functions;
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
    Player P_login();
    static void FM_login();
    void retrieve_field_managers_from_db();

    //Menus
    static int player_menu_1(Player &p,Field_manager *fm);
    void player_menu_favorites(Player &p);
    static void player_menu_booking(Player &p, Field_manager *f);
    static void player_menu_cancel(Player &p, Field_manager *fm);
    static void player_menu_profile(Player &p);
    void profile_menu_1(User &u);
    static void profile_menu_2(User &u);
    void profile_menu_3();
    void profile_menu_4();
    void profile_menu_5();
    void player_menu_rate(Player &p,Field_manager *fm);
    void player_menu_booked_fields(Player &p);
};


#endif //YESODOT_PROJECT_MYMAIN_H
