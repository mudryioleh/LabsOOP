#include "transistor_database.h"
#include <iostream>

int main() {
    TransistorDatabase db;

    db.inputNewBipolar();
    db.inputNewFET();

    db.displayAll();

    db.calculateAndDisplayMaxPower();

    return 0; 
}