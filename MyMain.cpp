#include <iostream>
#include <map>
#include "MyMain.h"
#include "Functions.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

void MyMain::print_Menu(const std::map<int, std::string> &menuOptions) {
    std::cout << BLUE << "Menu Options:" << RESET << std::endl;
    for (const auto &[key, value]: menuOptions) {
        std::cout << key << ". " << value << std::endl;
    }
}

Player MyMain::P_login() {
    sqlite3 *db;
    int rc = sqlite3_open("Test player data DB.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        exit(1);
    }
    long id;
    string password;
    do {
        cout << CYAN << "Login as Player" << RESET << endl;
        cout << "Enter your ID:" << endl;
        cin >> id;
        cout << "Enter your password:" << endl;
        cin >> password;

        if (!(Functions::checkLogin_P(db, to_string(id), password))) {
            cout << RED << "Login failed. Please try again." << RESET << endl;
        }
    } while (!(Functions::checkLogin_P(db, to_string(id), password)));

    cout << GREEN << "Login successful" << RESET << endl;
    Player p = Player::build_from_DB(id);
    sqlite3_close(db);
    return p;


}

Field_manager MyMain::FM_login() {
    sqlite3 *db;
    int rc = sqlite3_open("Test player data DB.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        exit(1);
    }

    long id;
    string password;
    do {


        cout << CYAN << "Login as Field Manager" << RESET << endl;
        cout << "Enter your ID:" << endl;
        cin >> id;
        cout << "Enter your password:" << endl;
        cin >> password;

        if (!(Functions::checkLogin_FM(db, to_string(id), password))) {
            cout << RED << "Login failed. Please try again." << RESET << endl;
        }
    } while ((!(Functions::checkLogin_FM(db, to_string(id), password))));
    cout << GREEN << "Login successful" << RESET << endl;
    Field_manager fm = Field_manager::build_from_DB(id);
    sqlite3_close(db);
    return fm;

}

vector<Field_manager *> Field_manager::field_managers;

int MyMain::runMenu() {

    sqlite3 *db;

    std::map<int, std::string> playerFieldManagerMenu = {
            {1, "Player"},
            {2, "Field Manager"},
            {3, "Exit"}
    };

    std::map<int, std::string> playerMenu = {
            {1, "Login"},
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
        int choice, choice1, choice2, choice3;
        std::cin >> choice;

        switch (choice) {
            case 1:
                currentMenu = playerMenu;
                print_Menu(currentMenu);
                cin >> choice1;
                switch (choice1) {
                    case 1: {
                        Player p = P_login();
                        int choice;
                        do {
                            cout <<CYAN "Choose one of the following options:" <<RESET<< endl;
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
                                    cout <<CYAN<< "Favorites" <<RESET<< endl;
                                    p.f.print();
                                    break;
                                case 2:
                                    cout << CYAN<<"Book field" << RESET<<endl;
                                    player_menu_booking(p, Field_manager::field_managers);
                                    p.update_to_DB();
                                    break;
                                case 3:
                                    cout <<CYAN<< "Cancel field"<<RESET << endl;
                                    player_menu_cancel(p, Field_manager::field_managers);
                                    break;
                                case 4:
                                    cout <<CYAN<< "Rate field" <<RESET << endl;
                                    // Add code to handle Rate field
                                    player_rating_booking(p);

                                    break;
                                case 5:
                                    cout <<CYAN<< "Profile" <<RESET << endl;
                                    P_menu_profile(p);
                                    break;
                                case 6:
                                    cout <<CYAN << "Booked fields" <<RESET<< endl;
                                    p.booked.print_booked_fields(p.Get_id());
                                    break;
                                case 7:
                                    cout<<CYAN << "Exiting..." <<RESET << endl;
                                    return 0;
                                default:
                                    cout<<RED << "Invalid choice. Please try again."<<RESET << endl;
                            }

                        } while (true);
                        break;
                    }
                    case 2: {
                        Player p = Functions::build_user<Player>();
                        Functions::P_insert_to_DB(p);
                        do {
                            cout <<CYAN "Choose one of the following options:" <<RESET<< endl;
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
                                    cout <<CYAN<< "Favorites" <<RESET<< endl;
                                    p.f.print();
                                    break;
                                case 2:
                                    cout << CYAN<<"Book field" << RESET<<endl;
                                    player_menu_booking(p, Field_manager::field_managers);
                                    p.update_to_DB();
                                    break;
                                case 3:
                                    cout <<CYAN<< "Cancel field"<<RESET << endl;
                                    player_menu_cancel(p, Field_manager::field_managers);
                                    break;
                                case 4:
                                    cout <<CYAN<< "Rate field" <<RESET << endl;
                                    // Add code to handle Rate field
                                    player_rating_booking(p);

                                    break;
                                case 5:
                                    cout <<CYAN<< "Profile" <<RESET << endl;
                                    P_menu_profile(p);
                                    break;
                                case 6:
                                    cout <<CYAN << "Booked fields" <<RESET<< endl;
                                    p.booked.print_booked_fields(p.Get_id());
                                    break;
                                case 7:
                                    cout<<CYAN << "Exiting..." <<RESET << endl;
                                    return 0;
                                default:
                                    cout<<RED << "Invalid choice. Please try again."<<RESET << endl;
                            }

                        } while (true);
                        break;
                    }
                    case 3:
                        currentMenu = playerFieldManagerMenu;
                        break;
                    default:
                        std::cout << "Invalid choice. Please try again." << std::endl;
                }
                break;
            case 2: {
                currentMenu = fieldManagerMenu;
                print_Menu(currentMenu);
                cin >> choice2;
                switch (choice2) {
                    case 1: {
                        Field_manager fm = FM_login();
                        int choice;
                        bool exitMenu = false;

                        while (!exitMenu) {
                            // Display menu options
                            std::cout<< CYAN << "Field Manager Menu" << RESET << std::endl;
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
                                case 1: {
                                    std::cout<< CYAN << "Add a new field."<< RESET << std::endl;
                                    Field field = Field::add_field();
                                    fm.field.push_back(field);
                                    fm.update_to_DB();
                                    Field_manager::field_managers.push_back(&fm);
                                }
                                    break;
                                case 2:
                                    std::cout<< CYAN << "Removing a field."<< RESET << std::endl;
                                    remove_field(fm, Field_manager::field_managers);
                                    // Remove field logic
                                    break;
                                case 3:
                                    std::cout<< CYAN << "Viewing profile..."<<  RESET << std::endl;
                                    FM_menu_profile(fm);
                                    break;
                                case 4:
                                    std::cout<< CYAN << "Viewing closed hours in field..."<< RESET << std::endl;
                                    closed_by_manager(fm, Field_manager::field_managers);
                                    break;
                                case 5:
                                    std::cout<< CYAN << "Going back..."<< RESET << std::endl;
                                    exitMenu = true;
                                    break;
                                default:
                                    std::cout<< RED << "Invalid choice. Please try again."<< RESET << std::endl;
                                    break;
                            }
                        }
                        break;
                    }
                    case 2: {
                        Field_manager *fm = new Field_manager();
                        *fm = Functions::build_user<Field_manager>();
                        Functions::FM_insert_to_DB(*fm);
                        Field_manager::field_managers.push_back(fm);
                        int choice;
                        bool exitMenu = false;

                        while (!exitMenu) {
                            // Display menu options
                            std::cout<<CYAN << "Field Manager Menu"<< RESET << std::endl;
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
                                case 1: {
                                    std::cout<<CYAN << "Adding a new field..."<< RESET << std::endl;
                                    Field field = Field::add_field();
                                    fm->field.push_back(field);
                                    fm->update_to_DB();
                                    break;
                                }
                                case 2: {
                                    std::cout<<CYAN << "Remove a field."<< RESET << std::endl;
                                    remove_field(*fm, Field_manager::field_managers);
                                    break;
                                }
                                case 3:
                                    std::cout<<CYAN << "Viewing profile."<< RESET << std::endl;
                                    FM_menu_profile(*fm);
                                    break;
                                case 4:
                                    std::cout<<CYAN << "Viewing closed hours in field..." << RESET << std::endl;
                                    closed_by_manager(*fm, Field_manager::field_managers);
                                    break;
                                case 5:
                                    std::cout<<CYAN << "Going back..."<< RESET << std::endl;
                                    exitMenu = true;
                                    break;
                                default:
                                    std::cout<<RED << "Invalid choice. Please try again."<< RESET << std::endl;
                                    break;
                            }
                        }
                        break;
                    }
                    case 3:
                        break;
                    default:
                        std::cout<<RED << "Invalid choice. Please try again."<< RESET << std::endl;
                }
                break;
            }
                break;
            case 3:
                return 0;
            default:
                std::cout<<RED << "Invalid choice. Please try again."<< RESET << std::endl;
        }
    }
}
MyMain::MyMain() {
    retrieve_field_managers_from_db();
    runMenu();
}


void MyMain::retrieve_field_managers_from_db() {
    sqlite3 *db;
    int rc = sqlite3_open("Test player data DB.db", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    const char *sql = "SELECT Class_data FROM [Field_Manager_Accounts]";
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        // Retrieve JSON data from the current row
        const char *json_data = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));

        // Parse JSON data and create Field_manager object
        nlohmann::json j;
        try {
            j = nlohmann::json::parse(json_data);
        } catch (const nlohmann::json::parse_error &e) {
            std::cerr << "JSON parse error: " << e.what() << std::endl;
            // Handle the error appropriately, such as skipping this data or logging the error
            continue;
        }



        // Create a new Field_manager object and add it to your collection
        Field_manager *fm = new Field_manager();
        fm->from_json(j);
        Field_manager::field_managers.push_back(fm);
    }

    if (rc != SQLITE_DONE) {
        std::cerr << "Error retrieving data: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}


//PLAYER!!
void MyMain::player_menu_booking(Player &p, vector<Field_manager *> field_managers) {
    string days[5] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
    vector<string> cities;

    // Collect unique cities from the fields
    for (const auto &fm: field_managers) {
        for (const auto &field: fm->field) {
            string city = field.get_field_city();
            if (find(cities.begin(), cities.end(), city) == cities.end()) {
                cities.push_back(city);
            }
        }
    }

    // Display the unique cities
    cout << "Choose a city:" << endl;
    for (size_t i = 0; i < cities.size(); ++i) {
        cout << i + 1 << ". " << cities[i] << endl;
    }

    // Get user choice for city
    int cityChoice;
    cout << "Enter the number of the city: " << endl;
    cin >> cityChoice;

    // Validate and process user choice for city
    if (cityChoice >= 1 && cityChoice <= static_cast<int>(cities.size())) {
        string chosenCity = cities[cityChoice - 1];
        vector<Field> availableFields;

        // Find available fields in the chosen city
        for (const auto &fm: field_managers) {
            for (const auto &field: fm->field) {
                if (field.get_field_city() == chosenCity) {
                    availableFields.push_back(field);
                }
            }
        }

        if (!availableFields.empty()) {
            // Display the available fields for booking in the chosen city
            cout << "Choose a field:" << endl;
            for (size_t i = 0; i < availableFields.size(); ++i) {
                cout << i + 1 << ". " << availableFields[i].get_field_name() << endl;
            }

            // Get user choice for field
            int fieldChoice;
            cout << "Enter the number of the field: " << endl;
            cin >> fieldChoice;

            // Validate user choice for field
            if (fieldChoice >= 1 && fieldChoice <= static_cast<int>(availableFields.size())) {
                Field chosenField = availableFields[fieldChoice - 1];

                // Display available days for booking
                cout << "Choose a day:" << endl;
                for (size_t i = 0; i < 5; ++i) {
                    cout << i + 1 << ". " << days[i] << endl;
                }

                // Get user choice for day
                int dayChoice;
                cout << "Enter the number of the day: " << endl;
                cin >> dayChoice;

                // Validate and process user choice for day
                if (dayChoice >= 1 && dayChoice <= 5) {
                    int dayIndex = dayChoice - 1;

                    // Display available hours for booking on the chosen day
                    cout << "Choose an hour (8:00 - 19:00): ";
                    int hourChoice;
                    cin >> hourChoice;

                    // Validate and process user choice for hour
                    if (hourChoice >= 8 && hourChoice <= 19) {
                        int checked = 0;
                        // Process the booking for the chosen field, day, and hour
                        for (auto &fm: field_managers) {
                            if (fm->field[checked] == chosenField) {
                                long playerId = p.Get_id();
                                fm->book_field_in_city_at_day_hour(playerId, chosenCity, dayIndex, hourChoice);

                                // Add the booked field to the player's booked fields
                                p.booked.booked_fields.push_back(chosenField);

                                // Update the occupied slots in the booked field
                                p.booked.setOccupied_slots(dayIndex, hourChoice - 8, playerId);

                                // Update the database
                                fm->update_to_DB();

                                break;
                            }
                            checked++;
                        }

                        // Ask user if they want to add the booked field to their favorites
                        char addToFavorites;
                        cout << "Add this field to your favorites? (y/n): ";
                        cin >> addToFavorites;

                        // Validate user choice for adding to favorites
                        if (addToFavorites == 'y' || addToFavorites == 'Y') {
                            p.booked.booked_fields.push_back(chosenField);
                            p.f += chosenField;
                            p.update_to_DB();
                            cout << "Field added to favorites." << endl;
                        } else {
                            cout << "Field not added to favorites." << endl;
                        }
                    } else {
                        cout << "Invalid hour choice. Please try again." << endl;
                    }
                } else {
                    cout << "Invalid day choice. Please try again." << endl;
                }
            } else {
                cout << "Invalid field choice. Please try again." << endl;
            }
        } else {
            cout << "No available fields in " << chosenCity << "." << endl;
        }
    } else {
        cout << "Invalid city choice. Please try again." << endl;
    }
}


void MyMain::player_menu_cancel(Player &p, vector<Field_manager *> field_managers) {
    // Find all fields booked by the player
    std::vector<Field> temp_field;
    for (auto fm: field_managers) {
        for (auto field: fm->field) {
            if (field.is_field_booked_by(p.Get_id())) {
                temp_field.push_back(field);
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
            Field field = temp_field[choice - 1];
            Field_manager *manager = nullptr;
            for (auto fm: field_managers) {
                if (fm->field_contains(field)) {
                    manager = fm;
                    break;
                }
            }
            if (manager && manager->cancel_field_booking(p.Get_id(), field)) {
                cout << "Field booking canceled." << endl;
                // Remove the canceled field from the player's booked fields
                p.booked.remove_booking(p.Get_id());
            } else {
                std::cout << "Failed to cancel field booking." << std::endl;
            }
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}


//template<typename UserType>
//void MyMain::menu_profile(UserType &u) {
//    cout << GREEN << "You are logged in as " << u.Get_Name() << RESET << endl;
//
//    // Define the menu options and corresponding actions
//    std::map<int, std::function<void(UserType &)>> menu = {
//            {1, [](UserType &u) { u.print(); }},
//            {2, [](UserType &u) { profile_menu_2(u); }},
//            {3, [](UserType &u) { cout << CYAN << "Going back..." << RESET << endl; /* back */ }},
//    };
//
//    int choice;
//    do {
//        cout << CYAN << "Choose an option:" << RESET << endl;
//        cout << "1. View your profile" << endl;
//        cout << "2. Edit your profile" << endl;
//        cout << "3. logout" << endl;
//        cin >> choice;
//
//        // Execute the corresponding action based on the user's choice
//        auto it = menu.find(choice);
//        if (it != menu.end()) {
//            it->second(u);
//        } else {
//            cout << RED << "Invalid choice. Please try again." << RESET << endl;
//        }
//    } while (choice != 3); // Corrected loop condition
//    runMenu();
//}

//void MyMain::profile_menu_2(User &u) {
//    cout << CYAN << "Choose what to edit:" << RESET << endl;
//
//    // Define the menu options and corresponding actions
//    std::map<int, std::function<void(User &)>> menu = {
//            {1, [](User &u) { u.Set_Name(); }},
//            {2, [](User &u) { u.Set_Address(); }},
//            {3, [](User &u) { u.Set_phone_number(); }},
//            {4, [](User &u) { u.Set_password(); }},
//            {5, [](User &u) { cout << CYAN << "Going back..." << RESET << endl; /* Go back */ }},
//    };
//
//    int choice;
//    do {
//        cout << "1. Name" << endl;
//        cout << "2. Address" << endl;
//        cout << "3. Phone number" << endl;
//        cout << "4. Password" << endl;
//        cout << "5. Back" << endl;
//        cin >> choice;
//
//        // Execute the corresponding action based on the user's choice
//        auto it = menu.find(choice);
//        if (it != menu.end()) {
//            it->second(u);
//        } else {
//            cout << RED << "Invalid choice. Please try again." << RESET << endl;
//        }
//    } while (choice != 7);
//}

//Field_manager
void MyMain::player_rating_booking(Player &p) {
    vector<string> field_book;
    int fieldChoice;
    string book;
    int index;
    do {
        for (int i = 0; i < p.booked.booked_fields.size(); ++i) {
            book = p.booked.booked_fields[i].get_field_name();
            if (find(field_book.begin(), field_book.end(), book) == field_book.end()) {
                field_book.push_back(book);
            }
        }
        cout << CYAN << "Choose a field:" << RESET << endl;
        for (size_t i = 0; i < field_book.size(); ++i) {
            cout << i + 1 << ". " << field_book[i] << endl;
        }
        cout << CYAN << "Enter the number of the fild: " << RESET << endl;
        cin >> fieldChoice;
    } while (!(fieldChoice >= 1 && fieldChoice <= static_cast<int>(field_book.size())));
    cout << CYAN << "Enter the rat field of (1-5) " << RESET << field_book[fieldChoice - 1] << endl;
    int star_rat;
    cin >> star_rat;
    for (int i = 0; i < p.booked.booked_fields.size(); ++i) {
        string name_fild = p.booked.booked_fields[i].get_field_name();
        if (book == p.booked.booked_fields[i].get_field_name()) {
            index = i;
        }

    }
    p.booked.booked_fields[index].Rating_change(star_rat);
    p.booked.booked_fields[index].print_rating();
}


void MyMain::remove_field(Field_manager &fm, vector<Field_manager *> &field_managers) {
    if (fm.field.empty()) {
        std::cout << "No fields to remove." << std::endl;
        return;
    }

    // Display all fields in the field manager
    std::cout << "Choose a field to remove:" << std::endl;
    for (size_t i = 0; i < fm.field.size(); ++i) {
        std::cout << i + 1 << ". " << fm.field[i].get_field_name() << " (City: " << fm.field[i].get_field_city() << ")"
                  << std::endl;
    }

    int choice;
    std::cout << "Enter the number of the field you want to remove: ";
    std::cin >> choice;

    // Validate user choice
    if (choice >= 1 && choice <= static_cast<int>(fm.field.size())) {
        // Remove the field from the field manager's vector
        fm.field.erase(fm.field.begin() + (choice - 1));
        std::cout << "Field removed successfully." << std::endl;

        // Update the field manager in the database
        fm.update_to_DB();

        // Remove the field manager from the vector of field managers
        field_managers.erase(remove(field_managers.begin(), field_managers.end(), &fm), field_managers.end());
    } else {
        std::cout << "Invalid choice. Please try again." << std::endl;
    }
}


void MyMain::P_menu_profile(Player &p) {
    cout<<GREEN << "You are logged in as " << p.Get_Name()<<RESET << endl;

    // Define the menu options and corresponding actions
    std::map<int, std::function<void(Player &)>> menu = {
            {1, [](Player &p) { p.print(); }},
            {2, [this](Player &p) { P_profile_menu_2(p); }},
            {3, [](Player &p) { cout<<CYAN << "Logging out..."<<RESET << endl; /* Logout */ }},
    };

    int choice;
    do {
        cout<<CYAN << "Choose an option:"<<RESET << endl;
        cout << "1. View your profile" << endl;
        cout << "2. Edit your profile" << endl;
        cout << "3. Logout" << endl;
        cin >> choice;

        // Execute the corresponding action based on the user's choice
        auto it = menu.find(choice);
        if (it != menu.end()) {
            it->second(p);
        } else {
            cout<<RED << "Invalid choice. Please try again."<<RESET << endl;
        }
    } while (choice != 3); // Corrected loop condition
}
void MyMain::P_profile_menu_2(Player &p) {
    cout << CYAN << "Choose what to edit:" << RESET << endl;

    // Define the menu options and corresponding actions
    std::map<int, std::function<void(User &)>> menu = {
            {1, [](User &u) { u.Set_Name(); }},
            {2, [](User &u) { u.Set_Address(); }},
            {3, [](User &u) { u.Set_phone_number(); }},
            {4, [](User &u) { u.Set_password(); }},
            {5, [](User &u) { cout<<CYAN << "Going back..." <<RESET << endl; /* Go back */ }},
    };

    int choice;
    do {
        cout << "1. Name" << endl;
        cout << "2. Address" << endl;
        cout << "3. Phone number" << endl;
        cout << "4. Password" << endl;
        cout << YELLOW << "5. Save changes" << RESET << endl;
        cout << "6. Back" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                p.Set_Name();
                break;
            case 2:
                p.Set_Address();
                break;
            case 3:
                p.Set_phone_number();
                break;
            case 4:
                p.Set_password();
                break;
            case 5:
                p.update_to_DB();
                break;
            case 6:
                // Back
                return;
            default:
                cout << RED << "Invalid choice. Please try again." << RESET << endl;
                break;
        }
    } while (true);
}

//Field Manager Profile
void MyMain:: FM_menu_profile(Field_manager &fm){
    cout<<GREEN << "You are logged in as " << fm.Get_Name()<<RESET << endl;

    // Define the menu options and corresponding actions
    std::map<int, std::function<void(Field_manager &)>> menu = {
            {1, [](Field_manager &fm) { fm.print(); }},
            {2, [this](Field_manager &fm) { FM_profile_menu_2(fm); }},
            {3, [](Field_manager &fm) { cout<<CYAN << "Logging out..."<<RESET << endl; /* Logout */ }},
    };

    int choice;
    do {
        cout<<CYAN << "Choose an option:"<<RESET << endl;
        cout << "1. View your profile" << endl;
        cout << "2. Edit your profile" << endl;
        cout << "3. Logout" << endl;
        cin >> choice;

        // Execute the corresponding action based on the user's choice
        auto it = menu.find(choice);
        if (it != menu.end()) {
            it->second(fm);
        } else {
            cout<<RED << "Invalid choice. Please try again."<<RESET << endl;
        }
    } while (choice != 3); // Corrected loop condition

}
void MyMain::FM_profile_menu_2(Field_manager &fm) {
    int choice;
    do {
        cout << "1. Name" << endl;
        cout << "2. Address" << endl;
        cout << "3. Phone number" << endl;
        cout << "4. Password" << endl;
        cout << YELLOW << "5. Save changes" << RESET << endl;
        cout << "6. Back" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                fm.Set_Name();
                break;
            case 2:
                fm.Set_Address();
                break;
            case 3:
                fm.Set_phone_number();
                break;
            case 4:
                fm.Set_password();
                break;
            case 5:
                fm.update_to_DB();
                break;
            case 6:
                // Back
                return;
            default:
                cout << RED << "Invalid choice. Please try again." << RESET << endl;
                break;
        }
    } while (true);
}
void MyMain::closed_by_manager(Field_manager &fm, vector<Field_manager *> &field_managers) {
    string days[5] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
    cout<<"which field do you want to close?"<<endl;

    for (int i = 0; i < fm.field.size(); ++i) {
        cout << i + 1 << ". " << fm.field[i].get_field_name() << " (City: " << fm.field[i].get_field_city() << ")"
             << endl;
    }
    int choice;
    cin >> choice;

    if (choice >= 1 && choice <= static_cast<int>(fm.field.size())) {
        cout<<"Which day do you want to close?"<<endl;
        for (int i = 0; i < 5; ++i) {
            cout << i + 1 << ". " << days[i] << endl;
        }
        int choice2;
        cin >> choice2;
        int startHour, endHour;
        cout<<"Which hour do you want to close?"<<endl;
        cin>>startHour;
        cout<< "Until what hour do you want to close?"<<endl;
        cin>>endHour;
        fm.field[choice - 1].close_field(choice2, startHour, endHour);

    }


}
