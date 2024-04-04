#include <iostream>
#include <map>
#include "MyMain.h"
#include "Functions.h"
#include <cctype>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

//initializer
vector<Field_manager *> Field_manager::field_managers;

bool is_9_digit(long id) {
    return id >= 100000000 && id <= 999999999;
}
void MyMain::print_Menu(const std::map<int, std::string> &menuOptions) {
    std::cout << BLUE << "Menu Options:" << RESET << std::endl;
    for (const auto &[key, value]: menuOptions) {
        std::cout << key << ". " << value << std::endl;
    }
}


//Login
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
            cout << CYAN << "*** Login as Player ***" << RESET << endl;
            cout << "Enter your ID: (or '0' to return to main menu)" << endl;
            do {
                cin >> id;
                if (cin.fail()){
                    cout<<RED<<"Invalid input. Please try again."<<RESET<<endl;
                    id = 1;
                    this_thread::sleep_for(chrono::seconds(2));
                    continue;
                }
                if (id == 0) {
                    Clear::clear_screen();
                    sqlite3_close(db);
                    return Player();
                }
            } while (!is_9_digit(id));

            cout << "Enter your password:" << endl;
            cin >> password;

            if (!(Functions::checkLogin_P(db, to_string(id), password))) {
                cout << RED << "Login failed. Please try again." << RESET << endl;
                this_thread::sleep_for(chrono::seconds(2));
            }
        } while ((!(Functions::checkLogin_P(db, to_string(id), password)))||!(is_9_digit(id)));
        cout << GREEN << "Login successful" << RESET << endl;
        this_thread::sleep_for(chrono::seconds(2));
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
        cout << CYAN << "*** Login as Field Manager ***" << RESET << endl;
        cout << "Enter your ID: (or '0' to return to main menu)" << endl;
        do {
            cin >> id;
            if (cin.fail()){
                cout<<RED<<"Invalid input. Please try again."<<RESET<<endl;
                id = 1;
                this_thread::sleep_for(chrono::seconds(2));
                continue;
            }
            if (id == 0) {
                Clear::clear_screen();
                sqlite3_close(db);
                return Field_manager();
            }
        } while (!is_9_digit(id));

        cout << "Enter your password:" << endl;
        cin >> password;

        if (!(Functions::checkLogin_FM(db, to_string(id), password))) {
            cout << RED << "Login failed. Please try again." << RESET << endl;
            this_thread::sleep_for(chrono::seconds(2));
        }
    } while ((!(Functions::checkLogin_FM(db, to_string(id), password)))||!(is_9_digit(id)));
    cout << GREEN << "Login successful" << RESET << endl;
    this_thread::sleep_for(chrono::seconds(2));
    Field_manager fm = Field_manager::build_from_DB(id);
    sqlite3_close(db);
    return fm;

}

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
        Clear::clear_screen();
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
            std::cout << "Invalid input. Please enter a valid integer." << std::endl;
            continue; // Continue to the next iteration of the loop
        }

        switch (choice) {
            case 1:
                currentMenu = playerMenu;
                print_Menu(currentMenu);
                cin >> choice1;
               Clear::clear_screen();
                switch (choice1) {
                    case 1: {
                        Player p = P_login();
                        if (p.Get_id() == 0){
                            currentMenu=playerFieldManagerMenu;
                            //print_Menu(currentMenu);
                            break; // Exit the switch statement
                        }
                        Clear::clear_screen();
                        int choice;
                        bool exitMenu = false;
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
;                                    Clear::clear_screen();
                                    cout <<CYAN<< "Favorites" <<RESET<< endl;
                                    p.f.print();
                                    break;
                                case 2:
                                    Clear::clear_screen();
                                    cout << CYAN<<"Book field" << RESET<<endl;
                                    player_menu_booking(p, Field_manager::field_managers);
                                    p.update_to_DB();
                                    break;
                                case 3:
                                    Clear::clear_screen();
                                    cout <<CYAN<< "Cancel field"<<RESET << endl;
                                    player_menu_cancel(p, Field_manager::field_managers);
                                    break;
                                case 4:
                                    Clear::clear_screen();
                                    cout <<CYAN<< "Rate field" <<RESET << endl;
                                    // Add code to handle Rate field
                                    player_rating_booking(p);

                                    break;
                                case 5:
                                    Clear::clear_screen();
                                    cout <<CYAN<< "Profile" <<RESET << endl;
                                    P_menu_profile(p);
                                    break;
                                case 6:
                                    Clear::clear_screen();
                                    cout <<CYAN << "Booked fields" <<RESET<< endl;
                                    p.booked.print_booked_fields(p.Get_id());
                                    break;
                                case 7:
                                    cout<<CYAN << "Exiting..." <<RESET << endl;
                                    for (auto fm : Field_manager::field_managers) {
                                        fm->FM_update_to_DB();
                                    }
                                    p.P_update_to_DB();
                                    return 0;
                                default:
                                    cout<<RED << "Invalid choice. Please try again."<<RESET << endl;
                                    Clear::clear_screen();
                                    break;
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
                                    Clear::clear_screen();
                                    cout <<CYAN<< "Favorites" <<RESET<< endl;
                                    p.f.print();
                                    break;
                                case 2:
                                    Clear::clear_screen();
                                    cout << CYAN<<"Book field" << RESET<<endl;
                                    player_menu_booking(p, Field_manager::field_managers);
                                    p.update_to_DB();
                                    break;
                                case 3:
                                    Clear::clear_screen();
                                    cout <<CYAN<< "Cancel field"<<RESET << endl;
                                    player_menu_cancel(p, Field_manager::field_managers);
                                    break;
                                case 4:
                                    Clear::clear_screen();
                                    cout <<CYAN<< "Rate field" <<RESET << endl;
                                    // Add code to handle Rate field
                                    player_rating_booking(p);

                                    break;
                                case 5:
                                    Clear::clear_screen();
                                    cout <<CYAN<< "Profile" <<RESET << endl;
                                    P_menu_profile(p);
                                    break;
                                case 6:
                                    Clear::clear_screen();
                                    cout <<CYAN << "Booked fields" <<RESET<< endl;
                                    p.booked.print_booked_fields(p.Get_id());
                                    break;
                                case 7:
                                    Clear::clear_screen();
                                    cout<<CYAN << "Exiting..." <<RESET << endl;
                                    this_thread::sleep_for(chrono::seconds(2));
                                    for (auto fm : Field_manager::field_managers) {
                                        fm->FM_update_to_DB();
                                    }
                                    p.P_update_to_DB();
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
                        this_thread::sleep_for(chrono::seconds(2));
                }
                break;
            case 2: {
                currentMenu = fieldManagerMenu;
                print_Menu(currentMenu);
                cin >> choice2;
                switch (choice2) {
                    case 1: {
                        Clear::clear_screen();
                        Field_manager fm = FM_login();
                        if (fm.Get_id() == 0) {
                            currentMenu = playerFieldManagerMenu;
                            break;
                        }
                        int choice;
                        bool exitMenu = false;

                        do {
                            Clear::clear_screen();
                            // Display menu options
                            std::cout<< CYAN << "Field Manager Menu" << RESET << std::endl;
                            std::cout << "1. Add Field" << std::endl;
                            std::cout << "2. Remove Field" << std::endl;
                            std::cout << "3. Profile" << std::endl;
                            std::cout << "4. Closed Hours in Field" << std::endl;
                            std::cout << "5.Pay to be first" << std::endl;
                            std::cout << "6. Back" << std::endl;
                            std::cout << "Enter your choice: ";

                            // Get user choice
                            std::cin >> choice;

                            // Process user choice
                            switch (choice) {
                                case 1: {
                                    Clear::clear_screen();
                                    std::cout<< CYAN << "Add a new field."<< RESET << std::endl;
                                    Field field = Field::add_field();
                                    fm.field.push_back(field);
                                    fm.update_to_DB();
                                    Field_manager::field_managers.push_back(&fm);
                                }
                                    break;
                                case 2:
                                    Clear::clear_screen();
                                    std::cout<< CYAN << "Removing a field."<< RESET << std::endl;
                                    remove_field(fm, Field_manager::field_managers);
                                    // Remove field logic
                                    break;
                                case 3:
                                    Clear::clear_screen();
                                    std::cout<< CYAN << "Viewing profile..."<<  RESET << std::endl;
                                    FM_menu_profile(fm);
                                    break;
                                case 4:
                                    Clear::clear_screen();
                                    std::cout<< CYAN << "Viewing closed hours in field..."<< RESET << std::endl;
                                    closed_by_manager(fm, Field_manager::field_managers);
                                    break;
                                case 5:
                                    Clear::clear_screen();
                                    std::cout << CYAN << "Pay to be first..." << RESET << std::endl;
                                    fm.Pay_to_be_first();
                                    break;
                                case 6:
                                    Clear::clear_screen();
                                    std::cout << CYAN << "Going back..." << RESET << std::endl;
                                    exitMenu = true;
                                    break;
                                default:
                                    std::cout<< RED << "Invalid choice. Please try again."<< RESET << std::endl;
                                    this_thread::sleep_for(chrono::seconds(2));
                                    break;
                            }
                        } while (!exitMenu);
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
                            std::cout << "5.Pay to be first" << std::endl;
                            std::cout << "6. Back" << std::endl;
                            std::cout << "Enter your choice: ";

                            // Get user choice
                            std::cin >> choice;

                            // Process user choice
                            switch (choice) {
                                case 1: {
                                    Clear::clear_screen();
                                    std::cout<<CYAN << "Adding a new field..."<< RESET << std::endl;
                                    Field field = Field::add_field();
                                    fm->field.push_back(field);
                                    fm->update_to_DB();
                                    break;
                                }
                                case 2: {
                                    Clear::clear_screen();
                                    std::cout<<CYAN << "Remove a field."<< RESET << std::endl;
                                    remove_field(*fm, Field_manager::field_managers);
                                    break;
                                }
                                case 3:
                                    Clear::clear_screen();
                                    std::cout<<CYAN << "Viewing profile."<< RESET << std::endl;
                                    FM_menu_profile(*fm);
                                    break;
                                case 4:
                                    Clear::clear_screen();
                                    std::cout<<CYAN << "Viewing closed hours in field..." << RESET << std::endl;
                                    closed_by_manager(*fm, Field_manager::field_managers);
                                    break;
                                case 5:
                                    Clear::clear_screen();
                                    std::cout << CYAN << "Pay to be first..." << RESET << std::endl;
                                    fm->Pay_to_be_first();
                                    break;
                                case 6:
                                    Clear::clear_screen();
                                    std::cout << CYAN << "Going back..." << RESET << std::endl;
                                    exitMenu = true;
                                    break;
                                default:
                                    std::cout<<RED << "Invalid choice. Please try again."<< RESET << std::endl;
                                    this_thread::sleep_for(chrono::seconds(2));
                                    Clear::clear_screen();
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

//Retriver from DB
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
//PLAYER!!
void MyMain::player_menu_booking(Player &p, const vector<Field_manager *> &field_managers) {
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
    int cityChoice;
    do {
        cout << "Choose a city:" << endl;
        for (size_t i = 0; i < cities.size(); ++i) {
            cout << i + 1 << ". " << cities[i] << endl;
        }
        cout << "Enter the number of the city (or '0' to main menu): ";
        string input;
        cin >> input;
        try {
            cityChoice = stoi(input);
            if (cityChoice == 0) {
                Clear::clear_screen();
                return;
            }
            if (cityChoice < 1 || cityChoice > static_cast<int>(cities.size())) {
                throw out_of_range("City choice is out of range.");
            }
        } catch (const exception &e) {
            Clear::clear_screen();
            continue;
        }
    } while (cityChoice < 1 || cityChoice > static_cast<int>(cities.size()));
    Clear::clear_screen();

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
        int fieldChoice;
        do {
            cout << "Choose a field:" << endl;
            for (size_t i = 0; i < availableFields.size(); ++i) {
                cout << i + 1 << ". " << availableFields[i].get_field_name() << endl;
            }
            cout << "Enter the number of the field (or '0' to return to main menu): ";
            string input;
            cin >> input;
            try {
                fieldChoice = stoi(input);
                if (fieldChoice == 0) {
                    Clear::clear_screen();
                    return; // Return to main menu
                }
                if (fieldChoice < 1 || fieldChoice > static_cast<int>(availableFields.size())) {
                    throw out_of_range("Field choice is out of range.");
                }
            } catch (const exception &e) {
                cerr << "Error: " << e.what() << endl;
                Clear::clear_screen();
                continue;
            }
        } while (fieldChoice < 1 || fieldChoice > static_cast<int>(availableFields.size()));
        Field* chosenField = nullptr;
        Field_manager* manager = nullptr;
        for (auto& fm : field_managers) {
            auto it = find(fm->field.begin(), fm->field.end(), availableFields[fieldChoice - 1]);
            if (it != fm->field.end()) {
                manager = fm;
                chosenField = &(*it);  // Assign the address of the found field to chosenField
                break;
            }
        }

        Clear::clear_screen();

        // Display available days for booking
        int dayChoice;
        do {
            cout << "Choose a day:" << endl;
            for (size_t i = 0; i < 5; ++i) {
                cout << i + 1 << ". " << days[i] << endl;
            }
            cout << "Enter the number of the day: ";
            string input;
            cin >> input;
            try {
                dayChoice = stoi(input);
                if (dayChoice < 1 || dayChoice > 5) {
                    throw out_of_range("Day choice is out of range.");
                }
            } catch (const exception &e) {
                cerr << "Error: " << e.what() << endl;
                Clear::clear_screen();
                continue;
            }
        } while (dayChoice < 1 || dayChoice > 5);
        int dayIndex = dayChoice - 1;
        Clear::clear_screen();

        // Display available hours for booking
        cout << "Available hours for booking:" << endl;
        for (int hour = 8; hour <= 19; ++hour) {
            if (chosenField->isAvailable(dayIndex, hour - 8)) {
                cout << hour << ":00 - " << hour + 1 << ":00" << endl;
            }
        }
        cout << "Enter the starting hour (8-18): ";
        int startHour;
        cin >> startHour;
        if (startHour < 8 || startHour > 18) {
            cerr << "Invalid starting hour. Please try again." << endl;
            return;
        }
        Clear::clear_screen();

        // Process the booking for the chosen field, day, and hour
        long playerId = p.Get_id();

        if (manager) {
            Field temp = manager->book_field_in_city_at_day_hour(playerId, chosenCity, dayIndex, startHour);
            p.booked.booked_fields.push_back(temp);
            p.booked.setOccupied_slots(dayIndex, startHour - 8, playerId);
            manager->FM_update_to_DB();
            p.P_update_to_DB();

            // Ask user if they want to add the booked field to their favorites
            char addToFavorites;
            cout << "Add this field to your favorites? (y/n): ";
            cin >> addToFavorites;
            if (addToFavorites == 'y' || addToFavorites == 'Y') {
                p.f += *chosenField;
                p.update_to_DB();
                cout << "Field added to favorites." << endl;
                Clear::clear_screen();
            } else {
                cout << "Field not added to favorites." << endl;
                Clear::clear_screen();
            }
        } else {
            cerr << "Failed to book field." << endl;
            Clear::clear_screen();
        }
    } else {
        cout << "No available fields in " << chosenCity << "." << endl;
        Clear::clear_screen();
    }
}
void MyMain::player_menu_cancel(Player &p, const vector<Field_manager *> &field_managers) {
    string days[5] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
    // Find all fields booked by the player
    std::vector<std::tuple<Field*, Field_manager*, int, int>> booked_fields;
    for (auto fm : field_managers) {
        for (auto& field : fm->field) {
            for (int day = 0; day < 5; ++day) {
                for (int hour = 0; hour < 12; ++hour) {
                    if (field.get_occupied(day, hour) == p.Get_id()) {
                        booked_fields.push_back({&field, fm, day, hour});
                    }
                }
            }
        }
    }

    // Display the booked fields
    if (booked_fields.empty()) {
        std::cout << "You have no booked fields to cancel." << std::endl;
        return;
    } else {
        bool exit = false;
        do {
            std::cout << "Choose a field to cancel (or '0' to return to main menu):" << std::endl;
            for (size_t i = 0; i < booked_fields.size(); ++i) {
                std::cout << i + 1 << ". ";
                std::cout << "Field: " << std::get<0>(booked_fields[i])->get_field_name() << ", ";
                std::cout << "Day: " << days[std::get<2>(booked_fields[i])] << ", ";
                std::cout << "Hour: " << (std::get<3>(booked_fields[i]) + 8) << ":00" << std::endl;
            }

            // Get user choice
            int choice;
            try {
                cout << "Enter the number of the field to cancel (or '0' to return to main menu): ";
                cin >> choice;

                // Check if the user wants to return to main menu
                if (choice == 0) {
                    return; // Return to main menu
                }

                // Validate user choice
                if (choice < 1 || choice > static_cast<int>(booked_fields.size())) {
                    throw std::invalid_argument("Invalid choice. Please try again.");
                }

                // Process user choice
                Field* field = std::get<0>(booked_fields[choice - 1]);
                Field_manager* manager = std::get<1>(booked_fields[choice - 1]);
                int day = std::get<2>(booked_fields[choice - 1]);
                int hour = std::get<3>(booked_fields[choice - 1]);

                if (manager && manager->cancel_field_booking(p.Get_id(), *field, day, hour)) {
                    cout << "Field booking canceled." << endl;
                    // Remove the canceled field from the player's booked fields
                    p.booked.remove_booking_by_day_hour(p.Get_id(), day, hour);

                    // Remove the canceled field from the booked_fields vector
                    p.booked.booked_fields.erase(p.booked.booked_fields.begin() + choice - 1);
                } else {
                    std::cout << "Failed to cancel field booking." << std::endl;
                }

                // Ask user if they want to continue
                char continueChoice;
                cout << "Do you want to cancel another field? (y/n): ";
                cin >> continueChoice;
                Clear::clear_screen();
                if (continueChoice == 'n') {
                    exit = true;

                }
            } catch (const std::exception& e) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

        } while (!exit);
    }
    p.update_to_DB();
}


//player profile
void MyMain::P_menu_profile(Player &p) {

    // Define the menu options and corresponding actions
    std::map<int, std::function<void(Player &)>> menu = {
            {1, [](Player &p) { p.print(); }},
            {2, [this](Player &p) { P_profile_menu_2(p); }},
            {3, [](Player &p) { cout<<CYAN << "Back to main menu..."<<RESET << endl; /* Logout */ }},
    };

    string choice;
    int choice_int;
    do {
        cout<<GREEN << "You are logged in as " << p.Get_Name()<<RESET << endl;
        cout << CYAN << "Choose an option:" << RESET << endl;
        cout << "1. View your profile" << endl;
        cout << "2. Edit your profile" << endl;
        cout << "3. Back" << endl;
        cin >> choice;

        try {
            choice_int = stoi(choice);
            if (choice_int < 1 || choice_int > 3) {
                throw std::invalid_argument("Invalid choice. Please try again.");
            }
            // Execute the corresponding action based on the user's choice
            auto it = menu.find(choice_int);
            if (it != menu.end()) {
                it->second(p);
            } else {
                cout << RED << "Invalid choice. Please try again." << RESET << endl;
                this_thread::sleep_for(chrono::seconds(2));
                Clear::clear_screen();
            }
        }
        catch (const std::exception& e) {
            cout<<"Error: "<< e.what() << endl;
            this_thread::sleep_for(chrono::seconds(2));
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
    } while (choice_int != 3); // Corrected loop condition
    Clear::clear_screen();
}
void MyMain::P_profile_menu_2(Player &p) {
    cout << CYAN << "Choose what to edit:" << RESET << endl;
    string choice;
    do {
        cout << "1. Name" << endl;
        cout << "2. Address" << endl;
        cout << "3. Phone number" << endl;
        cout << "4. Password" << endl;
        cout << "5. Back" << endl;
        cin >> choice;
        int choice_int;
        Clear::clear_screen();
        try {
            choice_int = stoi(choice);
            if (choice_int < 1 || choice_int > 6) {
                throw std::invalid_argument("Invalid choice. Please try again.");
            }

            switch (choice_int) {
                case 1:
                    Clear::clear_screen();
                    p.Set_Name();
                    break;
                case 2:
                    Clear::clear_screen();
                    p.Set_Address();
                    break;
                case 3:
                    Clear::clear_screen();
                    p.Set_phone_number();
                    break;
                case 4:
                    Clear::clear_screen();
                    p.Set_password();
                    break;
                case 5:
                    Clear::clear_screen();
                    return;
                default:
                    cout << RED << "Invalid choice. Please try again." << RESET << endl;
                    this_thread::sleep_for(chrono::seconds(2));
                    break;
            }
        } catch (const exception& e) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "Invalid input. Please try again." << RESET << endl;
            this_thread::sleep_for(chrono::seconds(2));
            Clear::clear_screen();
        }
    } while (true);
    Clear::clear_screen();
}



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
        if (field_book.size() == 0) {
            cout << CYAN << "You haven't booked any field yet" << RESET << endl;
            this_thread::sleep_for(chrono::seconds(2));
            Clear::clear_screen();
            return;
        }
        cout << CYAN << "Choose a field:" << RESET << endl;
        for (size_t i = 0; i < field_book.size(); ++i) {
            cout << i + 1 << ". " << field_book[i] << endl;
        }
        cout << CYAN << "Enter the number of the field: " << RESET << endl;
        cin >> fieldChoice;
    } while (!(fieldChoice >= 1 && fieldChoice <= static_cast<int>(field_book.size())));
    try {
        cout << CYAN << "Enter the rating field of (1-5) " << RESET << field_book[fieldChoice - 1] << endl;
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
    catch (const std::exception& e) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }}
void MyMain::remove_field(Field_manager &fm, vector<Field_manager *> &field_managers) {
    while (!fm.field.empty()) {
        // Display all fields in the field manager
        cout << "Choose a field to remove:" << endl;
        for (size_t i = 0; i < fm.field.size(); ++i) {
            cout << i + 1 << ". " << fm.field[i].get_field_name() << " (City: " << fm.field[i].get_field_city() << ")"
                 << endl;
        }

        string choice;
        int choice_int;
        bool validChoice = false;
        do {
            cout << "Enter the number of the field you want to remove (0 to exit): ";
            cin >> choice;
            try {
                choice_int = stoi(choice);

                if (choice_int == 0) {
                    return; // Exit the function if the user enters 0
                }

                // Validate user choice
                if (choice_int >= 1 && choice_int <= static_cast<int>(fm.field.size())) {
                    validChoice = true;
                } else {
                    Clear::clear_screen();
                    cout << "Invalid choice. Please try again." << endl;
                    this_thread::sleep_for(chrono::seconds(2));
                    // Display all fields again
                    for (size_t i = 0; i < fm.field.size(); ++i) {
                        cout << i + 1 << ". " << fm.field[i].get_field_name() << " (City: " << fm.field[i].get_field_city() << ")"<< endl;
                    }
                }
            } catch (const std::exception &e) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                Clear::clear_screen();
                cout << "Invalid input. Please try again." << endl;
                this_thread::sleep_for(chrono::seconds(2));
                // Display all fields again
                for (size_t i = 0; i < fm.field.size(); ++i) {
                    cout << i + 1 << ". " << fm.field[i].get_field_name() << " (City: " << fm.field[i].get_field_city() << ")"<< endl;
                }
            }
        } while (!validChoice);

        // Remove the field from the field manager's vector
        fm.field.erase(fm.field.begin() + (choice_int - 1));
        cout << "Field removed successfully." << endl;
        this_thread::sleep_for(chrono::seconds(2));
        Clear::clear_screen();
        // Update the field manager in the database
        fm.update_to_DB();

        // Remove the field manager from the vector of field managers
        field_managers.erase(remove(field_managers.begin(), field_managers.end(), &fm), field_managers.end());
    }

    cout << "No fields to remove." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    Clear::clear_screen();
}





//Field Manager Profile
void MyMain:: FM_menu_profile(Field_manager &fm){


    // Define the menu options and corresponding actions
    std::map<int, std::function<void(Field_manager &)>> menu = {
            {1, [](Field_manager &fm) { fm.print(); }},
            {2, [this](Field_manager &fm) { FM_profile_menu_2(fm); }},
            {3, [](Field_manager &fm) { cout<<CYAN << "Back to main menu..."<<RESET << endl; /* Logout */ }},
    };

    string choice;
    int choice_int;
    do {
        cout<<GREEN << "You are logged in as " << fm.Get_Name()<<RESET << endl;
        cout << CYAN << "Choose an option:" << RESET << endl;
        cout << "1. View your profile" << endl;
        cout << "2. Edit your profile" << endl;
        cout << "3. Back" << endl;
        cin >> choice;

        try {
            choice_int = stoi(choice);
            if (choice_int < 1 || choice_int > 3) {
                throw std::invalid_argument("Invalid choice. Please try again.");
                Clear::clear_screen();
            }
            // Execute the corresponding action based on the user's choice
            auto it = menu.find(choice_int);
            if (it != menu.end()) {
                it->second(fm);
            } else {
                cout << RED << "Invalid choice. Please try again." << RESET << endl;
                Clear::clear_screen();
            }
        }
        catch (const std::exception& e) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            Clear::clear_screen();
            continue;
        }
    } while (choice_int != 3); // Corrected loop condition
    Clear::clear_screen();

}
void MyMain::FM_profile_menu_2(Field_manager &fm) {
    cout << CYAN << "Choose what to edit:" << RESET << endl;
    string choice;
    do {
        cout << "1. Name" << endl;
        cout << "2. Address" << endl;
        cout << "3. Phone number" << endl;
        cout << "4. Password" << endl;
        cout << "5. Back" << endl;
        cin >> choice;
        int choice_int;
        try {
            choice_int = stoi(choice);
            if (choice_int < 1 || choice_int > 6) {
                throw std::invalid_argument("Invalid choice. Please try again.");
            }

            switch (choice_int) {
                case 1:
                    Clear::clear_screen();
                    fm.Set_Name();
                    break;
                case 2:
                    Clear::clear_screen();
                    fm.Set_Address();
                    break;
                case 3:
                    Clear::clear_screen();
                    fm.Set_phone_number();
                    break;
                case 4:
                    Clear::clear_screen();
                    fm.Set_password();
                    break;
                case 5:
                    Clear::clear_screen();
                    return;
                default:
                    Clear::clear_screen();
                    cout << RED << "Invalid choice. Please try again." << RESET << endl;
                    break;
            }
        } catch (const exception& e) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "Invalid input. Please try again." << RESET << endl;
            Clear::clear_screen();
        }
    } while (true);
    Clear::clear_screen();
}
void MyMain::closed_by_manager(Field_manager &fm, vector<Field_manager *> &field_managers) {
    string days[5] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
    int choice;
    do {
        cout << "Which field do you want to close? (Enter 0 to exit)" << endl;

        for (int i = 0; i < fm.field.size(); ++i) {
            cout << i + 1 << ". " << fm.field[i].get_field_name() << " (City: " << fm.field[i].get_field_city() << ")"
                 << endl;
        }

        try{
            cin >> choice;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please try again." << endl;
                continue;
            }
            if (choice == 0) {
                return; // Exit the function
            }
            if (choice < 1 || choice > static_cast<int>(fm.field.size())) {
                cout << "Invalid field choice. Please try again." << endl;
                continue;
            }


            cout << "Which day do you want to close?" << endl;
            for (int i = 0; i < 5; ++i) {
                cout << i + 1 << ". " << days[i] << endl;
            }
            int choice2;
            cin >> choice2;
            if (choice2 < 1 || choice2 > 5) {
                cout << "Invalid day choice. Please try again." << endl;
                continue;
            }

            int startHour, endHour;
            cout << "Which hour do you want to close?" << endl;
            cin >> startHour;
            cout << "Until what hour do you want to close?" << endl;
            cin >> endHour;
            if (startHour < 0 || startHour > 24 || endHour < 0 || endHour > 24 || endHour <= startHour) {
                cout << "Invalid hour range. Please try again." << endl;
                continue;
            }

            fm.field[choice - 1].close_field(choice2, startHour, endHour);
        }catch (const exception& e){
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (true);

}

