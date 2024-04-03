//
// Created by חי כרמי on 13/02/2024.
//

#ifndef YESODOT_PROJECT_DATE_H
#define YESODOT_PROJECT_DATE_H
#include <string>
#include "nlohmann/json.hpp"
#include "Clear_Screen.h"

using namespace std;

class Date {

private:
    int day;
    int month;
    int year;

public:
    void today();
    Date();
    Date(int day,int month,int year);
    bool setDateFromString(const string& date);

    //setters
    bool setDay(int day);
    bool setMonth(int month );
    bool setYear(int year);

    //getters
    int get_Day() const {return day;}
    int get_Month() const {return month;}
    int get_Year() const {return year;}

    string toSqlDate();
    void Print_month();
    int days_count();
    bool is_meuberet();
    bool check_valid_date();
    void print();

    //send it to json
    void to_json(nlohmann::json& j) const;
    //get it from json
    void from_json(const nlohmann::json& j);

};




#endif //YESODOT_PROJECT_DATE_H
