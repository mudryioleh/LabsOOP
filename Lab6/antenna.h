#ifndef ANTENNA_H
#define ANTENNA_H

#include <array>
#include <string>
#include <iostream>

const int SIZE = 5;

struct antenna_s_t {
    std::string type;
    float gain_factor;
    float frequency_range;
};

class Antenna {
private:
    std::array<antenna_s_t, SIZE> antennas;

public:
    Antenna();
    ~Antenna();

    void inputAntenna(int index);
    void displayAllAntennas() const;

    bool setType(int index, const std::string& newType);
    bool setGainFactor(int index, float newGain);
    bool setFrequencyRange(int index, float newRange);
};

#endif