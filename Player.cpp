//
// Created by חי כרמי on 11/02/2024.
//

#include "Player.h"
#include "User.h"
#include <iostream>
#include <string>

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
