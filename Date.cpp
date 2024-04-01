//
// Created by חי כרמי on 13/02/2024.
//

#include "Date.h"
#include <sstream>
#include "nlohmann/json.hpp"

using namespace std;
using namespace nlohmann;
#include "Date.h"
#include <ctime>
#include <iostream>
#include <sstream>



Date::Date() { // בחירת מחדל
    today();
}


void Date::today() { //פונקציה שמקבלת תאריך של היום
    time_t rawtime;
    tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    day = timeinfo->tm_mday;
    month = timeinfo->tm_mon + 1;
    year = timeinfo->tm_year + 1900;
}


Date::Date(int day,int month,int year)
{
    if (!(setDay(int (day))) || !(setMonth(int (month))) || !(setYear(int (year))) && check_valid_date())
        today();
    else {
        this->day = day;
        this->month = month;
        this->year = year;
    }
}

bool Date::setDateFromString(const string& date) {
    stringstream ss(date);
    char delim;

    ss >> day >> delim >> month >> delim >> year;

    if (!check_valid_date()){
        cout << "invalid date" << endl;
        return false;
    }
    return true;
}


bool Date::setDay(int day) {
    if (day < 1 || day > 31)
        return false;
    return true;

}


bool Date::setMonth(int month ) { //בדיקת חודש
    if (month < 1 || month > 12)
        return false;
    return true;
}


bool Date::setYear(int year) { //בדיקת שנה
    if (year < 0)
        return false;
    return true;
}

string Date:: toSqlDate() {
    ostringstream ss;
    ss << year << "-"
       << (month < 10 ? "0" : "") << month << "-"
       << (day < 10 ? "0" : "") << day;
    return ss.str();
}

void Date::Print_month() {
    switch (month) {
        case 1:
            cout << " January" << endl;
            break;
        case 2:
            cout << " February" << endl;
            break;
        case 3:
            cout << " March" << endl;
            break;
        case 4:
            cout << " April" << endl;
            break;
        case 5:
            cout << " May" << endl;
            break;
        case 6:
            cout << " June" << endl;
            break;
        case 7:
            cout << " July" << endl;
            break;
        case 8:
            cout << " August" << endl;
            break;
        case 9:
            cout << " September" << endl;
            break;
        case 10:
            cout << " October" << endl;
            break;
        case 11:
            cout << " November" << endl;
            break;
        case 12:
            cout << " December" << endl;
            break;
    }
}

int Date::days_count() {
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if (month == 2 && !is_meuberet())
        return 28;
    else
        return 29;
}



bool Date::is_meuberet() {
    if (year % 4 != 0)
        return false;

    if (year % 100 == 0 && year % 400 != 0)
        return false;

    return true;
}

bool Date::check_valid_date() {
    if (day > 31 ||
        (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) ||
        (day > 28 && month == 2)) // This doesn't account for leap years
    {
        return false;
    }
    else {
        return true;
    }
}



void Date::print() {
    cout<<day<<"/"<<month<<"/" <<year<< endl;
}

void Date::to_json(json &j) const {

    j={
            {"day",day},
            {"month",month},
            {"year",year}
    };
}

void Date::from_json(const json &j) {
    day = j.at("day").get<int>();
    month = j.at("month").get<int>();
    year = j.at("year").get<int>();
}





