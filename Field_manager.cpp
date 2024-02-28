//
// Created by חי כרמי on 21/02/2024.
//

#include "Field_manager.h"
#include <vector>

Field_manager::Field_manager(string name, long id, string address, long phone_num,char gender,Date b_day,string passowrd,vector<Field> field1)
: User(name, id,  address,  phone_num,gender,b_day,passowrd) , field(field1) {}


void Field_manager::print() {
        for ( auto &field : field) {
            User::print();
            field.print();
        }
        }

Field_manager &Field_manager::operator+=(const Field_manager &fieldManager) {

    field.insert(field.end(), fieldManager.field.begin(), fieldManager.field.end());
    return *this;
}
bool Field_manager::is_hour_occupied(const std::string& city, int day, int hour) const {
    for (int i = 0; i < counter; ++i) {
        if (field[i].get_field_city() == city && occupied[day][hour]!=0 && occupied[day][hour]!=1) {
            return true; // Hour is occupied
        }
    }
    return false; // Hour is not occupied
}

bool Field_manager::is_day_occupied(const std::string& city, int day) const {
    for (int i = 0; i < counter; ++i) {
        if (field[i].get_field_city() == city) {
            for (int hour = 8; hour < 20; ++hour) {
                if (occupied[day][hour]!=0 && occupied[day][hour]!=1) {
                    return true; // Day is occupied
                }
            }
        }
    }
    return false; // Day is not occupied
}

void Field_manager::book_field_in_city_at_day_hour(Player &p, const std::string& city, int day, int hour) {
    for (int i = 0; i < counter; ++i) {
        if (field[i].get_field_city() == city) {
            occupied[day][hour] =p.Get_id(); // Mark the hour as occupied
            // Additional logic to handle the booking (e.g., updating records)
            std::cout << "Field booked in " << city << " on day " << day << " at " << hour << ":00." << std::endl;
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

bool Field_manager::cancel_field_booking( long id) {
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
    for (Field& field : field) {
        if (this->is_field_booked_by(id)) { // Assuming is_booked_by() checks if the field is booked by the given ID
            field.print();
        }
    }
}

void Field_manager::to_json(nlohmann::json &j) {
    json user_data;
    User::to_json(user_data);

    nlohmann::json field_json;
    for (const auto& field_item : field) {
        nlohmann::json field_obj;
        field_item.to_json(field_obj);
        field_json.push_back(field_obj);
    }

    nlohmann::json occupied_json;
    for (size_t i = 0; i < 5; ++i) {
        nlohmann::json row_json;
        for (size_t j = 0; j < 12; ++j) {
            row_json.push_back(occupied[i][j]);
        }
        occupied_json.push_back(row_json);
    }


    j = {

            {"Field", field_json},
            {"occupied", occupied_json}
    };

}

void Field_manager::from_json(const nlohmann::json &j) {
    // Deserialize the 'field' array
    const nlohmann::json& field_json = j.at("field");
    field.clear(); // Clear existing fields
    for (const auto& field_obj : field_json) {
        Field field_item;
        field_item.from_json(field_obj);
        field.push_back(field_item);
    }

    // Deserialize the 'occupied' 2D array
    const nlohmann::json& occupied_json = j.at("occupied");
    for (size_t i = 0; i < 5; ++i) {
        for (size_t j = 0; j < 12; ++j) {
            occupied[i][j] = occupied_json.at(i).at(j);
        }
    }

}

Field_manager::Field_manager() {

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 12; ++j) {
            occupied[i][j] = 0; // Initialize the occupied array
        }
    }

    field_managers;
    counter++;

}

Field_manager Field_manager::build_from_json(string json_str) {
    nlohmann::json j = nlohmann::json::parse(json_str);
    Field_manager fm;
    fm.from_json(j);
    return fm;
}


