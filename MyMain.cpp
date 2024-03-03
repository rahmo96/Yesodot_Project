#include <iostream>
#include <map>
#include "MyMain.h"
#include <sqlite3.h>
#include "Field_manager.h"
#include <sqlite3.h>
#include "Field_manager.h"
#include "MyMain.h"
#include "Functions.h"

void MyMain::print_Menu(const std::map<int, std::string> &menuOptions) {
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
    cout << "Enter your id:" << endl;
    cin >> id;
    cout << "Enter your password:" << endl;
    cin >> password;
    if (Functions::checkLogin_P(db, to_string(id), password)) {
        cout << "Login successful" << endl;
        Player p = Player::build_from_DB(id);

        cout << "Favorites size after construction: " << p.favorites.get_size() << endl;

        return p;

    } else {
        cout << "Login failed" << endl;
    };
    sqlite3_close(db);
    exit(0);
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
                                    p.favorites.print();
                                    break;
                                case 2:
                                    cout << "Book field" << endl;
                                    player_menu_booking(p, Field_manager::field_managers);
                                    p.update_to_DB();
                                    break;
                                case 3:
                                    cout << "Cancel field" << endl;
                                    player_menu_cancel(p, Field_manager::field_managers);
                                    break;
                                case 4:
                                    cout << "Rate field" << endl;
                                    player_rating_booking(p);


                                    break;
                                case 5:
                                    cout << "Profile" << endl;
                                    menu_profile<Player>(p);
                                    break;
                                case 6:
                                    cout << "Booked fields" << endl;
                                    p.booked.print_booked_fields(p.Get_id());
                                    break;
                                case 7:
                                    cout << "Exiting..." << endl;
                                    return 0;
                                default:
                                    cout << "Invalid choice. Please try again." << endl;
                            }

                        } while (true);
                        break;
                    }
                    case 2: {
                        Player p = Functions::build_user<Player>();
                        Functions::P_insert_to_DB(p);
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
                        Field_manager fm;
                        fm = FM_login();
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
                                case 1: {
                                    std::cout << "Adding a new field..." << std::endl;
                                    Field field = Field::add_field();
                                    fm.field.push_back(field);
                                    fm.update_to_DB();
                                    Field_manager::field_managers.push_back(&fm);
                                }
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
                                case 1: {
                                    std::cout << "Adding a new field..." << std::endl;
                                    Field field = Field::add_field();
                                    fm->field.push_back(field);
                                    fm->update_to_DB();
                                    break;
                                }
                                case 2: {
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
                                    break;
                                }
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
                        break;
                    }
                    case 3:
                        break;
                    default:
                        std::cout << "Invalid choice. Please try again." << std::endl;
                }
                break;
            }
            case 3:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
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


//Menus
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
    cout << "Enter the number of the city: ";
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
            cout << "Enter the number of the field: ";
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
                cout << "Enter the number of the day: ";
                cin >> dayChoice;

                // Validate and process user choice for day
                if (dayChoice >= 1 && dayChoice <= 5) {
                    int dayIndex = dayChoice - 1;

                    // Display available hours for booking on the chosen day
                    cout << "Choose an hour (8-19): ";
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
                            p.favorites += chosenField;
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
    for (int i = 0; i < Field_manager::counter; ++i) {
        for (int j = 0; j < p.favorites.get_size(); ++j) {
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
            if (field_managers[choice - 1]->cancel_field_booking(p.Get_id())) {
                cout << "Field booking canceled." << endl;
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
            {3, [](UserType &u) { cout << "Going back..." << endl; /* Logout */ }},
    };

    int choice;
    do {
        cout << "Choose an option:" << endl;
        cout << "1. View your profile" << endl;
        cout << "2. Edit your profile" << endl;
        cout << "3. back" << endl;
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
        cout << "Choose a field:" << endl;
        for (size_t i = 0; i < field_book.size(); ++i) {
            cout << i + 1 << ". " << field_book[i] << endl;
        }
        cout << "Enter the number of the fild: ";
        cin >> fieldChoice;
    } while (!(fieldChoice >= 1 && fieldChoice <= static_cast<int>(field_book.size())));
    cout<<"enter the rat fild of (1-5) "<<field_book[fieldChoice-1]<<endl;
    int star_rat;
    cin>>star_rat;
    for (int i = 0; i < p.booked.booked_fields.size(); ++i) {
        string name_fild = p.booked.booked_fields[i].get_field_name();
        if (book==p.booked.booked_fields[i].get_field_name()){
            index=i;
        }

    }
    p.booked.booked_fields[index].Rating_change(star_rat);
    p.booked.booked_fields[index].print_rating();


}






