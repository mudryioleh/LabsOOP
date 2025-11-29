#include "transistor.h"
#include <limits>    
#include <algorithm>

string encodeSpaces(string s) {
    replace(s.begin(), s.end(), ' ', '_');
    return s;
}

string decodeSpaces(string s) {
    replace(s.begin(), s.end(), '_', ' ');
    return s;
}

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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Model Name: ";
    getline(cin, model);

    cout << "Enter Max Power (W): ";
    while (!(cin >> maxPower)) {
        cout << "Invalid input. Please enter a number for Power: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    if (maxPower < 0) {
        throw InvalidDataException("Input Error: Power cannot be negative.");
    }
}

void Transistor::print() const {
    cout << "Model: " << model << ", Power: " << maxPower << "W";
}

void Transistor::saveToFile(ofstream& ofs) const {
   ofs << encodeSpaces(model) << " " << maxPower;
}

void Transistor::readFromFile(ifstream& ifs) {
    ifs >> model >> maxPower;
    model = decodeSpaces(model);
}

bool Transistor::operator>(const Transistor& other) const {
    return this->maxPower > other.maxPower;
}

bool Transistor::operator<(const Transistor& other) const {
    return this->maxPower < other.maxPower;
}