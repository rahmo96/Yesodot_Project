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
#include "sqlite3.h"
using namespace std;


class Player : virtual public User {
private:
    friend class Functions;
    friend class MyMain;
    vector<Field> field;
    Favorites f;

public:
    Player()=default;
    Player(string name, long id, string address, long phone_num,char gender, Date birthdy,string passowrd): User(name, id, address, phone_num,gender,birthdy,passowrd){};
    Player(const string &name, const long &id, const string &address, const long &phone_num, const char &gender, const Date &b_day, const string &passowrd, const vector<Field> &field, const Favorites &f): User(name, id, address, phone_num,gender,b_day,passowrd), field(field), f(f){};
    Player(const Player &player);
    void print() override;

    //Getters
    vector<Field> Get_field() const {return field;};
    Favorites get_f() const {return f;};
    //Setters
    void Set_player(string name, long id, string address, long phone_num,char gender, Date birthdy,string passowrd, vector<Field> field, Favorites f);

    //Send it to json
    void to_json(nlohmann::json& j);
    //Get it from json
    void from_json(const nlohmann::json& j);

    static Player build_from_DB(long id);


};


#endif //YESODOT_PROJECT_PLAYER_H
