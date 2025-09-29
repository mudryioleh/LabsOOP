#ifndef ANTENNA_H
#define ANTENNA_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct antenna_s_t {
    string type;
    float gain_factor;
    float frequency_min;
    float frequency_max;
};

class Antenna {
private:
    vector<antenna_s_t> antennas;

public:
    Antenna();
    ~Antenna();

    void inputAntenna();
    void displayAllAntennas() const;

    bool setType(size_t index, const string& newType);
    bool setGainFactor(size_t index, float newGain);
    bool setFrequencyRange(size_t index, float minRange, float maxRange);

    void addAntenna(const antenna_s_t& antenna);
    void insertAntenna(size_t index, const antenna_s_t& antenna);
    void removeAntenna(size_t index);
    void swapAntennas(size_t index1, size_t index2);
    void clearAntennas();
};

#endif