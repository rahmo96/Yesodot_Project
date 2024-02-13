//
// Created by חי כרמי on 13/02/2024.
//

#include "MyMain.h"
#include "Date.h"

enum {
    Login = 1, sign_up
};

void MyMain::print_Menu_login_registration() {
    cout << "Please choose one of the following option" << endl;
    cout << "1.	Login  " << endl;
    cout << "2. sign up" << endl;
}
void MyMain::print_Menu_player_field_manger() {
    cout << "Please choose one of the following option" << endl;
    cout << "1. player  " << endl;
    cout << "2. field_manger" << endl;
}

MyMain::MyMain() {
    string name;
    string id;
    string Address;
    long phone_number;
    Date Birthday;

    int choice = 0;
    int choice2=0;
    do {
        print_Menu_player_field_manger();

        print_Menu_login_registration();

        cin >> choice;

        switch (choice) {
            case Login: {
//TODO:make a login
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
                cout << "enter your Birthday " << endl;
            }
        }
    } while (choice < 2);
}



