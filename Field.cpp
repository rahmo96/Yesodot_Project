//
// Created by jacob on 13/02/2024.
//

#include "Field.h"
#include <iostream>
#include "string"

Field::Field(string field_name, string field_type, string field_city,string description) {
    this->field_name = field_name;
    this->field_city = field_city;
    this->field_type = field_type;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 12; ++j) {
            this->occupied[i][j] = 0;
        }
    }

    this->rating = 0;
    this->counter_rating = 0;

    this->description=description;
}

Field::Field(const Field &other) {
    this->field_name = other.field_name;
    this->field_type = other.field_type;
    this->field_city = other.field_city;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 12; ++j) {
            this->occupied[i][j] = other.occupied[i][j];
        }
    }
}


void Field::print() const {
    cout << "The field sport name is: " << field_name << " " << endl;
    cout << "_______" << endl;
    cout << "The field sport type is: " << field_type << " " << endl;
    cout << "Located in: " << field_city << endl;
    print_rating();
    cout << "_______" << endl;
}
void Field::print_rating() const {
    cout << "the rate is: " << rating << endl;
    cout << "Number of ratings is: " << counter_rating << endl;
}



Field Field::operator=(const Field &other) {
    this->field_name = other.field_name;
    this->field_city = other.field_city;
    this->field_type = other.field_type;
    return *this;
}

void Field::Rating_change(float rat){
    counter_rating++;
    rating=(rat+rating)/counter_rating;
}



Field::Field() {
    this->field_name = "";
    this->field_type = "";
    this->field_city = "";

}

bool Field::operator!=(const Field &other) {
    if (field_name != other.field_name)
        return true;
    if (field_city != other.field_city)
        return true;
    if (field_type != other.field_type)
        return true;

    return false;

}

void Field::to_json(json &j) const {

    nlohmann::json occupied_json;
    for (size_t i = 0; i < 5; ++i) {
        nlohmann::json row_json;
        for (size_t k = 0; k < 12; ++k) {
            row_json.push_back(occupied[i][k]);
        }
        occupied_json.push_back(row_json);
    }


    j = {
            {"Field_name", field_name},
            {"Field_type", field_type},
            {"Field_city", field_city},
            {"Occupied", occupied_json},
            {"Rating", rating},
    };

}

void Field::from_json(const json &j) {

    field_name = j.at("Field_name");
    field_type = j.at("Field_type");
    field_city = j.at("Field_city");

    const json& occupied_json = j.at("Occupied");
    for (size_t i = 0; i < occupied_json.size(); ++i) {
        const json& row_json = occupied_json[i];
        for (size_t k = 0; k < row_json.size(); ++k) {
            occupied[i][k] = row_json[k];
        }
    }
    rating = j.at("Rating");

}

Field Field::add_field() {
    string name, type, city, description;
    cout << "Enter field name: " << endl;
    cin >> name;
    cout << "Enter field type: " << endl;
    cin >> type;
    cout << "Enter field city: " << endl;
    cin >> city;

    cout << "Would you like to add description? (y/n)" << endl;
    string answer;
    cin >> answer;
    while (answer != "y" && answer != "Y" && answer != "n" && answer != "N") {
        cout << "Invalid input. Please enter 'y' or 'n'." << endl;
        cin >> answer;
    }

    if (answer == "y" || answer == "Y") {
        cout << "Enter description: " << endl;
        cin.ignore(); // Ignore newline character from previous cin
        getline(cin, description);
    } else {
        description = "no description";
    }

    return Field(name, type, city, description);
}


bool Field::operator==(const Field &other) {

    if (field_name != other.field_name)
        return false;
    if (field_city != other.field_city)
        return false;
    if (field_type != other.field_type)
        return false;

    return true;
}

bool Field::is_field_booked_by(long id) const {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 12; ++j) {
            if (occupied[i][j] == id) {
                return true;
            }
        }
    }
    return false;
}

bool Field::cancel_booking(long id) {
    bool cancelled = false;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 12; ++j) {
            if (occupied[i][j] == id) {
                occupied[i][j] = 0; // Assuming 0 represents an unoccupied slot
                cancelled = true;
            }
        }
    }
    return cancelled;
}
void Field::close_field(int choice2, int startHour,int endHour){

    for (int i = startHour; i < endHour; ++i) {
        occupied[choice2-1][i-8] = 1;

    }
}





