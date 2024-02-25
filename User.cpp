//
// Created by חי כרמי on 20/02/2024.
//

#include "User.h"

User::User(const User &user) {

    this->name = user.name;
    this->id = user.id;
    this->phone_number = user.phone_number;
    this->Birthday = user.Birthday;
    this->Address = user.Address;
}

User::User(string name, long id, string address, long phone_num, Date birthdy,Field *fild) {
    this->name = name;
    this->id = id;
    this->phone_number = phone_num;
    this->Birthday = birthdy;
    this->Address = address;
    this->field=fild;




}

void User::print_user() {
    cout << "the name is:" << this->name << endl;
    cout << "the id is:" << id << endl;
    cout << "the Address is:" << Address << endl;
    cout << "the phone num is:" << phone_number << endl;
    cout << "the Birthday is:";
    Birthday.print();


}

Field *User::copy_arr_fild() {
    Field *new_fild =new Field[this->field->get_size()];
    for (int i = 0; i < this->field->get_size(); ++i) {
        new_fild[i]=field[i];
    }

    return new_fild;
}

