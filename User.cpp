//
// Created by חי כרמי on 20/02/2024.
//

#include "User.h"

User::User(const User &user) {

    this->name = user.name;
    this->id = user.id;
    this->phone_number = user.phone_number;
    this->Address = user.Address;
    this->gender = user.gender;
    this->b_day = user.b_day;
    //
    this->passowrd = user.passowrd;
}

User::User(string name, long id, string address, long phone_num, char gender, Date b_day, string password) {
    this->name = name;
    this->id = id;
    this->phone_number = phone_num;
    this->Address = address;
    this->gender = gender;
    this->b_day = b_day;
    this->passowrd = password;
}

void User::print() {
    cout << "the name is:" << this->name << endl;
    cout << "the id is:" << id << endl;
    cout << "the Address is:" << Address << endl;
    cout << "the phone num is:" << phone_number << endl;
    cout << "the gender is:" << gender << endl;
    cout << "the birth day is:" << date_to_string() << endl;
    }

string User::date_to_string() {
        if (b_day.check_valid_date())
            return to_string(b_day.get_Day()) + "-" + to_string(b_day.get_Month()) + "-" + to_string(b_day.get_Year());
        else
            return "";
}

void User::Set_Name() {
    string name;
    cout<<"Enter name: "<<endl;
    cin>>name;
    this->name=name;

}

void User::Set_phone_number() {
    long phone_num;
    cout<<"Enter phone number: "<<endl;
    cin>>phone_num;
    this->phone_number=phone_num;

}

void User::Set_gender() {
    char gender;
    cout<<"Enter gender: "<<endl;
    cin>>gender;
    this->gender=gender;
}

void User::Set_Address() {
    string address;
    cout<<"Enter address: "<<endl;
    cin>>address;
    this->Address=address;
}

void User::Set_password() {
    string old_password;
    cout<<"Enter old password: "<<endl;
    cin>>old_password;
    if (old_password==this->passowrd){
        string new_password;
        cout<<"Enter new password: "<<endl;
        cin>>new_password;
        this->passowrd=new_password;
    } else{
        cout<<"Wrong password"<<endl;
        return;
    }


}

void User::to_json(nlohmann::json &j) {

    j = {
            {"name", name},
            {"id", id},
            {"address", Address},
            {"phone_num", phone_number},
            {"gender", gender},
            {"b_day", date_to_string()},
            {"password", passowrd}
    };

}

void User::from_json(const nlohmann::json &j) {

    name = j["name"];
    id = j["id"];
    Address = j["address"];
    phone_number = j["phone_num"];
    passowrd = j["password"];

}


