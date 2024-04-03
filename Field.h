//
// Created by jacob on 13/02/2024.
//

#ifndef YESODOT_PROJECT_FIELD_H
#define YESODOT_PROJECT_FIELD_H
#include <iostream>
#include <string>
#include "nlohmann/json.hpp"
#include "Clear_Screen.h"

using namespace nlohmann;
using namespace std;

class Field {
private:
    friend class Functions;
    string field_name;
    string field_type;
    string field_city;
    float rating=0;
    int counter_rating=0;
    long occupied[5][12];
    string description;
public:
    Field();
    Field(const Field &other);
    Field(string field_name,string field_type,string field_city,string description);
//    ~Field();
    string get_field_name() const {return field_name;};
    string get_field_type() const {return field_type;};
    string get_field_city() const {return field_city;}
    float get_rating() const {return rating;}

    void print() const;
    Field operator=(const Field &other);
    bool operator != (const Field &other);
    bool operator == (const Field &other);

    //Send it to json
    void to_json(json& j) const;
    //Get it from json
    void from_json(const json& j);
    void Rating_change(float rat);

    static Field add_field();
    Field remove_field();
    void print_rating() const;


    //Getters
    long get_occupied(int row, int col) const {return occupied[row][col];}
    //Setters
    void set_occupied(int row, int col, long id) {occupied[row][col] = id;}

    //checks
    bool is_field_booked_by(long id) const;

    bool cancel_booking(long id);
    void close_field(int choice2, int startHour,int endHour);

    };


#endif //YESODOT_PROJECT_FIELD_H
