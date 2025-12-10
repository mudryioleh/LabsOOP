#include "Antenna.h"

Antenna::Antenna() : type("Unknown"), gain(0.0), frequencyRange("0-0 Hz") {}

Antenna::Antenna(string t, double g, string f) : type(t), gain(g), frequencyRange(f) {}

ostream& operator<<(ostream& os, const Antenna& a) {
    os << "{ Antenna: " << a.type 
       << " | Gain: " << a.gain 
       << " dB | Freq: " << a.frequencyRange << " }";
    return os;
}