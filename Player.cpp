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
    this->booked = player.booked;
    this->f = player.f;
}

void Player::print() {
    User::print();
    cout<<"-----"<<endl;
    cout<<"Favorite fields: "<<endl;
    cout<<"-----"<<endl;
    f.print();
    cout<<"-----"<<endl;

}

void Player::Set_Name() {
    string name;
    cout<<"Enter new name (or 0 to return to previous menu): "<<endl;
    cin.ignore();
    getline(cin , name);
    if (name=="0"){
        return;
    }
    this->name=name;
    P_send_name_to_DB(name);
    this->update_to_DB();

}

void Player::Set_phone_number() {
    while (true) {
        string t_phone_num;
        long phone_num;
        cout << "Enter new phone number:(or 0 to return to previous menu) " << endl;
        cin.ignore();
        getline(cin , t_phone_num);
        if (t_phone_num=="0"){
            return;
        }
        try {
            phone_num = stol(t_phone_num);
        } catch (const exception &e) {
            cout << "Invalid phone number. Please try again." << endl;
            continue; // Ask for phone number again
        }
        if ( phone_num<100000000 || phone_num>999999999){
            cout << "Invalid phone number. Please try again." << endl;
            continue; // Ask for phone number again
        }
        this->phone_number = phone_num;
        P_send_phone_number_to_DB(phone_num);
        this->update_to_DB();
        break; // Exit the loop if a valid phone number is provided
    }
}




void Player::Set_Address() {
    string address;
    cout<<"Enter new address (or 0 to return to previous menu): "<<endl;
    cin.ignore();
    getline(cin, address);
    if (address=="0"){
        return;
    }
    this->Address=address;
    P_send_address_to_DB(address);
    this->update_to_DB();
}

void Player::Set_password() {
    string old_password;
    cout<<"Enter old password: (or 0 to return to previous menu): "<<endl;
    cin.ignore();
    getline(cin, old_password);
    if (old_password=="0"){
        return;
    }
    if (old_password==this->passowrd){
        string new_password;
        cout<<"Enter new password: "<<endl;
        getline(cin , new_password);
        this->passowrd=new_password;
        P_send_password_to_DB(new_password);
    } else{
        cout<<"Wrong password"<<endl;
        return;
    }

    this->update_to_DB();


}


void Player::to_json(nlohmann::json &j) {
    json player_data_json;
    User::to_json(player_data_json);

    nlohmann::json booked_json;
    booked.to_json(booked_json);

    json favorites_json;
    f.to_json(favorites_json);

    j={
            {"Name",             name},
            {"id",               id},
            {"address",          Address},
            {"phone_num",        phone_number},
            {"b_day",            date_to_string()},
            {"gender",           string (1, gender)},
            {"password",         passowrd},
            {"Booked",            booked_json},
            {"Favorites",        favorites_json}
    };
}


void Player::from_json(const nlohmann::json& j) {
    this->booked.booked_fields.clear();
    User::from_json(j);
    const nlohmann::json& booked_json = j.at("Booked");
    booked.from_json(booked_json);
    const nlohmann::json& favorites_json = j.at("Favorites");
    f.from_json(favorites_json);


}

void
Player::Set_player(string name, long id, string address, long phone_num, char gender, Date birthdy, string passowrd,
                   Booked &booked, Favorites &f) {
    this->name = name;
    this->id = id;
    this->Address = address;
    this->phone_number = phone_num;
    this->gender = gender;
    this->b_day = birthdy;
    this->passowrd = passowrd;
    this->booked = booked;
    this->f = f;

    std::cout << "Favorites size in Set_player: " << f.get_size() << std::endl;
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

        Booked fields;
        fields.from_json(j.at("Booked"));




        Favorites f;
        f.from_json(j.at("Favorites"));

        Player p(name, id, Address, phone_number, gender, b_day, password, fields, f);

        return p;


    } catch (const std::exception& e) {
        std::cerr << "Error building Player from JSON: " << e.what() << std::endl;
        // Handle the error appropriately, such as returning a default-constructed Player or re-throwing the exception
        throw;
    }
}


bool Player::update_to_DB() {
    // Serialize the updated Player object to a JSON string
    nlohmann::json player_data;
    this->to_json(player_data);
    string json_string = player_data.dump();

    sqlite3* db;
    if (sqlite3_open("Test player data DB.db", &db) != SQLITE_OK) {
        std::cerr << "Error opening database" << std::endl;
        return false;
    }

    sqlite3_stmt* stmt;
    const char* update_query = "UPDATE [Player_Accounts] SET [Class_data] = ? WHERE id = ?";
    if (sqlite3_prepare_v2(db, update_query, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Error preparing update statement" << std::endl;
        sqlite3_close(db);
        return false;
    }

    sqlite3_bind_text(stmt, 1, json_string.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, this->Get_id());

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Error updating database" << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return false;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return true;
}

Player Player::operator=(const Player &other) {
    this->name = other.name;
    this->id = other.id;
    this->Address = other.Address;
    this->phone_number = other.phone_number;
    this->gender = other.gender;
    this->b_day = other.b_day;
    this->passowrd = other.passowrd;
    this->booked = other.booked;
    this->f = other.f;
    return *this;
}

bool Player::isIdInDatabase(long id) {
    sqlite3* db;
    if (sqlite3_open("Test player data DB.db", &db) != SQLITE_OK) {
        std::cerr << "Error opening database" << std::endl;
        return false;
    }

    std::string query = "SELECT COUNT(*) FROM [Player_Accounts] WHERE id = ?";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Error preparing statement" << std::endl;
        sqlite3_close(db);
        return false;
    }

    sqlite3_bind_int64(stmt, 1, id);

    int result = sqlite3_step(stmt);
    bool idExists = false;
    if (result == SQLITE_ROW) {
        int count = sqlite3_column_int(stmt, 0);
        idExists = count > 0;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return idExists;
}




