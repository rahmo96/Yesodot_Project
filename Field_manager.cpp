//
// Created by חי כרמי on 21/02/2024.
//

#include "Field_manager.h"
#include <vector>

Field_manager::Field_manager(string name, long id, string address, long phone_num,char gender,Date b_day,string passowrd,vector<Field> field1)
: User(name, id,  address,  phone_num,gender,b_day,passowrd) , field(field1) {}


void Field_manager::print() {
        for ( auto &field : field) {
            User::print();
            field.print();
        }
        }

Field_manager &Field_manager::operator+=(const Field_manager &fieldManager) {

    field.insert(field.end(), fieldManager.field.begin(), fieldManager.field.end());
    return *this;
}

