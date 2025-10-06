#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Antenna {
private:
    string type;
    double gain_factor;       
    double freq_min;  
    double freq_max;  

public:
    Antenna() {
        type = "Default";
        gain_factor = 1.0;
        freq_min = 100.0;
        freq_max = 200.0;
        cout << "Створено антену за замовчуванням.\n";
    }

    Antenna(string t, double g, double fmin, double fmax) {
        setType(t);
        setGain(g);
        setFrequencyRange(fmin, fmax);
        cout << "Створено антену з параметрами.\n";
    }

    ~Antenna() {
        cout << "Знищено антену: " << type << endl;
    }

    void setType(string t) {
        if (t.empty()) {
            cout << "Помилка: тип антени не може бути порожнім!\n";
            type = "Unknown";
        } else {
            type = t;
        }
    }

    void setGain(double g) {
        if (g <= 0) {
            cout << "Помилка: коефіцієнт підсилення має бути > 0!\n";
            gain_factor = 1.0;
        } else {
            gain_factor = g;
        }
    }

    void setFrequencyRange(double fmin, double fmax) {
        if (fmin <= 0 || fmax <= 0 || fmin >= fmax) {
            cout << "Помилка: некоректний діапазон!\n";
            freq_min = 100.0;
            freq_max = 200.0;
        } else {
            freq_min = fmin;
            freq_max = fmax;
        }
    }

    void input() {
        cout << "\nВведіть дані для антени:\n";
        cout << "Тип: ";
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Тип: ";
        getline(cin, type);

        cout << "Коефіцієнт підсилення: ";
        cin >> gain_factor;
        cout << "Нижня межа діапазону: ";
        cin >> freq_min;
        cout << "Верхня межа діапазону: ";
        cin >> freq_max;

        setFrequencyRange(freq_min, freq_max);
    }

    void display() const {
        cout << "Антена [Тип: " << type
             << ", Підсилення: " << gain_factor
             << ", Діапазон: " << freq_min << "-" << freq_max << " МГц]\n";
    }

    bool hasGainMoreThan(double N) const {
        return gain_factor > N;
    }

    bool supportsFrequency(double f) const {
        return (f >= freq_min && f <= freq_max);
    }
};

int main() {
    Antenna defaultAntenna;
    defaultAntenna.display();

    Antenna dipoleAntenna("Dipole", 2.5, 300.0, 600.0);
    dipoleAntenna.display();

    Antenna copiedAntenna;
    copiedAntenna.input();
    copiedAntenna.display();

    vector<Antenna> antennas = {defaultAntenna, dipoleAntenna, copiedAntenna};

    cout << "\n--- Антени з підсиленням більше ніж 2.0 ---\n";
    bool found = false;
    for (const auto &ant : antennas) {
        if (ant.hasGainMoreThan(2.0)) {
            ant.display();
            found = true;
        }
    }
    if (!found) {
        cout << "Немає антен з таким коефіцієнтом підсилення.\n";
    }

    cout << "\n--- Антени, що підтримують частоту 400 МГц ---\n";
    found = false;
    for (const auto &ant : antennas) {
        if (ant.supportsFrequency(400.0)) {
            ant.display();
            found = true;
        }
    }
    if (!found) {
        cout << "Немає антен, що підтримують 400 МГц.\n";
    }

    return 0;
}