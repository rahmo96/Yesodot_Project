//
// Created by חי כרמי on 11/02/2024.
//

#ifndef YESODOT_PROJECT_PLAYER_H
#define YESODOT_PROJECT_PLAYER_H
#include <iostream>
#include <string>

using namespace std;

class Player {
private:
    string name; // Consider using std::string for better memory management
    string id;
    string Address;
    long phone_number;
public:
    Player();
    Player(const Player &player);
    void Set_Name(string name){ this->name=name;}


};


#endif //YESODOT_PROJECT_PLAYER_H
