//
// Created by raha1 on 21/02/2024.
//
#include "Field.h"
#include "nlohmann/json.hpp"
#ifndef YESODOT_PROJECT_FAVORITES_H
#define YESODOT_PROJECT_FAVORITES_H


class Favorites {
private:
    Field *favorite_field;
    int size;

public:
    Favorites();
    Favorites(Field *favorite_field, int size);
    Favorites(const Favorites &other);
    //void set_favorite_field(Field *favorite_field);
    //void set_size(int size);
    Field *get_favorite_field();
    int get_size() const {return size;};
    void print();
    Favorites operator+=(Field& f_field);
    Favorites operator-=(Field& f_field);
    Favorites &operator=(const Favorites &f_field);

    //send it to json
    void to_json(nlohmann::json& j) const;
    //get it from json
    void from_json(const nlohmann::json& j);


};


#endif //YESODOT_PROJECT_FAVORITES_H
