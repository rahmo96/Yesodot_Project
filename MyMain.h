//
// Created by חי כרמי on 13/02/2024.
//

#ifndef YESODOT_PROJECT_MYMAIN_H
#define YESODOT_PROJECT_MYMAIN_H
#include <iostream>
using namespace std;

class MyMain {
public:
    void print_Menu_login_registration();
    MyMain();    // Class constructor
    void print_Menu_player_field_manger();
//Clears the buffer
static void clear_the_buffer() {
        while (getchar() != '\n') {
        }
    }

 static bool check_ID(long id) {
     if (id < 10000000 || id > 1000000000) {
         return false;
     }

     return true;
 }

};


#endif //YESODOT_PROJECT_MYMAIN_H
