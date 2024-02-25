//
// Created by jacob on 13/02/2024.
//

#ifndef YESODOT_PROJECT_FIELD_H
#define YESODOT_PROJECT_FIELD_H

#include <iostream>
#include <string>

using namespace std;

class Field {
private:
    string field_name;
    string field_type;
    string field_city;
    int size;
public:
    Field();

    Field(const Field &other);

    Field(const string field_name, const string field_type, const string field_city);

    string get_field_name();

    string get_field_type();

    string get_field_city();

    void print();

    Field &operator=(const Field &other);

    int get_size() { return this->size; }
    void set_size(int suze){ this->size=suze;}

//    void operator[](int index) {
//        std::cout << "Calling operator[] with index: " << index << std::endl;
//    }
    void operator()(const string field_name, const string field_type, const string field_city);

};





#endif //YESODOT_PROJECT_FIELD_H
