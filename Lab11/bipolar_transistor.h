#ifndef BIPOLARTRANSISTOR_H
#define BIPOLARTRANSISTOR_H

#include "transistor.h"

class TransistorDatabase;

class BipolarTransistor : public Transistor {
private:
    std::string type;

public:
    BipolarTransistor();
    ~BipolarTransistor();

    friend class TransistorDatabase;
};

#endif