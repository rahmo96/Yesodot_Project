//
// Created by jacob on 13/02/2024.
//

#ifndef YESODOT_PROJECT_FIELD_H
#define YESODOT_PROJECT_FIELD_H
#include <iostream>
#include <string>
#include "nlohmann/json.hpp"

using namespace nlohmann;
using namespace std;

class Field {
private:
    friend class Functions;
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
    Field operator=(const Field &other);
    bool operator != (const Field &other);

    //Send it to json
    void to_json(json& j) const;
    //Get it from json
    void from_json(const json& j);

};


#endif //YESODOT_PROJECT_FIELD_H
