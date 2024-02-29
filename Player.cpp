//
// Created by חי כרמי on 11/02/2024.
//

#include "Player.h"
#include "User.h"
#include <iostream>
#include <string>
#include "nlohmann/json.hpp"
#include "vector"

using namespace nlohmann;


using namespace std;


Player::Player(const Player &player) : User(player){
    this->field = player.field;
}

void Player::print() {
    User::print();
    cout<<"-----"<<endl;
    cout<<"Favorite fields: "<<endl;
    cout<<"-----"<<endl;
    f.print();
    cout<<"-----"<<endl;

}

void Player::to_json(nlohmann::json &j) {
    json player_data_json;
    User::to_json(player_data_json);
    nlohmann::json field_json = nlohmann::json::array();
    for (const auto &field_item : field) {
        nlohmann::json field_obj;
        field_item.to_json(field_obj); // Assuming Field has a to_json method
        field_json.push_back(field_obj);
    }
    json favorites_json;
    f.to_json(favorites_json);

    j = {
            {"Player", player_data_json},
            {"Field", field_json},
            {"Favorites", favorites_json}
    };

}


void Player::from_json(const nlohmann::json& j) {
    this->field.clear();
    const nlohmann::json& field_json = j.at("field");
    for (const auto& field_obj : field_json) {
        Field field_item;
        field_item.from_json(field_obj);
        field.push_back(field_item);
    }
}

void
Player::Set_player(string name, long id, string address, long phone_num, char gender, Date birthdy, string passowrd,
                   vector<Field> field, Favorites f) {
    this->name = name;
    this->id = id;
    this->Address = address;
    this->phone_number = phone_num;
    this->gender = gender;
    this->b_day = birthdy;
    this->passowrd = passowrd;
    this->field = field;
    this->f = f;
}

Player Player::build_from_DB(long id) {
    try {
        json j = User::from_DB(id);
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
        const nlohmann::json& field_json = j.at("field");
        for (const auto& field_obj : field_json) {
            Field field_item;
            field_item.from_json(field_obj);
            fields.push_back(field_item);
        }

        Favorites f;
        const nlohmann::json& favorites_json = j.at("favorites");
        f.from_json(favorites_json);
        Player p;
        p.Set_player(name, id, Address, phone_number, gender, b_day, password, fields, f);
        return p;

    } catch (const std::exception& e) {
        std::cerr << "Error building Player from JSON: " << e.what() << std::endl;
        // Handle the error appropriately, such as returning a default-constructed Player or re-throwing the exception
        throw;
    }
}

