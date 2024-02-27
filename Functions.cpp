#include "Functions.h"
#include "Player.h"
#include "sqlite3.h"
using namespace std;

int Functions::GetDouble(long i) {
    switch (i) {
        case 0: return 0;
        case 1: return 2;
        case 2: return 4;
        case 3: return 6;
        case 4: return 8;
        case 5: return 1;
        case 6: return 3;
        case 7: return 5;
        case 8: return 7;
        case 9: return 9;
        default: return 0;
    }
}

bool Functions:: IsValidIsraeliID(const std::string& israeliID) {
    if (israeliID.length() != 9)
        return false;

    long sum = 0;

    for (int i = 0; i < israeliID.length(); i++) {
        int digit = israeliID[israeliID.length() - 1 - i] - '0';
        sum += (i % 2 != 0) ? GetDouble(digit) : digit;
    }

    return sum % 10 == 0;
}

bool Functions::checkLogin_P(sqlite3* db, const string& id, const string& password) {
    sqlite3_stmt *stmt;
    string sql = "SELECT * FROM [Player_Accounts] WHERE ID='" + id + "' AND Password='" + password + "'";
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        cerr << "Failed to execute query: " << sql << "\n";
        cerr << "Error: " << sqlite3_errmsg(db) << "\n";
        return false;
    }

    bool loginSuccess = sqlite3_step(stmt) == SQLITE_ROW;
    sqlite3_finalize(stmt);
    return loginSuccess;
}

bool Functions:: checkLogin_FM(sqlite3* db, const string& id, const string& password) {
    sqlite3_stmt *stmt;
    string sql = "SELECT * FROM [Field_Manager_Accounts] WHERE ID='" + id + "' AND Password='" + password + "'";
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        cerr << "Failed to execute query: " << sql << "\n";
        cerr << "Error: " << sqlite3_errmsg(db) << "\n";
        return false;
    }

    bool loginSuccess = sqlite3_step(stmt) == SQLITE_ROW;
    sqlite3_finalize(stmt);
    return loginSuccess;
}



int Functions:: P_insert_to_DB(Player &p) {
    sqlite3* db;
    int rc = sqlite3_open("Test player data DB.db", &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return rc;
    }

    const char* sql = "INSERT INTO [Player_Accounts] (Name, ID, Phone_number, Gender, Address, Birthday, Password) VALUES (?, ?, ?, ?, ?, ?, ?)";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return rc;
    }
    string gender(1, p.Get_gender());

    sqlite3_bind_text(stmt, 1, p.Get_Name().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, p.Get_id());
    sqlite3_bind_int(stmt, 3, p.Get_phone_number());
    sqlite3_bind_text(stmt, 4, gender.c_str(), 1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, p.Get_Address().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, p.date_to_string().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 7, p.get_password().c_str(), -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Error inserting data: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return rc;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return SQLITE_OK;
}

int Functions:: FM_insert_to_DB(Field_manager &p){
    sqlite3* db;

    int rc = sqlite3_open("Test player data DB.db", &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return rc;
    }

    const char* sql = "INSERT INTO [Field_Manager_Accounts] (Name, ID, Phone_number, Gender, Address, Birthday, Password) VALUES (?, ?, ?, ?, ?, ?, ?)";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return rc;
    }
    string gender(1, p.Get_gender());

    sqlite3_bind_text(stmt, 1, p.Get_Name().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, p.Get_id());
    sqlite3_bind_int(stmt, 3, p.Get_phone_number());
    sqlite3_bind_text(stmt, 4, gender.c_str(), 1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, p.Get_Address().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, p.date_to_string().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 7, p.get_password().c_str(), -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Error inserting data: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return rc;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return SQLITE_OK;
}

//Menus
void Functions:: player_menu_1(){
    cout<<"Choose one of the following option:"<<endl;
    cout<<"1. Favorites"<<endl;
    cout<<"2. Book field"<<endl;
    cout<<"3. Cancel field"<<endl;
    cout<<"4. Rate field"<<endl;
    cout<<"5. Profile"<<endl;
    cout<<"6. Booked fields"<<endl;
    cout<<"7. Exit"<<endl;
}
void Functions:: player_menu_favorites(Player &p){
    p.f.print();
}

void Functions::player_menu_booking(Player &p, Field_manager *f) {
    std::vector<std::string> cities;
    std::cout << "Choose from which city you want to book a field:" << std::endl;

    // Collect unique cities from the fields
    for (int i = 0; i < Field_manager::counter; ++i) {
        std::string city = f->field[i].get_field_city();
        if (std::find(cities.begin(), cities.end(), city) == cities.end()) {
            cities.push_back(city);
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
            if (!f->is_day_occupied(chosenCity, day)) {
                std::cout << day << ": "; // You might want to convert day to a weekday name
                // Display available hours for booking on this day
                for (int hour = 8; hour < 20; ++hour) { // Assuming hours are from 8 to 19
                    if (!f->is_hour_occupied(chosenCity, day, hour)) {
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
        if (dayChoice >= 0 && dayChoice < 5 && !f->is_day_occupied(chosenCity, dayChoice)) {
            // Get user choice for hour
            int hourChoice;
            std::cout << "Choose an hour: ";
            std::cin >> hourChoice;

            // Validate and process user choice for hour
            if (hourChoice >= 8 && hourChoice < 20 && !f->is_hour_occupied(chosenCity, dayChoice, hourChoice)) {
                // Process the booking for the chosen city, day, and hour
                f->book_field_in_city_at_day_hour(p, chosenCity, dayChoice, hourChoice);

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
                    Field chosen(f->field[index].get_field_name(), f->field[index].get_field_type(), f->field[index].get_field_city());
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

void Functions::player_menu_cancel(Player &p, Field_manager *fm) {
    // Find all fields booked by the player
    std::vector<Field> temp_field;
    for (int i = 0; i < Field_manager::counter; ++i) {
        if (fm[i].is_field_booked_by(p.Get_id())) {
            temp_field.push_back(fm->field[i]);
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
            if (fm->cancel_field_booking(p.Get_id())){
                cout << "Field booking canceled." <<endl;
            } else {
                std::cout << "Failed to cancel field booking." << std::endl;
            }
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}

void Functions::player_menu_profile(Player &p) {
    cout<<"You are logged in as "<<p.Get_Name()<<endl;
    cout<<"Choose an option:"<<endl;
    cout<<"1. View your profile"<<endl;
    cout<<"2. Edit your profile"<<endl;
    cout<<"3. View your bookings"<<endl;
    cout<<"4. Logout"<<endl;
}

void Functions::profile_menu_1(User &u) {
    u.print();

}
void Functions::profile_menu_2(User &u) {
    cout<<"Choose what to edit:"<<endl;
    cout<<"1. Name"<<endl;
    cout<<"2. Address"<<endl;
    cout<<"3. Phone number"<<endl;
    cout<<"4. Gender"<<endl;
    cout<<"5. Birth date"<<endl;
    cout<<"6. Password"<<endl;
    cout<<"7. Back"<<endl;
}

void Functions::profile_menu_3() {

    cout<<"Choose what to edit:"<<endl;
    cout<<"1. Name"<<endl;
    cout<<"2. Address"<<endl;
    cout<<"3. Phone number"<<endl;
    cout<<"4. Gender"<<endl;
    cout<<"5. Birth date"<<endl;
    cout<<"6. Password"<<endl;
    cout<<"7. Back"<<endl;
}








