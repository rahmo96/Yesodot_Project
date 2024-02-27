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



static bool IsValidIsraeliID(const string& israeliID);
static int GetDouble(long i);
bool checkLogin(sqlite3* db, const string& id, const string& password);
template<typename T>
T build_user() {
        std::string name;
        long id;
        std::string Address;
        long phone_number;
        char gender;
        string bd;
        string password;
        std::cout << "enter your name " << std::endl;
        std::cin >> name;
        std::cout << "enter your id number " << std::endl;
        std::cin >> id;
        std::cout << "enter your Address " << std::endl;
        std::cin >> Address;
        std::cout << "enter your phone_number " << std::endl;
        std::cin >> phone_number;
        std::cout << "enter your gender (m/f)" << std::endl;
        std::cin >> gender;
        cout<<"enter your date of birth"<<endl;
        cin>>bd;
        Date birthday;
        birthday.setDateFromString(bd);
        cout<<"enter your password"<<endl;
        cin>>password;


        T player1(name, id, Address, phone_number, gender,birthday, password);
        player1.print();
        return player1;
    }
void player_menu();

int P_insert_to_DB(Player &p);


int FM_insert_to_DB(Field_manager &p);







#endif //FUNCTIONS_H
