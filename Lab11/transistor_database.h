#ifndef TRANSISTORDATABASE_H
#define TRANSISTORDATABASE_H

#include <vector>
#include "transistor.h"
#include "bipolar_transistor.h"
#include "field_effect_transistor.h"

class TransistorDatabase {
private:
    std::vector<Transistor*> database;

public:
    TransistorDatabase();
    ~TransistorDatabase();
    
    void inputNewBipolar();
    void inputNewFET();
    void displayAll() const;
    void calculateAndDisplayMaxPower() const;
};

#endif