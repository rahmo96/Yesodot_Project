//
// Created by חי כרמי on 21/02/2024.
//

#ifndef YESODOT_PROJECT_FIELD_MANAGER_H
#define YESODOT_PROJECT_FIELD_MANAGER_H

#include "User.h"
#include "Field.h"
class Field_manager: public virtual User{
private:
public:
    Field_manager(string namme, long id, string address, long phone_num, Date birthdy ,Field* field1);
    Field_manager(const Field_manager &fieldManager);


};


#endif //YESODOT_PROJECT_FIELD_MANAGER_H
