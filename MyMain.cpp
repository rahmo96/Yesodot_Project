//
// Created by חי כרמי on 13/02/2024.
//

#include "MyMain.h"
#include "Date.h"
#include "player.h"
#include "sqlite3.h"
#include "Functions.h"
#include <Field_manager.h>
#include <string>
using namespace std;



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
    sqlite3 *db;

    string name;
    long id;
    string Address;
    long phone_number;
    Date Birthday;
    string password;
    int day;
    int month;
    int year;
    char gander='f';

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
                            cout << "Enter your ID number: ";
                            cin >> id;
                            cout << "Enter your password: ";
                            cin >> password;

                            int rc = sqlite3_open("Test player data DB.db", &db);
                            if (rc) {
                                cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
                                sqlite3_close(db);
                                break;
                            }

                            string sql = "SELECT id FROM Users WHERE ID=" + to_string(id) + " AND Password=" +(password);
                            char* errorMsg;
                            rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &errorMsg);
                            if (rc != SQLITE_OK) {
                                cerr << "SQL error: " << errorMsg << endl;
                                sqlite3_free(errorMsg);
                            } else {
                                cout << "Login successful!" << endl;
                            }

                            sqlite3_close(db);
                            break;
                        }
                        case sign_up: {
                            cout << "enter your name " << endl;
                            cin >> name;
                            cout << "enter your id number " << endl;
                            cin >> id;
                            while (!check_ID(id)) {
                                cout << "ID num must be 9 digits thanks\n";
                                cin >> id;

                            }
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
                            Field *field = new Field[1];
                            field[0]("sport.com", "foot ball", "ashdod");
                            field[1]("sporttttttt.com", "foot ballllll", "ashdodddddd");
                            field[0].print();
                            field->set_size(1);

                            Player *player1 = new Player(name, id, Address, phone_number, gander ,Birthday, field);
                            player1->print();
                            break;

                        }
                        default:
                            break;


                    }

                } while (choice_login_or_signup > 2 || choice_login_or_signup < 1);

            }
                if (choice == 99) {
                    case field_manger: {
                        cout << "enter your name " << endl;
                        cin >> name;
                        cout << "enter your id number " << endl;
                        cin >> id;
                        while (!check_ID(id)) {
                            cout << "ID num must be 9 digits thanks\n";
                            cin >> id;
                        }

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
                        break;
                    }
                }
            default:
                break;
        }
    } while (choice > 2 || choice < 1);

}



