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
    long id;
    string Address;
    long phone_number;
    char gender;
    Date b_day;
    string mail;
    //Username and password
    string user_name;
    string passowrd;


public:
    User(string name, long id, string address, long phone_num,char gender,Date b_day);

    User(const User &user);

    void Set_Name(string name) { this->name = name; }
    void Set_phone_number(long phne_num) { this->phone_number = phne_num; }
    void Set_mail(string mail) { this->mail =mail; }
    void Set_gander(char gander) { this->gender =gander; }
    void Set_user_name(string user_name) { this->user_name =user_name; }

   virtual void print_user() ;


};

#endif //YESODOT_PROJECT_USER_H
