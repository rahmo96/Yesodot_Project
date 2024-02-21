//
// Created by חי כרמי on 11/02/2024.
//

#include "Player.h"
#include "User.h"
#include <iostream>
#include <string>

using namespace std;


Player::Player(string name ,long id, string address, long phone_num, Date birthday,Field field): User(name,  id,  address,  phone_num,  birthday) {
this->field=field;
}
