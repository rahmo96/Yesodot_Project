//
// Created by jacob on 13/02/2024.
//

#ifndef YESODOT_PROJECT_FIELD_H
#define YESODOT_PROJECT_FIELD_H
#include <iostream>
#include <string>

class Field {
private:
    string field_type;
    string field_city;
public:
    Field(const Field &other);
    Field(string field_type,string field_city);
    string get_field_type();
    string get_field_city();
    void print();

};


#endif //YESODOT_PROJECT_FIELD_H
