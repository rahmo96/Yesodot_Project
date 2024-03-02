//
// Created by חי כרמי on 21/02/2024.
//

#include "Field_manager.h"
#include <vector>

Field_manager::Field_manager(string name, long id, string address, long phone_num, char gender, Date b_day,
                             string passowrd, vector<Field> field1, bool promoting_funded)
        : User(name, id, address, phone_num, gender, b_day, passowrd), field(field1) {counter++;}


void Field_manager::print() {
    User::print(); // Print user details

    // Print fields
    for (auto &f : field) {
        f.print(); // Print field details
    }

    // Print promotion status
    if (promoting_funded) {
        cout << "Promoted!" << endl;
    } else {
        cout << "Not promoted yet!" << endl;
    }
}


Field_manager &Field_manager::operator+=(const Field_manager &fieldManager) {

    field.insert(field.end(), fieldManager.field.begin(), fieldManager.field.end());
    return *this;
}

bool Field_manager::is_hour_occupied(const std::string &city, int day, int hour) const {
    for (int i = 0; i < counter; ++i) {
        if (field[i].get_field_city() == city && occupied[day][hour] != 0 && occupied[day][hour] != 1) {
            return true; // Hour is occupied
        }
    }
    return false; // Hour is not occupied
}

bool Field_manager::is_day_occupied(const std::string &city, int day) const {
    for (int i = 0; i < counter; ++i) {
        if (field[i].get_field_city() == city) {
            for (int hour = 8; hour < 20; ++hour) {
                if (occupied[day][hour] != 0 && occupied[day][hour] != 1) {
                    return true; // Day is occupied
                }
            }
        }
    }
    return false; // Day is not occupied
}

void Field_manager::book_field_in_city_at_day_hour(long id, const std::string &city, int day, int hour) {
    // Find the field in the specified city
    string days[5]={"Sunday","Monday","Tuesday","Wednesday","Thursday"};
    for (int i = 0; i < counter; ++i) {
        if (field[i].get_field_city() == city) {
            // Check if the slot is already booked
            if (occupied[day][hour] != 0) {
                std::cout << "This slot is already booked." << std::endl;
                return;
            }

            // Mark the hour as occupied with the player's ID
            occupied[day][hour] = id;

            // Additional logic to handle the booking (e.g., updating records)
            std::cout << "Field booked in " << city << " on day " << days[day] << " at " << hour << ":00." << std::endl;
            break;
        }
    }
}


bool Field_manager::is_field_booked_by(long id) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 12; ++j) {
            if (occupied[i][j] == id) {
                return true; // Field is booked
            }
        }
    }
    return false; // Field is not booked
}

bool Field_manager::cancel_field_booking(long id) {
    bool bookingCanceled = false;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 12; ++j) {
            if (this->occupied[i][j] == id) {
                this->occupied[i][j] = 0; // Cancel the booking by setting it to 0
                bookingCanceled = true;
            }
        }
    }
    return bookingCanceled;
}

void Field_manager::find_fields_with_id(long id) {
    for (Field &field: field) {
        if (this->is_field_booked_by(id)) { // Assuming is_booked_by() checks if the field is booked by the given ID
            field.print();
        }
    }
}

void Field_manager::to_json(nlohmann::json &j) {
    json player_json;
    User::to_json(player_json);
    nlohmann::json field_json;
    for (const auto &field_item: field) {
        nlohmann::json field_obj;
        field_item.to_json(field_obj);
        field_json.push_back(field_obj);
    }

    nlohmann::json occupied_json;
    for (size_t i = 0; i < 5; ++i) {
        nlohmann::json row_json;
        for (size_t k = 0; k < 12; ++k) {
            row_json.push_back(occupied[i][k]);
        }
        occupied_json.push_back(row_json);
    }

    j = {
            {"Name",             name},
            {"id",               id},
            {"address",          Address},
            {"phone_num",        phone_number},
            {"b_day",            date_to_string()},
            {"gender",           string (1, gender)},
            {"password",         passowrd},
            {"promoting_funded", promoting_funded},
            {"Field",            field_json},
            {"Occupied",         occupied_json}
    };
}



Field_manager Field_manager::from_json(const nlohmann::json &j) {
    this->name = j.at("Name");
    this->id = j.at("id");
    this->Address = j.at("address");
    this->phone_number = j.at("phone_num");
    string gender_str = j.at("gender");
    this->gender =gender_str[0];
    this->passowrd = j.at("password");
    this->promoting_funded = j.at("promoting_funded");
    // Deserialize the 'field' array
    const nlohmann::json &field_json = j.at("Field");
    field.clear(); // Clear existing fields
    for (const auto &field_obj: field_json) {
        Field field_item;
        field_item.from_json(field_obj);
        field.push_back(field_item);
    }

    // Deserialize the 'occupied' 2D array
    const nlohmann::json &occupied_json = j.at("Occupied");
    for (size_t i = 0; i < 5; ++i) {
        for (size_t j = 0; j < 12; ++j) {
            occupied[i][j] = occupied_json.at(i).at(j);
        }
    }

    return *this;

}



Field_manager Field_manager::build_from_json(string json_str) {
    nlohmann::json j = nlohmann::json::parse(json_str);
    Field_manager fm;
    fm.from_json(j);
    return fm;
}

Field_manager Field_manager::build_from_DB(long id) {
    try {
        json j = User::FM_from_DB(id);
        string name = j.at("Name");
        long id = j.at("id");
        string Address = j.at("address");
        long phone_number = j.at("phone_num");
        string g = j.at("gender");
        char gender = g[0];
        Date b_day;
        b_day.setDateFromString(j.at("b_day"));
        string password = j.at("password");

        vector<Field> fields;
        const nlohmann::json& field_json = j.at("Field");
        for (const auto& field_obj : field_json) {
            Field field_item;
            field_item.from_json(field_obj);
            fields.push_back(field_item);
        }
        const nlohmann::json &occupied_json = j.at("Occupied");
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 12; ++j) {
                //occupied[i][j] = occupied_json.at(i).at(j);
            }
        }
        const nlohmann::json &promoting_funded_json = j.at("promoting_funded");
        bool promoting_funded = promoting_funded_json;
        Field_manager fm;
        fm.Set_field_manager(name, id, Address, phone_number, gender, b_day, password, fields, promoting_funded);
        return fm;

    } catch (const std::exception& e) {
        std::cerr << "Error building Player from JSON: " << e.what() << std::endl;
        // Handle the error appropriately, such as returning a default-constructed Player or re-throwing the exception
        throw;
    }
}

void Field_manager::Set_field_manager(string name, long id, string address, long phone_num, char gender, Date b_day,
                                      string passowrd, vector<Field> field1, bool promoting_funded) {

    this->name = name;
    this->id = id;
    this->Address = address;
    this->phone_number = phone_num;
    this->gender = gender;
    this->b_day = b_day;
    this->passowrd = passowrd;
    this->field = field1;
    this->promoting_funded = promoting_funded;

}

bool Field_manager::update_to_DB() {
        // Serialize the updated Player object to a JSON string
        nlohmann::json player_data;
        this->to_json(player_data);

        sqlite3 *db;
        if (sqlite3_open("Test player data DB.db", &db) != SQLITE_OK) {
            std::cerr << "Error opening database" << std::endl;
            return false;
        }

        // Update the Class_data column in the database with the updated JSON string
        std::string update_query =
                "UPDATE [Field_Manager_Accounts] SET [Class_data] = '" + player_data.dump() + "' WHERE id = " +
                std::to_string(this->Get_id());
        const char *sql = update_query.c_str();
        if (sqlite3_exec(db, sql, nullptr, nullptr, nullptr) != SQLITE_OK) {
            std::cerr << "Error updating database" << std::endl;
            sqlite3_close(db);
            return false;
        }

        sqlite3_close(db);
        return true;
    }



