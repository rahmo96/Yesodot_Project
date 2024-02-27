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
public:
    Field();
    Field(const Field &other);
    Field(string field_name,string field_type,string field_city);
    string get_field_name() const {return field_name;};
    string get_field_type() const {return field_type;};
    string get_field_city() const {return field_city;}
    void print();
    Field &operator=(const Field &other);
    bool operator != (const Field &other);

};


#endif //YESODOT_PROJECT_FIELD_H
