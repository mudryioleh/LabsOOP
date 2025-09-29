#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Antenna {
private:
    string type;
    double gain_factor;       
    double frequency_range;

public:
    Antenna() {
        type = "Default";
        gain_factor = 1.0;
        frequency_range = 100.0;
        cout << "Створено антену за замовчуванням.\n";
    }

    Antenna(string t, double g, double f) {
        setType(t);
        setGain(g);
        setFrequency(f);
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

    void setFrequency(double f) {
        if (f <= 0) {
            cout << "Помилка: частотний діапазон має бути > 0!\n";
            frequency_range = 100.0;
        } else {
            frequency_range = f;
        }
    }

    void input() {
        cout << "\nВведіть дані для антени:\n";
        cout << "Тип: ";
        cin >> type;
        cout << "Коефіцієнт підсилення: ";
        cin >> gain_factor;
        cout << "Частотний діапазон: ";
        cin >> frequency_range;
    }

    void display() const {
        cout << "Антена [Тип: " << type
             << ", Підсилення: " << gain_factor
             << ", Частотний діапазон: " << frequency_range << " МГц]\n";
    }

    bool hasGainMoreThan(double N) const {
        return gain_factor > N;
    }
};

int main() {
    Antenna defaultAntenna;
    defaultAntenna.display();

    Antenna dipoleAntenna("Dipole", 2.5, 500.0);
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

    return 0;
}