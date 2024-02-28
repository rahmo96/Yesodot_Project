//
// Created by חי כרמי on 11/02/2024.
//

#ifndef YESODOT_PROJECT_PLAYER_H
#define YESODOT_PROJECT_PLAYER_H
#include <iostream>
#include <string>
#include "User.h"
#include "Date.h"
#include "Field.h"
#include "Favorites.h"
#include "vector"
using namespace std;


class Player : virtual public User {
private:
    friend class Functions;
    vector<Field> field;
    Favorites f;

public:
    Player(string name, long id, string address, long phone_num,char gender, Date birthdy,string passowrd): User(name, id, address, phone_num,gender,birthdy,passowrd){};
    Player(const Player &player);
    void print() override;

    //Getters
    vector<Field> Get_field() const {return field;};
    Favorites get_f() const {return f;};
    //Setters
    void set_field(const vector<Field> &field);
    void set_f(const Favorites &f);

    //Send it to json
    void to_json(nlohmann::json& j);
    //Get it from json
    void from_json(const nlohmann::json& j);

};


#endif //YESODOT_PROJECT_PLAYER_H
