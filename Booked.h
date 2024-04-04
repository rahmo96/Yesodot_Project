//
// Created by raha1 on 02/03/2024.
//

#ifndef YESODOT_PROJECT_BOOKED_H
#define YESODOT_PROJECT_BOOKED_H
#include <vector>
#include "Field.h"
#include <iostream>
#include "Clear_Screen.h"
#include <thread>
#include <chrono>
using namespace std;


class Booked {
private:
    friend class Field;
    friend class Functions;
    friend class MyMain;
    friend class Player;
    vector<Field > booked_fields;
    long occupied_slots[5][12];
public:
    Booked() : booked_fields(), occupied_slots() {}

    Booked(vector<Field > booked_fields, long occupied_slots[5][12]) {
        this->booked_fields = move(booked_fields);
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 12; ++j) {
                this->occupied_slots[i][j] = occupied_slots[i][j];
            }
        }
    }

    Booked(const Booked &other) {
        this->booked_fields = other.booked_fields;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 12; ++j) {
                this->occupied_slots[i][j] = other.occupied_slots[i][j];
            }
        }
    }

    Booked &operator=(const Booked &other) {
        if (this != &other) {
            this->booked_fields = other.booked_fields;
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 12; ++j) {
                    this->occupied_slots[i][j] = other.occupied_slots[i][j];
                }
            }
        }
        return *this;
    }

    void setOccupied_slots(int row, int col, long id) {
        occupied_slots[row][col] = id;

    }

    vector<Field> getBooked_fields() const { return booked_fields; }

    long get_occupied_slots(int row, int col) const { return occupied_slots[row][col]; }

    void to_json(nlohmann::json &j) {
        nlohmann::json booked_fields_json;
        for (const auto &field_item : booked_fields) {
            nlohmann::json field_obj;
            field_item.to_json(field_obj); // Assuming Field has a to_json method
            booked_fields_json.push_back(field_obj);
        }

        j["booked_fields"] = booked_fields_json;
        j["occupied_slots"] = occupied_slots;
    }

    void from_json(const nlohmann::json &j) {
        const nlohmann::json &booked_fields_json = j.at("booked_fields");
        for (const auto &field_obj : booked_fields_json) {
            Field field_item; // Assuming Field has a from_json constructor
            field_item.from_json(field_obj);
            booked_fields.push_back(field_item);
        }

        const nlohmann::json &occupied_slots_json = j.at("occupied_slots");
        for (int i = 0; i < 5; ++i) {
            for (int k = 0; k < 12; ++k) {
                occupied_slots[i][k] = occupied_slots_json[i][k].get<long>();
            }
        }
    }

    void print_booked_fields(long id) {
        string days[5] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday" };
        if (booked_fields.empty()) {
            cout << "No booked fields found." << endl;
            int choice;
            do{
                cout<<"Press '0' to return to main menu"<<endl;
                cin>>choice;
                if (cin.fail()){
                    cin.clear();
                    cout<<"Invalid input. Please enter a number"<<endl;
                }
            } while (choice != 0);

        }
        for (const auto& field_item : booked_fields) {
            field_item.print();
            cout << endl;
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 12; ++j) {
                    if (occupied_slots[i][j] == id && occupied_slots[i][j] == field_item.get_occupied(i, j)) {
                        cout << "Day: " << days[i] << " Time: " << j + 8 << ":00" << endl;
                    }
                }
            }
        }

        int choice;
        do{
            cout<<"Press '0' to return to main menu"<<endl;
            cin>>choice;
            if (cin.fail()){
                cin.clear();
                cout<<"Invalid input. Please enter a number"<<endl;
            }
        } while (choice != 0);

        cout<< "\n\n";
        Clear::clear_screen();
    }

    bool remove_booking(long id) {
        auto it = std::remove_if(booked_fields.begin(), booked_fields.end(), [&](const Field& field) {
            return field.is_field_booked_by(id);
        });

        if (it != booked_fields.end()) {
            booked_fields.erase(it, booked_fields.end());
            return true;
        }

        return false;
    }
    bool isAvailable(int dayIndex, int hourIndex);

    void remove_booking_by_day_hour(long id ,int dayIndex, int hourIndex);


};



#endif //YESODOT_PROJECT_BOOKED_H
