//
// Created by חי כרמי on 13/02/2024.
//

#include "Date.h"

using namespace std;
#include "Date.h"
#include <ctime>
#include <iostream>



Date::Date() { // בחירת מחדל
    today();
}


void Date::today() { //פונקציה שמקבלת תאריך של היום
    std::time_t rawtime;
    std::tm* timeinfo;
    std::time(&rawtime);
    timeinfo = std::localtime(&rawtime);
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



void Date::Print_Date(){
    cout << day << "/" << month << "/" << year <<endl;
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
    if (day > 29 && (month == 4 || month == 6 || month == 9 || month == 11 || month == 2 ))
        return false;
    else if ( day > 30 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
        return false;
    else
        return true;
}







void Date::print() {
    cout<<day<<"/"<<month<<"/" <<year<< endl;

}



