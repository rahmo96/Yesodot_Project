//
// Created by חי כרמי on 21/02/2024.
//

#include "Field_manager.h"
#include <vector>

Field_manager::Field_manager(string name, long id, string address, long phone_num,char gender,Date b_day,vector<Field> field1)
: User(name, id,  address,  phone_num,gender,b_day) , field(field1) {}


void Field_manager::print() {
        for ( auto &field : field) {
            field.print();
        }
        }
