//
// Created by raha1 on 21/02/2024.
//

#include "Favorites.h"
#include "nlohmann/json.hpp"

using namespace std;
using namespace nlohmann;

Favorites::Favorites() : favorite_field(nullptr), size(0) {}

Favorites::Favorites(Field *favorite_field, int size) {
    this->favorite_field = favorite_field; // make a copy of this
    this->size = size;
}

Favorites::Favorites(const Favorites &other) {
    this->size = other.size;
    this->favorite_field=new Field[size];
    for (int i = 0; i < size; ++i) {
        this->favorite_field[i]=other.favorite_field[i];
    }

}


Field *Favorites::get_favorite_field() {
    return favorite_field;
}

void Favorites::print() {
    if (size == 0) {
        cout << "No favorite fields yet " << endl;
        return;
    }
    for (int i = 0; i < size; ++i) {
        favorite_field[i].print();
        cout << endl;
    }

}

Favorites Favorites::operator+=(Field &f_field) {
    Field *new_field = new Field[size + 1];
    for (int i = 0; i < size; ++i) {
        new_field[i] = favorite_field[i];
    }
    new_field[size] = f_field;
    delete[] favorite_field;
    favorite_field = new_field;
    size++;
    return *this;
}

Favorites Favorites::operator-=(Field &f_field) {
    Field *new_field = new Field[size - 1];
    int j = 0;
    for (int i = 0; i < size; ++i) {
        if (favorite_field[i] != f_field) {
            new_field[j] = favorite_field[i];
            j++;
        }
    }
    delete[] favorite_field;
    favorite_field = new_field;
    size--;
    return *this;
}

void Favorites::to_json(json &j) const {
    nlohmann::json array_json;
    for (int i = 0; i < size; ++i) {
        nlohmann::json field_json;
        favorite_field[i].to_json(field_json); // Assuming Field has a to_json method
        array_json.push_back(field_json);
    }
    j = {
            {"favorite_field", array_json},
            {"size", size}
    };
}



Favorites& Favorites::operator=(const Favorites& f_field) {
    if (this != &f_field) {
        this->size = f_field.size;
        delete[] this->favorite_field;
        this->favorite_field = new Field[size];
        for (int i = 0; i < size; ++i) {
            this->favorite_field[i] = f_field.favorite_field[i];
        }
    }
    return *this;
}

void Favorites::from_json(const json &j) {
    size = j.at("size");
    delete[] favorite_field;
    favorite_field = new Field[size];
    for (int i = 0; i < size; ++i) {
        favorite_field[i].from_json(j["favorite_field"][i]);
    }

}

