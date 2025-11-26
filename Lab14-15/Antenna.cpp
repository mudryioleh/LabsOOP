#include "Antenna.h"

Antenna::Antenna() : type("Unknown"), gain(0.0), frequencyRange("N/A") {}

Antenna::Antenna(string t, double g, string f) : type(t), gain(g), frequencyRange(f) {}

string Antenna::getType() const { return type; }
double Antenna::getGain() const { return gain; }
string Antenna::getFreqRange() const { return frequencyRange; }

bool Antenna::operator==(const Antenna& other) const {
    return (type == other.type && 
            abs(gain - other.gain) < 0.001 &&
            frequencyRange == other.frequencyRange);
}

bool Antenna::operator!=(const Antenna& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& os, const Antenna& a) {
    os << "[Type: " << a.type 
       << ", Gain: " << a.gain 
       << ", Freq: " << a.frequencyRange << "]";
    return os;
}