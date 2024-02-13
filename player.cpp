//
// Created by חי כרמי on 11/02/2024.
//

#include "player.h"

Player::Player(const Player &player) {
    this->name = player.name;
    this->id = player.id;
}

Player::Player(string namme, string id, string address, long phone_num, Date birthdy) {
    this->name = namme;
    this->id = id;
    this->phone_number = phone_num;
    this->Birthday = birthdy;
    this->Address = address;
}

void Player::print_player() {
    cout << "the name is:" << this->name << endl;
    cout << "the id is:" << id << endl;
    cout << "the Address is:" << Address << endl;
    cout << "the phone num is:" << phone_number << endl;
    cout << "the Birthday is:";
    Birthday.print();


}
