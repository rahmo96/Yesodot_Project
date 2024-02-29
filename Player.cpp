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

    // Merge all JSON objects into one

    j.merge_patch({
                          {"Name", name},
                          {"id", id},
                          {"address", Address},
                          {"phone_num", phone_number},
                          {"gender", std::string(1, gender)},
                          {"b_day", date_to_string()},
                          {"password", passowrd},
                          {"Field", field_json},
                          {"Favorites", favorites_json}
                  });
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
        json j = User::P_from_DB(id);
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
        const nlohmann::json& field_json = j.at("Field");
        for (const auto& field_obj : field_json) {
            Field field_item;
            field_item.from_json(field_obj);
            fields.push_back(field_item);
        }

        Favorites f;
        const nlohmann::json& favorites_json = j.at("Favorites");
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

Player Player::set_Player_from_json(json j) {
    Player p;
    p.name = j.at("Name");
    p.id = j.at("id");
    p.Address = j.at("address");
    p.phone_number = j.at("phone_num");
    string g = j.at("gender");
    p.gender =g[0];
    p.b_day.setDateFromString(j.at("b_day"));
    p.passowrd = j.at("password");
    const nlohmann::json& field_json = j.at("Field");
    for (const auto& field_obj : field_json) {
        Field field_item;
        field_item.from_json(field_obj);
        p.field.push_back(field_item);
    }
    const nlohmann::json& favorites_json = j.at("Favorites");
    p.f.from_json(favorites_json);
    return p;

}

bool Player::update_to_DB() {
    // Serialize the updated Player object to a JSON string
    nlohmann::json player_data;
    this->to_json(player_data);

    sqlite3 *db;
    if (sqlite3_open("Test player data DB.db", &db) != SQLITE_OK) {
        std::cerr << "Error opening database" << std::endl;
        return false;
    }

    // Update the Class_data column in the database with the updated JSON string
    std::string update_query =
            "UPDATE [Player_Accounts] SET [Class_data] = '" + player_data.dump() + "' WHERE id = " +
            std::to_string(this->Get_id());
    const char *sql = update_query.c_str();
    if (sqlite3_exec(db, sql, nullptr, nullptr, nullptr) != SQLITE_OK) {
        std::cerr << "Error updating database" << std::endl;
        sqlite3_close(db);
        return false;
    }

    sqlite3_close(db);
    return true;


}

