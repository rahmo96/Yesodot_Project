//
// Created by חי כרמי on 11/02/2024.
//

#ifndef YESODOT_PROJECT_PLAYER_H
#define YESODOT_PROJECT_PLAYER_H
#include <iostream>
#include <string>
#include "Date.h"
#include "User.h"
#include "Field.h"
#include "Favorites.h"
#include "vector"


using namespace std;

class Player: public virtual User{
private:
    vector<Field> field;
    Favorites f;

public:
    Player(string name, long id, string address, long phone_num,char gender, Date birthdy);
    Player(const Player &player);
    void print() override;

};


#endif //YESODOT_PROJECT_PLAYER_H
