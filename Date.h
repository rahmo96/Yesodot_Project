//
// Created by חי כרמי on 13/02/2024.
//

#ifndef YESODOT_PROJECT_DATE_H
#define YESODOT_PROJECT_DATE_H


class Date {

private:
    int day;
    int month;
    int year;

public:
    void today();
    Date();
    Date(int day,int month,int year);
    bool setDay(int day); //setDay
    bool setMonth(int month);
    bool setYear(int year);
    void Print_Date();
    void Print_month();
    int days_count();
    bool is_meubar();
    bool check_valid_date();
    void print();

};




#endif //YESODOT_PROJECT_DATE_H
