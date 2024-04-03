//
// Created by raha1 on 02/03/2024.
//

#include "Booked.h"

bool Booked::isAvailable(int dayIndex, int hourIndex) {
    return occupied_slots[dayIndex][hourIndex] == 0; // Assuming 0 means the slot is available
}

void Booked::remove_booking_by_day_hour(long id, int dayIndex, int hourIndex) {
    if (occupied_slots[dayIndex][hourIndex] == id) {
        occupied_slots[dayIndex][hourIndex] = 0; // Assuming 0 means the slot is available()
    }
    for(auto &field : booked_fields){
        if(field.is_field_booked_by(id))
            return;

    }

}

