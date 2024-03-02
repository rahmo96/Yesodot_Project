//
// Created by חי כרמי on 20/02/2024.
//

#ifndef YESODOT_PROJECT_USER_H
#define YESODOT_PROJECT_USER_H

#include <iostream>
#include <string>
#include "Date.h"
#include "sqlite3.h"
#include "Booked.h"


using namespace std;
class User {
    protected:
    string name;
    long id;
    string Address;
    long phone_number;
    char gender;
    Date b_day;
    //Username and password
    string passowrd;


public:
    User(string name, long id, string address, long phone_num,char gender,Date b_day,string password);

    User(const User &user);

    User():b_day(){};

    //Setters
    void Set_Name();
    void Set_phone_number();
    void Set_password();
    void Set_Address();


    //Getters
    long Get_id() { return id; }
    string Get_Name() { return name; }
    string Get_Address() { return Address; }
    long Get_phone_number() { return phone_number; }
    char Get_gender() { return gender; }
    string get_password() { return passowrd; }


    //Send it to json
    virtual void to_json(nlohmann::json& j);
    //Get it from json
     void from_json(const nlohmann::json& j);


    virtual void print() ;
    string date_to_string();

    //void send_name_to_DB();
    void send_name_to_DB(string name);
    void send_address_to_DB(string address);
    void send_phone_number_to_DB(long phone_num);
    void send_password_to_DB(string password);

    static nlohmann::json P_from_DB(long id);
    static nlohmann::json FM_from_DB(long id);




};

#endif //YESODOT_PROJECT_USER_H
