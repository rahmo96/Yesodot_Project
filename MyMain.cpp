#include <iostream>
#include <map>
#include "MyMain.h"

#include "Functions.h"

 void MyMain::print_Menu(const std::map<int, std::string>& menuOptions) {
    for (const auto& [key, value] : menuOptions) {
        std::cout << key << ". " << value << std::endl;
    }
}

Player MyMain::P_login() {
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
        Player p =Player::build_from_DB(id);

        return p;

    }else{
        cout<<"Login failed"<<endl;
    };
    sqlite3_close(db);
    exit(0);
}
Field_manager MyMain::FM_login() {
    sqlite3* db;
    int rc = sqlite3_open("Test player data DB.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        exit(1);
    }

    long id;
    string password;
    cout << "Enter your id:" << endl;
    cin >> id;
    cout << "Enter your password:" << endl;
    cin >> password;

    if (Functions::checkLogin_FM(db, to_string(id), password)) {
        cout << "Login successful" << endl;
        Field_manager fm = Field_manager::build_from_DB(id);
        sqlite3_close(db);
        return fm;
    } else {
        cout << "Login failed" << endl;
        sqlite3_close(db);
        exit(1);
    }
}

#include <sqlite3.h>
#include "Field_manager.h"
#include <sqlite3.h>
#include "Field_manager.h"
#include "MyMain.h"


int MyMain::runMenu() {
    vector<Field_manager*> all_field_managers;
    //retrieve_field_managers_from_db();
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
                    case 1:{
                        Player p= P_login();
                        int choice;
                        do {
                            cout << "Choose one of the following options:" << endl;
                            cout << "1. Favorites" << endl;
                            cout << "2. Book field" << endl;
                            cout << "3. Cancel field" << endl;
                            cout << "4. Rate field" << endl;
                            cout << "5. Profile" << endl;
                            cout << "6. Booked fields" << endl;
                            cout << "7. Exit" << endl;
                            cin >> choice;

                            switch (choice) {
                                case 1:
                                    cout << "Favorites" << endl;
                                    p.f.print();
                                    break;
                                case 2:
                                    cout << "Book field" << endl;
                                    player_menu_booking(p, all_field_managers);
                                    p.update_to_DB();
                                    break;
                                case 3:
                                    cout << "Cancel field" << endl;
                                    player_menu_cancel(p, all_field_managers);
                                    break;
                                case 4:
                                    cout << "Rate field" << endl;
                                    // Add code to handle Rate field
                                    break;
                                case 5:
                                    cout << "Profile" << endl;
                                    menu_profile<Player>(p);
                                    break;
                                case 6:
                                    cout << "Booked fields" << endl;
                                    // Add code to handle Booked fields
                                    break;
                                case 7:
                                    cout << "Exiting..." << endl;
                                    return 0;
                                default:
                                    cout << "Invalid choice. Please try again." << endl;
                            }

                        } while (true);
                        break;}
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
                    case 1:{
                        Field_manager fm=FM_login();
                        int choice;
                        bool exitMenu = false;

                        while (!exitMenu) {
                            // Display menu options
                            std::cout << "Field Manager Menu" << std::endl;
                            std::cout << "1. Add Field" << std::endl;
                            std::cout << "2. Remove Field" << std::endl;
                            std::cout << "3. Profile" << std::endl;
                            std::cout << "4. Closed Hours in Field" << std::endl;
                            std::cout << "5. Back" << std::endl;
                            std::cout << "Enter your choice: ";

                            // Get user choice
                            std::cin >> choice;

                            // Process user choice
                            switch (choice) {
                                case 1:{
                                    std::cout << "Adding a new field..." << std::endl;
                                    Field field = Field::add_field();
                                    fm.field.push_back(field);
                                    fm.update_to_DB();}
                                    break;
                                case 2:
                                    std::cout << "Removing a field..." << std::endl;

                                    // Remove field logic
                                    break;
                                case 3:
                                    std::cout << "Viewing profile..." << std::endl;
                                    menu_profile<Field_manager>(fm);
                                    break;
                                case 4:
                                    std::cout << "Viewing closed hours in field..." << std::endl;
                                    // Closed hours logic
                                    break;
                                case 5:
                                    std::cout << "Going back..." << std::endl;
                                    exitMenu = true;
                                    break;
                                default:
                                    std::cout << "Invalid choice. Please try again." << std::endl;
                                    break;
                            }
                        }
                        break;}
                    case 2:{
                        Field_manager *fm= new Field_manager();
                        *fm =Functions::build_user<Field_manager>();
                        Functions::FM_insert_to_DB(*fm);
                        all_field_managers.push_back(fm);
                        int choice;
                        bool exitMenu = false;

                        while (!exitMenu) {
                            // Display menu options
                            std::cout << "Field Manager Menu" << std::endl;
                            std::cout << "1. Add Field" << std::endl;
                            std::cout << "2. Remove Field" << std::endl;
                            std::cout << "3. Profile" << std::endl;
                            std::cout << "4. Closed Hours in Field" << std::endl;
                            std::cout << "5. Back" << std::endl;
                            std::cout << "Enter your choice: ";

                            // Get user choice
                            std::cin >> choice;

                            // Process user choice
                            switch (choice) {
                                case 1:{
                                    std::cout << "Adding a new field..." << std::endl;
                                    Field field = Field::add_field();
                                    fm->field.push_back(field);
                                    fm->update_to_DB();
                                    break;}
                                case 2:{
                                    std::cout << "Removing a field..." << std::endl;
                                    cout << "Enter the name of the field you want to remove: ";
                                    string name;
                                    cin >> name;
                                    for (int i = 0; i < fm->field.size(); i++) {
                                        if (fm->field[i].get_field_name() == name) {
                                            fm->field.erase(fm->field.begin() + i);
                                            break;
                                        }
                                    }
                                    break;}
                                case 3:
                                    std::cout << "Viewing profile..." << std::endl;
                                    menu_profile<Field_manager>(*fm);
                                    break;
                                case 4:
                                    std::cout << "Viewing closed hours in field..." << std::endl;
                                    // Closed hours logic
                                    break;
                                case 5:
                                    std::cout << "Going back..." << std::endl;
                                    exitMenu = true;
                                    break;
                                default:
                                    std::cout << "Invalid choice. Please try again." << std::endl;
                                    break;
                            }
                        }
                        break;}
                    case 3:
                        break;
                    default:
                        std::cout << "Invalid choice. Please try again." << std::endl;
                }
                break;}
                break;
            case 3:
                return 0;
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


    // Print the JSON data for debugging
        std::cout << "JSON data: " << json_data << std::endl;

    // Parse JSON data and create Field_manager object
        nlohmann::json j;
        try {
            j = nlohmann::json::parse(json_data);
        } catch (const nlohmann::json::parse_error& e) {
            std::cerr << "JSON parse error: " << e.what() << std::endl;
            // Handle the error appropriately, such as skipping this data or logging the error
            continue;
        }

        Field_manager* fm = new Field_manager();
        fm->from_json(j);

        // Parse JSON data and create Field_manager object
        nlohmann::json j1 = nlohmann::json::parse(json_data);
        Field_manager* fm1 = new Field_manager();
        fm1->from_json(j);

        // Add Field_manager object to your collection
        Field_manager::field_managers.push_back(fm1);
    }

    if (rc != SQLITE_DONE) {
        std::cerr << "Error retrieving data: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}


//Menus
void MyMain::player_menu_booking(Player &p,vector<Field_manager*> field_managers) {
    std::vector<std::string> cities;
    std::cout << "Choose from which city you want to book a field:" << std::endl;

    // Collect unique cities from the fields
    for (int i = 0; i < Field_manager::counter; ++i) {
        for (int j = 0; j < field_managers[i]->field.size(); ++j) {
            std::string city = field_managers[i]->field[j].get_field_city();
            if (std::find(cities.begin(), cities.end(), city) == cities.end()) {
                cities.push_back(city);
            }
        }

    }

    // Display the unique cities
    for (size_t i = 0; i < cities.size(); ++i) {
        std::cout << i + 1 << ". " << cities[i] << std::endl;
    }

    // Get user choice for city
    int cityChoice;
    std::cout << "Enter your choice for city: ";
    std::cin >> cityChoice;

    // Validate and process user choice for city
    if (cityChoice >= 1 && cityChoice <= static_cast<int>(cities.size())) {
        std::string chosenCity = cities[cityChoice - 1];
        // Display available days for booking in the chosen city
        std::cout << "Available days for booking in " << chosenCity << ":" << std::endl;
        for (int day = 0; day < 5; ++day) { // Assuming 5 days (0 to 4)
            if (!field_managers[day]->is_day_occupied(chosenCity, day)) {
                std::cout << day << ": "; // You might want to convert day to a weekday name
                // Display available hours for booking on this day
                for (int hour = 8; hour < 20; ++hour) { // Assuming hours are from 8 to 19
                    if (!field_managers[hour-8]->is_hour_occupied(chosenCity, day, hour)) {
                        std::cout << hour << ":00 ";
                    }
                }
                std::cout << std::endl;
            }
        }

        // Get user choice for day
        int dayChoice;
        std::cout << "Choose a day: ";
        std::cin >> dayChoice;

        // Validate and process user choice for day
        if (dayChoice >= 0 && dayChoice < 5 && !field_managers[dayChoice]->is_day_occupied(chosenCity, dayChoice)) {
            // Get user choice for hour
            int hourChoice;
            std::cout << "Choose an hour: ";
            std::cin >> hourChoice;

            // Validate and process user choice for hour
            if (hourChoice >= 8 && hourChoice < 20 && !field_managers[hourChoice-8]->is_hour_occupied(chosenCity, dayChoice, hourChoice)) {
                // Process the booking for the chosen city, day, and hour
                field_managers[hourChoice-8]->book_field_in_city_at_day_hour(p, chosenCity, dayChoice, hourChoice);

                // Ask the user if they want to add the field to their favorites
                char choice_favorites;
                std::cout << "Do you want to add this field to your favorites? (y/n) ";
                std::cin >> choice_favorites;

                // Validate the user's choice
                while (choice_favorites != 'y' && choice_favorites != 'Y' && choice_favorites != 'n' && choice_favorites != 'N') {
                    std::cout << "Wrong input. Do you want to add this field to your favorites? (y/n) ";
                    std::cin >> choice_favorites;
                }

                // If the user wants to add the field to their favorites, add it
                if (choice_favorites == 'y' || choice_favorites == 'Y') {
                    // Find the index of the chosen city in the cities vector
                    int index = cityChoice - 1;
                    Field chosen(field_managers[index]->field[index].get_field_name(), field_managers[index]->field[index].get_field_type() ,field_managers[index]->field[index].get_field_city());
                    p.field.push_back(chosen);
                    p.f += chosen;
                    std::cout << "Field added to favorites." << std::endl;
                }
            } else {
                std::cout << "Invalid hour choice. Please try again." << std::endl;
            }
        } else {
            std::cout << "Invalid day choice. Please try again." << std::endl;
        }
    } else {
        std::cout << "Invalid city choice. Please try again." << std::endl;
    }
}

void MyMain::player_menu_cancel(Player &p,vector<Field_manager*> field_managers) {
    // Find all fields booked by the player
    std::vector<Field> temp_field;
    for (int i = 0; i < Field_manager::counter; ++i) {
        for (int j = 0; j < p.f.get_size(); ++j) {
            if (field_managers[i]->is_field_booked_by(p.Get_id())) {
                temp_field.push_back(field_managers[j]->field[i]);
            }

        }

    }

    // Display the booked fields
    if (temp_field.empty()) {
        std::cout << "You have no booked fields to cancel." << std::endl;
    } else {
        std::cout << "Choose a field to cancel:" << std::endl;
        for (size_t i = 0; i < temp_field.size(); ++i) {
            std::cout << i + 1 << ". ";
            temp_field[i].print();
        }

        // Get user choice
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Validate and process user choice
        if (choice >= 1 && choice <= static_cast<int>(temp_field.size())) {
            if (field_managers[choice-1]->cancel_field_booking(p.Get_id())){
                cout << "Field booking canceled." <<endl;
            } else {
                std::cout << "Failed to cancel field booking." << std::endl;
            }
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}

template<typename UserType>
void MyMain::menu_profile(UserType &u) {
    cout << "You are logged in as " << u.Get_Name() << endl;

    // Define the menu options and corresponding actions
    std::map<int, std::function<void(UserType &)>> menu = {
            {1, [](UserType &u) { u.print(); }},
            {2, [](UserType &u) { profile_menu_2(u); }},
            {3, [](UserType &u) { cout << "Logging out..." << endl; /* Logout */ }},
    };

    int choice;
    do {
        cout << "Choose an option:" << endl;
        cout << "1. View your profile" << endl;
        cout << "2. Edit your profile" << endl;
        cout << "3. Logout" << endl;
        cin >> choice;

        // Execute the corresponding action based on the user's choice
        auto it = menu.find(choice);
        if (it != menu.end()) {
            it->second(u);
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3); // Corrected loop condition
}



void MyMain::profile_menu_2(User &u) {
    cout << "Choose what to edit:" << endl;

    // Define the menu options and corresponding actions
    std::map<int, std::function<void(User &)>> menu = {
            {1, [](User &u) { u.Set_Name(); }},
            {2, [](User &u) { u.Set_Address(); }},
            {3, [](User &u) { u.Set_phone_number(); }},
            {4, [](User &u) { u.Set_password(); }},
            {5, [](User &u) { cout << "Going back..." << endl; /* Go back */ }},
    };

    int choice;
    do {
        cout << "1. Name" << endl;
        cout << "2. Address" << endl;
        cout << "3. Phone number" << endl;
        cout << "4. Password" << endl;
        cout << "5. Back" << endl;
        cin >> choice;

        // Execute the corresponding action based on the user's choice
        auto it = menu.find(choice);
        if (it != menu.end()) {
            it->second(u);
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);
}

