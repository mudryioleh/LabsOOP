#include "Antenna.h"

Antenna::Antenna() : type("Unknown"), gain(0.0), frequencyRange("N/A") {}

Antenna::Antenna(string t, double g, string f) : type(t), gain(g), frequencyRange(f) {}

bool Antenna::input() {
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Введіть дані для антени:\n";
    
    cout << "Тип: ";
    getline(cin, type);
    if (type.empty() || type.length() < 3) {
        cout << "Помилка: Некоректний тип антени! (мін. 3 символи)\n";
        return false;
    }

    cout << "Коефіцієнт підсилення (дБ): ";
    cin >> gain;
    
    if (cin.fail() || gain <= 0.0f) {
        cout << "Помилка: Некоректний коефіцієнт підсилення!\n";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }

    double freq_min, freq_max;
    
    cout << "Мінімальна частота (МГц): ";
    cin >> freq_min;
    cout << "Максимальна частота (МГц): ";
    cin >> freq_max;

    if (cin.fail() || freq_min < 0.0f || freq_max < freq_min) {
        cout << "Помилка: Некоректний діапазон частот!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }

    frequencyRange = to_string(freq_min) + " - " + to_string(freq_max) + " MHz";

    return true; 
}

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