//
// Created by חי כרמי on 11/02/2024.
//

#ifndef YESODOT_PROJECT_PLAYER_H
#define YESODOT_PROJECT_PLAYER_H
#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class Player {
private:
    string name;
    string id;
    string Address;
    long phone_number;
    Date Birthday;

public:
    Player(string namme, string id,string address, long phone_num,Date birthdy);
    Player(const Player &player);
    void Set_Name(string name){ this->name=name;}


};


#endif //YESODOT_PROJECT_PLAYER_H
