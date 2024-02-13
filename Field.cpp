//
// Created by jacob on 13/02/2024.
//

#include "Field.h"
#include <iostream>

Field::Field(string field_type, string field_city) {
    this-> field_city = field_city;
    this -> field_type = field_type;
}

Field::Field(const Field &other) {
    this -> field_type = other.field_type;
    this -> field_city = other.field_city;
}

string Field::get_field_city() {
    return field_city;
}

string Field::get_field_type() {
    return field_type;
}

void Field::print() {
    cout<<"The field sport type is: " << field_type << " " << endl;
    cout<<"The field location is: " << field_city << endl;
}