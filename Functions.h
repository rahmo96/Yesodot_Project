//
// Created by raha1 on 24/02/2024.
//


using namespace std;
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include "User.h"
#include "sqlite3.h"



    static bool IsValidIsraeliID(const string& israeliID);

    static int GetDouble(long i);

    template<typename T>
    T build_user() {
        std::string name;
        long id;
        std::string Address;
        long phone_number;
        char gender;
        int day, month, year;
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
        std::cout << "enter your Birthday day " << std::endl;
        std::cin >> day;
        std::cout << "enter your Birthday month " << std::endl;
        std::cin >> month;
        std::cout << "enter your Birthday year " << std::endl;
        std::cin >> year;
        cout<<"enter your password"<<endl;
        cin>>password;
        Date Birthday(day, month, year);
        T player1(name, id, Address, phone_number, gender, Birthday, password);
        player1.print();
        return player1;
    }

template<typename T>
int insert_to_DB(T &p){
    sqlite3* db;
    int rc = sqlite3_open("Test player data DB.db", &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return rc;
    }

    const char* sql = "INSERT INTO [Users] (Name, ID, Phone_number,Address, Password) VALUES (?, ?, ?, ?, ?)";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return rc;
    }


    sqlite3_bind_text(stmt, 1, p.Get_Name().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, p.Get_id()) ;
    sqlite3_bind_int(stmt, 3, p.Get_phone_number());
    sqlite3_bind_text(stmt, 4, p.Get_Address().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, p.get_password().c_str(), -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Error inserting data: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return rc;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return rc;

}

void player_menu();

#endif //FUNCTIONS_H
