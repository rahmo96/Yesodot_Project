//
// Created by jacob on 13/02/2024.
//

#include "Field.h"
#include <iostream>
#include "string"

Field::Field(string field_name,string field_type, string field_city) {
    this->field_name = field_name;
    this-> field_city = field_city;
    this -> field_type = field_type;
}

Field::Field(const Field &other) {
    this -> field_name = other.field_name;
    this -> field_type = other.field_type;
    this -> field_city = other.field_city;
}



void Field::print() {
    cout<<field_name<<endl;
    cout<<"_______"<<endl;
    cout<<"The field sport type is: " << field_type << " " << endl;
    cout<<"Located in: " << field_city << endl;
    cout<<"_______"<<endl;
}



Field Field::operator=(const Field &other) {
    this->field_name=other.field_name;
    this->field_city=other.field_city;
    this->field_type=other.field_type;
    return *this;
}




Field::Field() {
    this->field_name="";
    this->field_type="";
    this->field_city="";

}

bool Field::operator!=(const Field &other) {
    if (field_name!=other.field_name)
        return true;
    if (field_city!=other.field_city)
        return true;
    if (field_type!=other.field_type)
        return true;

    return false;

}

void Field::to_json(json &j) const {

    j={
            {field_name,"Field name"},
            {field_type,"Field type"},
            {field_city,"Field city"}
    };

}

void Field::from_json(const json &j) {

    field_name = j.at("Field name");
    field_type = j.at("Field type");
    field_city = j.at("Field city");

}



