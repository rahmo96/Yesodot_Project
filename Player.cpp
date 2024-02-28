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