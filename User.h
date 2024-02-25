//
// Created by חי כרמי on 20/02/2024.
//

#ifndef YESODOT_PROJECT_USER_H
#define YESODOT_PROJECT_USER_H

#include <iostream>
#include <string>
#include "Date.h"
#include "Functions.h"


using namespace std;
class User {

protected:
    string name;
    long id;
    string Address;
    long phone_number;
    char gender;
    Date b_day;
    string mail;
    //Username and password
    string passowrd;


public:
    User(string name, long id, string address, long phone_num,char gender,Date b_day);

    User(const User &user);

    //Setters
    void Set_Name(string name) { this->name = name; }
    void Set_phone_number(long phne_num) { this->phone_number = phne_num; }
    void Set_mail(string mail) { this->mail =mail; }
    void Set_gender(char gender) { this->gender =gender; }


    //Getters
    long Get_id() { return id; }
    string Get_Name() { return name; }
    string Get_Address() { return Address; }
    long Get_phone_number() { return phone_number; }
    string Get_mail() { return mail; }
    char Get_gender() { return gender; }
    string get_password() { return passowrd; }


   virtual void print() ;


};

#endif //YESODOT_PROJECT_USER_H
