//
// Created by חי כרמי on 20/02/2024.
//

#include "User.h"

User::User(const User &user) {

    this->name = user.name;
    this->id = user.id;
    this->phone_number = user.phone_number;
    this->Address = user.Address;
    this->gender = user.gender;
    this->b_day = user.b_day;
    //
    this->passowrd = user.passowrd;
}

User::User(string name, long id, string address, long phone_num, char gender, Date b_day, string password) {
    this->name = name;
    this->id = id;
    this->phone_number = phone_num;
    this->Address = address;
    this->gender = gender;
    this->b_day = b_day;
    this->passowrd = password;
}

void User::print() {
    cout << "the name is:" << this->name << endl;
    cout << "the id is:" << id << endl;
    cout << "the Address is:" << Address << endl;
    cout << "the phone num is:" << phone_number << endl;
    cout << "the gender is:" << gender << endl;
    cout << "the birth day is:" << date_to_string() << endl;
    }

string User::date_to_string() {
        if (b_day.check_valid_date())
            return to_string(b_day.get_Day()) + "-" + to_string(b_day.get_Month()) + "-" + to_string(b_day.get_Year());
}
