//
// Created by raha1 on 24/02/2024.
//


using namespace std;
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include "User.h"
#include "Player.h"
#include "Field_manager.h"
#include "Date.h"
#include "sqlite3.h"

class Functions{
public:
    static bool IsValidIsraeliID(const string& israeliID);
    static int GetDouble(long i);
    bool checkLogin_P(sqlite3* db, const string& id, const string& password);
    bool checkLogin_FM(sqlite3* db, const string& id, const string& password);
    template<typename T>
    T build_user() {
        string name;
        long id;
        string Address;
        long phone_number;
        char gender;
        string bd;
        string password;
        cout << "enter your name " <<  endl;
        cin >> name;
        cout << "enter your id number " <<  endl;
        cin >> id;
        if (!IsValidIsraeliID( to_string(id))) {
            do {
                cout << "please enter a valid id number" <<endl;
                cin >> id;
            } while (!IsValidIsraeliID( to_string(id)));
        }
        cout << "enter your Address " <<  endl;
        cin >> Address;
        cout << "enter your phone_number " <<  endl;
        cin >> phone_number;
        cout << "enter your gender (m/f)" <<  endl;
        cin >> gender;
        if (gender != 'm' && gender != 'M' && gender != 'f' && gender != 'F') {
            do {
                cout << "please enter a valid gender" <<  endl;
                cin >> gender;
            } while (gender != 'm' && gender != 'M' && gender != 'f' && gender != 'F');

        }
        cout<<"enter your date of birth"<<endl;
        cin>>bd;
        Date birthday;
        if (!birthday.setDateFromString(bd)){
            do {
                cout << "please enter a valid date" << endl;
                cin >> bd;
            } while (!birthday.setDateFromString(bd));
        }
        cout<<"enter your password"<<endl;
        cin>>password;
        T player1(name, id, Address, phone_number, gender,birthday, password);
        player1.print();
        return player1;
    }

    int P_insert_to_DB(Player &p);

    int FM_insert_to_DB(Field_manager &p);

//Menus
    void player_menu_1();
    void player_menu_favorites(Player &p);
    void player_menu_booking(Player &p,Field_manager *f);
    void player_menu_cancel(Player &p,Field_manager *fm);
    void player_menu_profile(Player &p);
    void profile_menu_1(User &u);
    void profile_menu_2(User &u);
    void profile_menu_3();
    void profile_menu_4();
    void profile_menu_5();
    void player_menu_rate(Player &p,Field_manager *fm);
    void player_menu_booked_fields(Player &p);




};










#endif //FUNCTIONS_H
