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
    MyMain();    // Class constructor

    int runMenu();
    static void print_Menu(const std::map<int, std::string>& menuOptions);

    Player P_login();
    Field_manager FM_login();
    void retrieve_field_managers_from_db();

    //Menus
    static int player_menu_1();
    static void player_menu_booking(Player &p, vector<Field_manager*> field_managers);
    static void player_rating_booking(Player &p);

    static void player_menu_cancel(Player &p,vector<Field_manager*> field_managers);
    void P_menu_profile(Player &p);

    void FM_menu_profile(Field_manager &fm);
    static void P_profile_menu_2(Player &p);
    void FM_profile_menu_2(Field_manager &fm);

    //Field manager menus
    void field_manager_menu();
    void remove_field(Field_manager &fm,vector<Field_manager*>& field_managers);

    void
    bookField(Player &p, Field_manager *fm, const Field &chosenField, const string &chosenCity, int dayIndex,
              int startHour,
              int endHour);

    void addToFavorites(Player &p, const Field &chosenField);

    void closed_by_manager(Field_manager &fm, vector<Field_manager *> &field_managers);
};


#endif //YESODOT_PROJECT_MYMAIN_H
