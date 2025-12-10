#ifndef ANTENNA_H
#define ANTENNA_H

#include <string>
#include <iostream>

using namespace std;

class Antenna {
private:
    string type;
    double gain;
    string frequencyRange;

public:
    Antenna();
    Antenna(string t, double g, string f);

    friend ostream& operator<<(ostream& os, const Antenna& a);
};

#endif