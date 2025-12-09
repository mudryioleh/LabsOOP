#ifndef ANTENNA_H
#define ANTENNA_H

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Antenna {
private:
    string type;
    double gain;
    string frequencyRange;

public:
    Antenna(string t, double g, string f);
    ~Antenna();

    void print() const;
    string getType() const { return type; }
};

#endif