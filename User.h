//
// Created by חי כרמי on 20/02/2024.
//

#ifndef YESODOT_PROJECT_USER_H
#define YESODOT_PROJECT_USER_H

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;
class User {
private:
    string name;
    string id;
    string Address;
    long phone_number;
    Date Birthday;
    string passowrd;


public:
    User(string namme, string id, string address, long phone_num, Date birthdy);

    User(const User &user);

    void Set_Name(string name) { this->name = name; }

   virtual void print_user() ;


};

#endif //YESODOT_PROJECT_USER_H
