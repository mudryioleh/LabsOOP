#ifndef BIPOLARTRANSISTOR_H
#define BIPOLARTRANSISTOR_H

#include "transistor.h"

class BipolarTransistor : public Transistor {
private:
    std::string type;

public:
    BipolarTransistor();
    ~BipolarTransistor();
    
    void inputData() override;
    void displayData() const override;
};

#endif