#include "transistor.h"

Transistor::Transistor() : model("Unknown"), maxPower(0.0) {}

Transistor::Transistor(string model, double maxPower) {
    if (maxPower < 0) {
        throw InvalidDataException("Power cannot be negative!");
    }
    this->model = model;
    this->maxPower = maxPower;
}

Transistor::~Transistor() {}

void Transistor::input() {
    cout << "Enter Model Name: ";
    cin >> model;
    cout << "Enter Max Power (W): ";
    cin >> maxPower;
    
    if (maxPower < 0) {
        throw InvalidDataException("Input Error: Power cannot be negative.");
    }
}

void Transistor::print() const {
    cout << "Model: " << model << ", Power: " << maxPower << "W";
}

void Transistor::saveToFile(ofstream& ofs) const {
    ofs << model << " " << maxPower;
}

void Transistor::readFromFile(ifstream& ifs) {
    ifs >> model >> maxPower;
}

bool Transistor::operator>(const Transistor& other) const {
    return this->maxPower > other.maxPower;
}

bool Transistor::operator<(const Transistor& other) const {
    return this->maxPower < other.maxPower;
}