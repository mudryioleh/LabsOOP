#ifndef TRANSISTOR_H
#define TRANSISTOR_H

#include <iostream>
#include <string>

class Transistor {
private:
    std::string partNumber;
    double maxPower_mW;

public:
    Transistor();
    virtual ~Transistor();

    virtual void inputData();
    virtual void displayData() const;

    double getPowerInWatts() const;
    std::string getPartNumber() const;
};

#endif