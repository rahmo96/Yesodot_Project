//
// Created by חי כרמי on 11/02/2024.
//

#include "player.h"

Player::Player(const Player &player) {
    this->name = player.name;
    this->id = player.id;
}

Player::Player(string namme, string id, string address, long phone_num, Date birthdy) {

}
