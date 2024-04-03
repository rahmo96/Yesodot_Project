//
// Created by raha1 on 21/02/2024.
//

#include "Favorites.h"
#include "nlohmann/json.hpp"

using namespace std;
using namespace nlohmann;

Favorites::Favorites() : favorite_field() {}


Favorites::Favorites(const Favorites &other) {
    for (const auto &field_item : other.favorite_field) {
        favorite_field.push_back(field_item);
    }


}


vector<Field> Favorites::get_favorite_field() {
    return favorite_field;
}


void Favorites::print() {
    if (favorite_field.size() == 0) {
        cout << "No favorite fields yet " << endl;
        return;
    }
    for (int i = 0; i < favorite_field.size(); ++i) {
        favorite_field[i].print();
        cout << endl;
    }
    int choice;
    do {
        cout << "Enter 0 to exit" << endl;
        cin >> choice;
        if (cin.fail() || choice != 0) {
            cout << "Invalid choice. Please try again." << endl;
            cin.clear();
            choice = 1;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (choice != 0);
}

Favorites Favorites::operator+=(Field &f_field) {
    this->favorite_field.push_back(f_field);
    return *this;

}

Favorites Favorites::operator-=(Field &f_field) {
    vector<Field> new_field;
    int j = 0;
    for (int i = 0; i <favorite_field.size(); ++i) {
        if (favorite_field[i] != f_field) {
            new_field[j] = favorite_field[i];
            j++;
        }
    }

    favorite_field = new_field;
    return *this;
}

void Favorites::to_json(json &j) const {
    nlohmann::json array_json;
    for (int i = 0; i <favorite_field.size(); ++i) {
        nlohmann::json field_json;
        favorite_field[i].to_json(field_json); // Assuming Field has a to_json method
        array_json.push_back(field_json);
    }
    j = {
            {"favorite_field", array_json},
    };
}



Favorites& Favorites::operator=(const Favorites& f_field) {

        for (const auto &field_item : f_field.favorite_field) {
            favorite_field.push_back(field_item);
        }

    return *this;
}

void Favorites::from_json(const json &j) {

    const json& array_json = j.at("favorite_field");
    for (const auto& field_obj : array_json) {
        Field field_item;
        field_item.from_json(field_obj);
        favorite_field.push_back(field_item);
    }

}

int Favorites::get_size() {
    return favorite_field.size();
}





