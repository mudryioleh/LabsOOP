#include "Antenna.h"

Antenna::Antenna(string t, double g, string f) : type(t), gain(g), frequencyRange(f) {
    cout << "  [CTOR] Antenna '" << type << "' created." << endl;
}

Antenna::~Antenna() {
    cout << "  [DTOR] Antenna '" << type << "' destroyed." << endl;
}

void Antenna::print() const {
    cout << "Antenna: " << type << ", Gain: " << gain << "dB, Range: " << frequencyRange << endl;
}