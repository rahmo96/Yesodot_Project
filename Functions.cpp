#include "Functions.h"
#include "Player.h"
#include "sqlite3.h"

int GetDouble(long i) {
    switch (i) {
        case 0: return 0;
        case 1: return 2;
        case 2: return 4;
        case 3: return 6;
        case 4: return 8;
        case 5: return 1;
        case 6: return 3;
        case 7: return 5;
        case 8: return 7;
        case 9: return 9;
        default: return 0;
    }
}

bool IsValidIsraeliID(const std::string& israeliID) {
    if (israeliID.length() != 9)
        return false;

    long sum = 0;

    for (int i = 0; i < israeliID.length(); i++) {
        int digit = israeliID[israeliID.length() - 1 - i] - '0';
        sum += (i % 2 != 0) ? GetDouble(digit) : digit;
    }

    return sum % 10 == 0;
}




