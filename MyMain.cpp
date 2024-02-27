//
// Created by חי כרמי on 13/02/2024.
//

#include "MyMain.h"
#include "Date.h"
#include "User.h"
#include "Player.h"
#include "sqlite3.h"
#include "Functions.h"
#include "Field_manager.h"

using namespace std;



enum {
    Login = 1, sign_up
};
enum {
    pplayer = 1, field_manger
};


void MyMain::print_Menu_login_registration() {
    cout << "Please choose one of the following option" << endl;
    cout << "1.Login  " << endl;
    cout << "2.sign up" << endl;
}

void MyMain::print_Menu_player_field_manger() {
    cout << "Please choose one of the following option" << endl;
    cout << "1.player  " << endl;
    cout << "2.field manger" << endl;
}

MyMain::MyMain() {
    sqlite3 *db;
    long id;
    string password;
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
                            bool loggedIn = false;
                            while (!loggedIn) {
                                cout << "Enter your ID number (or enter -1 to exit): ";
                                cin >> id;
                                if (id == -1) {
                                    break; // Exit the loop and the program
                                }

                                cout << "Enter your password: ";
                                cin >> password;

                                int rc = sqlite3_open("Test player data DB.db", &db);
                                if (rc) {
                                    cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
                                    sqlite3_close(db);
                                    break;
                                }

                                if (checkLogin_P(db, to_string(id), password))  // Check if the login is successful
                                    cout<<"Login successful!"<<endl;
                                else
                                    cout<<"Login failed!"<<endl;


                                sqlite3_close(db);
                            }

                            int player_coice;
                            do {
                                player_menu();
                            } while (player_coice != 7);

                            break;
                        }
                        case sign_up: {
                            Player player =build_user<Player>();
                            P_insert_to_DB(player);
                            break;
                        }
                    }
                } while (choice_login_or_signup > 2);
                break;
            }
            case field_manger: {
                Field_manager field_manager =build_user<Field_manager>();
                FM_insert_to_DB(field_manager);
                break;
            }
        }
    } while (choice > 2);
}


    