//
// Created by חי כרמי on 13/02/2024.
//

#include "MyMain.h"
#include "Date.h"
#include "player.h"
#include "sqlite3.h"

enum {
    Login = 1, sign_up
};
enum {
    pplayer = 1, field_manger
};


void MyMain::print_Menu_login_registration() {
    cout << "Please choose one of the following option" << endl;
    cout << "1.	Login  " << endl;
    cout << "2. sign up" << endl;
}

void MyMain::print_Menu_player_field_manger() {
    cout << "Please choose one of the following option" << endl;
    cout << "1. player  " << endl;
    cout << "2. field manger" << endl;
}

MyMain::MyMain() {
    string name;
    long id;
    string Address;
    long phone_number;
    Date Birthday;
    char gender;
    long password;
    int day;
    int month;
    int year;

    int choice = 0;
    do {
        print_Menu_player_field_manger();
        cin >> choice;

        switch (choice) {
            case pplayer: {
                int choice_login_or_signup = 0;
                do {


                    print_Menu_login_registration();
                    cin >> choice_login_or_signup;
                    switch (choice_login_or_signup) {
                        case Login: {
                            cout << "enter your id number " << endl;
                            cin >> id;
                            cout << "enter your password " << endl;
                            cin >> password;
                            break;
                        }
                        case sign_up: {
                            cout << "enter your name " << endl;
                            cin >> name;
                            cout << "enter your id number " << endl;
                            cin >> id;
                            cout << "enter your Address " << endl;
                            cin >> Address;
                            cout << "enter your phone_number " << endl;
                            cin >> phone_number;
                            cout<<"enter your gender (m/f)"<<endl;
                            cin>>gender;
                            cout << "enter your Birthday day " << endl;
                            cin >> day;
                            cout << "enter your Birthday month " << endl;
                            cin >> month;
                            cout << "enter your Birthday year " << endl;
                            cin >> year;
                            Date Birthday(day, month, year);
                            Player player1(name, id, Address, phone_number,gender, Birthday);
                            player1.print_player();
                            break;

                        }

                    }

                } while (choice_login_or_signup > 2);
            }
            case field_manger: {
                cout << "enter your name " << endl;
                cin >> name;
                cout << "enter your id number " << endl;
                cin >> id;
                cout << "enter your Address " << endl;
                cin >> Address;
                cout << "enter your phone_number " << endl;
                cin >> phone_number;
                cout << "enter your Birthday day " << endl;
                cin >> day;
                cout << "enter your Birthday month " << endl;
                cin >> month;
                cout << "enter your Birthday year " << endl;
                cin >> year;
                Date Birthday(day, month, year);

            }
        }
    } while (choice > 2);
}



