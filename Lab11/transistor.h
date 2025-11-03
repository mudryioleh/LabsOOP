#ifndef TRANSISTOR_H
#define TRANSISTOR_H

#include <string>

class TransistorDatabase;

class Transistor {
private:
    std::string partNumber; 
    double maxPower_mW;

public:
    Transistor();
    virtual ~Transistor();

    friend class TransistorDatabase;
};

#endif