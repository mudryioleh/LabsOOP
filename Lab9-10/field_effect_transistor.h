#ifndef FIELDEFFECTTRANSISTOR_H
#define FIELDEFFECTTRANSISTOR_H

#include "transistor.h"

class FieldEffectTransistor : public Transistor {
private:
    std::string technology;

public:
    FieldEffectTransistor();
    ~FieldEffectTransistor();

    void inputData() override;
    void displayData() const override;
};

#endif