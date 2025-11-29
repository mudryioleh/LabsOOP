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

    bool input();
    
    string getType() const;
    double getGain() const;
    string getFreqRange() const;

    bool operator==(const Antenna& other) const;
    bool operator!=(const Antenna& other) const;

    friend ostream& operator<<(ostream& os, const Antenna& antenna);
};

#endif