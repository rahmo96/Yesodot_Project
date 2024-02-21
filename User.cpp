//
// Created by חי כרמי on 20/02/2024.
//

#include "User.h"

User::User(const User &user) {

    this->name = user.name;
    this->id = user.id;
}

User::User(string name, long id, string address, long phone_num, Date birthdy) {
    this->name = name;
    this->id = id;
    this->phone_number = phone_num;
    this->Birthday = birthdy;
    this->Address = address;
}

void User::print_user() {
    cout << "the name is:" << this->name << endl;
    cout << "the id is:" << id << endl;
    cout << "the Address is:" << Address << endl;
    cout << "the phone num is:" << phone_number << endl;
    cout << "the Birthday is:";
    Birthday.print();


}