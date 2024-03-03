//
// Created by חי כרמי on 21/02/2024.
//

#ifndef YESODOT_PROJECT_FIELD_MANAGER_H
#define YESODOT_PROJECT_FIELD_MANAGER_H

#include "User.h"
#include "Field.h"
#include <vector>
#include "Player.h"
class Field_manager: virtual public User{
private:
    friend class Functions;
    friend class MyMain;
    static int counter;
    static vector<Field_manager*> field_managers;
    vector<Field> field;
    bool promoting_funded;
public:
    Field_manager():User() {

        promoting_funded = 0;
        counter++;

    }
    Field_manager(string name, long id, string address, long phone_num,char gender,Date b_day,string passowrd, bool promoting_funded=0): User(name, id, address, phone_num,gender,b_day,passowrd){counter++;}
    Field_manager(string name, long id, string address, long phone_num,char gender,Date b_day,string passowrd,vector<Field> field1, bool promoting_funded=0);
    Field_manager(const Field_manager& fieldManager)
            : User(fieldManager), field(fieldManager.field) {
        promoting_funded = fieldManager.promoting_funded;
        counter++;
    };
    void print() override;
    Field_manager &operator+=(const Field_manager &fieldManager);

    //booking helpers
    bool is_hour_occupied(const std::string& city, int day, int hour) const;
    bool is_day_occupied(const std::string& city, int day) const;
    void book_field_in_city_at_day_hour(long id, const std::string& city, int day, int hour);
    void find_fields_with_id(long id);
    bool is_field_booked_by(long id);
    bool cancel_field_booking(long id);
    void set_promoting_funded(bool prom){promoting_funded=prom;}


    //Getters
    vector<Field> Get_field() const {return field;};
    static vector<Field_manager*> Get_field_managers() {return field_managers;}

    //Setters
    void Set_field_manager(string name, long id, string address, long phone_num, char gender, Date b_day, string passowrd, vector<Field> field1, bool promoting_funded);

//send it to json
    void to_json(nlohmann::json& j);
    //get it from json
    Field_manager from_json(const nlohmann::json& j);

    //Build from json
    Field_manager build_from_json(string json_str);
    static Field_manager build_from_DB(long id);

    bool update_to_DB();

    bool cancel_field_booking(long id, const Field& field);

    bool field_contains(const Field& field) {
        for (auto& f : this->field) {
            if (f == field) {
                return true;
            }
        }
        return false;
    }

    //Remove field from field_managers
    void remove_field_manager(vector<Field_manager*> &field_managers);

    bool Pay_to_be_first();


};


#endif //YESODOT_PROJECT_FIELD_MANAGER_H
