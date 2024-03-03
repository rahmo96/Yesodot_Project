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
    static bool checkLogin_P(sqlite3* db, const string& id, const string& password);
    static bool checkLogin_FM(sqlite3* db, const string& id, const string& password);
    static bool isIdInDatabase(long id);
    template<typename T>
    static T build_user() {
        string name;
        long id;
        string Address;
        long phone_number;
        char gender;
        string bd;
        string password;
        cout << "enter your name " <<  endl;
        cin >> name;
        getline(std::cin, name);
        do {
            cout << "Enter your id number: "<< endl;
            cin >> id;

            // Validate the ID
            if (!IsValidIsraeliID(to_string(id))) {
                cout << "Invalid ID. Please enter a valid ID number." << endl;
                continue; // Restart the loop to get a new ID
            }

            // Check if the ID is already in use
            if (isIdInDatabase(id)) {
                cout << "This ID is already in use. Please enter another one." << endl;
            }

        } while (!IsValidIsraeliID(to_string(id)) || isIdInDatabase(id));

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

    static int P_insert_to_DB(Player &fm);

    static int FM_insert_to_DB(Field_manager &fm);








};










#endif //FUNCTIONS_H
