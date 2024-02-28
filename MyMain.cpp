#include <iostream>
#include <map>
#include "Functions.h"

 void MyMain::print_Menu(const std::map<int, std::string>& menuOptions) {
    for (const auto& [key, value] : menuOptions) {
        std::cout << key << ". " << value << std::endl;
    }
}

void MyMain::P_login() {
    sqlite3* db;
    int rc = sqlite3_open("Test player data DB.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        exit(1);
    }
    long id;
    string password;
    cout<<"Enter your id:"<<endl;
    cin>>id;
    cout<<"Enter your password:"<<endl;
    cin>>password;
    if(Functions::checkLogin_P(db, to_string(id), password)){
        cout<<"Login successful"<<endl;
    }else{
        cout<<"Login failed"<<endl;
    };
    sqlite3_close(db);
}
void MyMain::FM_login() {
    sqlite3* db;
    int rc = sqlite3_open("Test field manager data DB.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        exit(1);
    }
    long id;
    string password;
    cout<<"Enter your id:"<<endl;
    cin>>id;
    cout<<"Enter your password:"<<endl;
    cin>>password;
    if(Functions::checkLogin_FM(db, to_string(id), password)){
        cout<<"Login successful"<<endl;
    }else{
        cout<<"Login failed"<<endl;
    };
    sqlite3_close(db);
}
#include <sqlite3.h>
#include "Field_manager.h"
#include <sqlite3.h>
#include "Field_manager.h"
#include "MyMain.h"


void MyMain::runMenu() {
    vector<Field_manager*> all_field_managers;
    retrieve_field_managers_from_db();
    sqlite3 *db;

    std::map<int, std::string> playerFieldManagerMenu = {
            {1, "Player"},
            {2, "Field Manager"},
            {3, "Exit"}
    };

    std::map<int, std::string> playerMenu = {
            {1, "Login" },
            {2, "Sign up"},
            {3, "Back"}
    };

    std::map<int, std::string> fieldManagerMenu = {
            {1, "Login"},
            {2, "Sign up"},
            {3, "Back"}
    };
    std::map<int, std::string> loginMenu = {
            {1, "Player"},
            {2, "Field Manager"},
            {3, "Exit"}
    };



    std::map<int, std::string> currentMenu = playerFieldManagerMenu;

    while (true) {
        print_Menu(currentMenu);
        int choice,choice1, choice2,choice3 ;
        std::cin >> choice;

        switch (choice) {
            case 1:
                currentMenu = playerMenu;
                print_Menu(currentMenu);
                cin>>choice1;
                switch (choice1) {
                    case 1:
                        P_login();
                        break;
                    case 2:{
                        Player p=Functions::build_user<Player>();
                        Functions::P_insert_to_DB(p);
                        break;}
                    case 3:
                        currentMenu=playerFieldManagerMenu;
                        break;
                    default:
                        std::cout << "Invalid choice. Please try again." << std::endl;
                }
                break;
            case 2:{
                currentMenu = fieldManagerMenu;
                print_Menu(currentMenu);
                cin>>choice2;
                switch (choice2) {
                    case 1:
                        FM_login();
                        break;
                    case 2:{
                        Field_manager fm=Functions::build_user<Field_manager>();
                        all_field_managers.push_back(&fm);
                        Functions::FM_insert_to_DB(fm);
                        break;}
                    case 3:
                        break;
                    default:
                        std::cout << "Invalid choice. Please try again." << std::endl;
                }
                break;}
                break;
            case 3:
                return;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}

MyMain::MyMain() {
    runMenu();
}

#include <iostream>
#include <sqlite3.h>
#include <vector>
#include "Field_manager.h"

std::vector<Field_manager*> Field_manager::field_managers;

void MyMain::retrieve_field_managers_from_db() {
    sqlite3* db;
    int rc = sqlite3_open("Test player data DB.db", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    const char* sql = "SELECT Class_data FROM [Field_Manager_Accounts]";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        // Retrieve JSON data from the current row
        const char* json_data = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));

        // Parse JSON data and create Field_manager object
        nlohmann::json j = nlohmann::json::parse(json_data);
        Field_manager fm1;
        fm1.from_json(j);

        // Add Field_manager object to your collection
        Field_manager::field_managers.push_back(&fm1);
    }

    if (rc != SQLITE_DONE) {
        std::cerr << "Error retrieving data: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
