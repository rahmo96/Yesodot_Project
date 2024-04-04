//
// Created by raha1 on 21/02/2024.
//
#include "Field.h"
#include "nlohmann/json.hpp"
#include "sqlite3.h"
#include "Clear_Screen.h"
#include <thread>
#include <chrono>

#ifndef YESODOT_PROJECT_FAVORITES_H
#define YESODOT_PROJECT_FAVORITES_H


class Favorites {
private:
    vector<Field> favorite_field;

public:
    Favorites();
    Favorites(const Favorites &other);
    //void set_favorite_field(Field *favorite_field);
    //void set_size(int size);
    vector<Field> get_favorite_field();
    void print();
    Favorites operator+=(Field& f_field);
    Favorites operator-=(Field& f_field);
    Favorites &operator=(const Favorites &f_field);

    int get_size();

    static Favorites get_player_favorites( string id);

    //send it to json
    void to_json(nlohmann::json& j) const;
    //get it from json
    void from_json(const nlohmann::json& j);


};


#endif //YESODOT_PROJECT_FAVORITES_H
