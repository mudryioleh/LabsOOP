#include "derived_transistors.h"
#include <limits>


BipolarTransistor::BipolarTransistor(string m, double p, double g, string t) 
    : Transistor(m, p) {
    if (g < 0) throw InvalidDataException("Gain cannot be negative!");
    gain = g;
    type = t;
}

void BipolarTransistor::input() {
    Transistor::input(); 
    cout << "Enter Gain (hFE): ";
    while (!(cin >> gain)) {
        cout << "Invalid input. Enter a number for Gain: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (gain < 0) throw InvalidDataException("Input Error: Gain cannot be negative.");
    
    cout << "Enter Type (NPN/PNP): ";
    cin >> type;
}

void BipolarTransistor::print() const {
    cout << "[Bipolar] ";
    Transistor::print();
    cout << ", Gain: " << gain << ", Type: " << type << endl;
}

void BipolarTransistor::saveToFile(ofstream& ofs) const {
    ofs << "B ";
    Transistor::saveToFile(ofs);
    ofs << " " << gain << " " << type << endl;
}

void BipolarTransistor::readFromFile(ifstream& ifs) {
    Transistor::readFromFile(ifs);
    ifs >> gain >> type;
}

FieldEffectTransistor::FieldEffectTransistor(string m, double p, double gt, string ct)
    : Transistor(m, p) {
    gateThreshold = gt;
    channelType = ct;
}

void FieldEffectTransistor::input() {
    Transistor::input();
    cout << "Enter Gate Threshold (V): ";
    cin >> gateThreshold;
    cout << "Enter Channel Type (N-CH/P-CH): ";
    cin >> channelType;
}

void FieldEffectTransistor::print() const {
    cout << "[FET] ";
    Transistor::print();
    cout << ", Vgs(th): " << gateThreshold << "V, Channel: " << channelType << endl;
}

void FieldEffectTransistor::saveToFile(ofstream& ofs) const {
    ofs << "F ";
    Transistor::saveToFile(ofs);
    ofs << " " << gateThreshold << " " << channelType << endl;
}

void FieldEffectTransistor::readFromFile(ifstream& ifs) {
    Transistor::readFromFile(ifs);
    ifs >> gateThreshold >> channelType;
}