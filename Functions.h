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
#include <cctype>


class Functions{
public:
    static bool IsValidIsraeliID(const string& israeliID);
    static int GetDouble(long i);
    static bool isNumber(const string &s);
    static bool checkLogin_P(sqlite3* db, const string& id, const string& password);
    static bool checkLogin_FM(sqlite3* db, const string& id, const string& password);
    static bool isIdInDatabase(long id);
    template<typename T>
    static T build_user() {
        string name;
        long id;
        string t_id;
        string Address;
        string t_phone_number;
        long phone_number;
        char gender;
        string t_birthday;
        string password;

        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, name);

        do {
            cout << "Enter your ID number: \n";
            getline(cin, t_id);

            if (isNumber(t_id)) {
                id = stol(t_id, nullptr, 10);

                if (!IsValidIsraeliID(t_id)) {
                    cout << "Invalid ID. Please enter a valid ID number." << endl;
                    continue; // Restart the loop to get a new ID
                }

                if (isIdInDatabase(id)) {
                    cout << "This ID is already in use. Please enter another one." << endl;
                    continue; // Restart the loop to get a new ID
                }

                break; // Exit the loop if ID is valid and not in use
            }
            else {
                cout << "Invalid ID. Please enter a valid ID number." << endl;
            }

        } while (true);

        cout << "Enter your Address: \n";
        getline(cin, Address);

        do {
            cout << "Enter your phone number: ";
            getline(cin, t_phone_number);
            if (t_phone_number.length() != 10 || !isNumber(t_phone_number)) {
                cout << "Invalid phone number. Please enter a 10-digit number." << endl;
            }
        } while (t_phone_number.length() != 10 || !isNumber(t_phone_number));
        phone_number = stol(t_phone_number);

        do {
            cout << "Enter your gender (m/f):\n ";
            cin >> gender;
            gender = tolower(gender);
        } while (gender != 'm' && gender != 'f');

        do {
            cout << "Enter your date of birth (DD.MM.YYYY): \n";
            getline(cin, t_birthday);
        } while (t_birthday.length() != 10);
        Date birthday;
        birthday.setDateFromString(t_birthday);

        cout << "Enter your password: ";
        cin >> password;

        T player1(name, id, Address, phone_number, gender, birthday, password);
        player1.print(); // Assuming T has a print method
        return player1;
    }

    static string trim(const string& str);
    static int P_insert_to_DB(Player &fm);

    static int FM_insert_to_DB(Field_manager &fm);








};










#endif //FUNCTIONS_H
