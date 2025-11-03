#ifndef FIELDEFFECTTRANSISTOR_H
#define FIELDEFFECTTRANSISTOR_H

#include "transistor.h"

class TransistorDatabase;

class FieldEffectTransistor : public Transistor {
private:
    std::string technology; 

public:
    FieldEffectTransistor();
    ~FieldEffectTransistor();

    friend class TransistorDatabase;
};

#endif