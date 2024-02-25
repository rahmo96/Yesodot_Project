//
// Created by חי כרמי on 20/02/2024.
//

#ifndef YESODOT_PROJECT_USER_H
#define YESODOT_PROJECT_USER_H

#include <iostream>
#include <string>
#include "Date.h"
#include "Field.h"
#include "Functions.h"

using namespace std;
class User {

protected:
    string name;
    long id;
    string Address;
    long phone_number;
    Date Birthday;
    string passowrd;
    char gender;
    Field *field;



public:
    User(string namme, long id, string address, long phone_num, char gander ,Date birthdy);

    User(const User &user);

    void Set_Name(string name) { this->name = name; }
    void Set_phone_number(long phne_num) { this->phone_number = phne_num; }
    void Set_Birthday(Date Birthday) { this->Birthday =Birthday; }
    void Set_gander(char gander) { this->gender =gander; }
    Field* copy_arr_fild();

   virtual void print() ;


};

#endif //YESODOT_PROJECT_USER_H
