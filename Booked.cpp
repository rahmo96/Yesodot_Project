//
// Created by raha1 on 02/03/2024.
//

#include "Booked.h"

bool Booked::isAvailable(int dayIndex, int hourIndex) {
    return occupied_slots[dayIndex][hourIndex] == 0; // Assuming 0 means the slot is available
}
