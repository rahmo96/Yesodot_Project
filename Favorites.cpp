//
// Created by raha1 on 21/02/2024.
//

#include "Favorites.h"

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

int Favorites::get_size() {
    return size;
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

//Favorites Favorites::operator-=(Field &f_field) {
//    Field *new_field = new Field[size - 1];
//    int j = 0;
//    for (int i = 0; i < size; ++i) {
//        if (favorite_field[i] != f_field) {
//            new_field[j] = favorite_field[i];
//            j++;
//        }
//    }
//    delete[] favorite_field;
//    favorite_field = new_field;
//    size--;
//    return *this;
//}
//
