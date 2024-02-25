//
// Created by חי כרמי on 11/02/2024.
//

#include "Player.h"
#include "User.h"
#include <iostream>
#include <string>

using namespace std;


Player::Player(string name ,long id, string address, long phone_num,char gender, Date birthday,Field *field): User(name,  id,  address,  phone_num, gender,birthday) {
this->field=field;
}

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
