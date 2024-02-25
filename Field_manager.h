//
// Created by חי כרמי on 21/02/2024.
//

#ifndef YESODOT_PROJECT_FIELD_MANAGER_H
#define YESODOT_PROJECT_FIELD_MANAGER_H

#include "User.h"
#include "Field.h"
#include <vector>
class Field_manager: public virtual User{
private:
    vector<Field> field;
public:
    Field_manager(string name, long id, string address, long phone_num,char gender,Date b_day): User(name, id, address, phone_num,gender,b_day){}
    Field_manager(string name, long id, string address, long phone_num,char gender,Date b_day,vector<Field> field1);
    Field_manager(const Field_manager &fieldManager);
    void print() override;
    Field_manager &operator+=(const Field_manager &fieldManager);





};


#endif //YESODOT_PROJECT_FIELD_MANAGER_H
