#include "antenna.h"

using namespace std;

Antenna::Antenna() {
    antennas.clear(); 
}

Antenna::~Antenna() {
    cout << "Antenna system destroyed.\n";
}

void Antenna::inputAntenna() {
    antenna_s_t antenna;
    cout << "Введіть дані для антени:\n";
    
    cout << "Тип: ";
    getline(cin, antenna.type);
    if (antenna.type.empty() || antenna.type.length() < 3) {
        cout << "Помилка: Некоректний тип антени!\n";
        return;
    }

    cout << "Коефіцієнт підсилення (дБ): ";
    cin >> antenna.gain_factor;
    if (antenna.gain_factor <= 0.0f) {
        cout << "Помилка: Некоректний коефіцієнт підсилення!\n";
        return;
    }

    cout << "Мінімальна частота (МГц): ";
    cin >> antenna.frequency_min;
    cout << "Максимальна частота (МГц): ";
    cin >> antenna.frequency_max;
    if (antenna.frequency_min < 0.0f || antenna.frequency_max < antenna.frequency_min) {
        cout << "Помилка: Некоректний діапазон частот!\n";
        return;
    }

    cin.ignore();
    addAntenna(antenna);
    cout << "Антену успішно додано!\n";
}

void Antenna::displayAllAntennas() const {
    if (antennas.empty()) {
        cout << "\nСписок антен порожній!\n";
        return;
    }

    cout << "\nСписок антен:\n";
    cout << "-----------------\n";
    for (size_t i = 0; i < antennas.size(); ++i) {
        cout << "Антена " << i + 1 << ":\n";
        cout << "Тип: " << antennas[i].type << "\n";
        cout << "Коефіцієнт підсилення: " << antennas[i].gain_factor << " дБ\n";
        cout << "Діапазон частот: " << antennas[i].frequency_min << " - " << antennas[i].frequency_max << " МГц\n";
        cout << "-----------------\n";
    }
}

bool Antenna::setType(size_t index, const string& newType) {
    if (index >= antennas.size() || newType.empty() || newType.length() < 3) {
        return false;
    }
    antennas[index].type = newType;
    return true;
}

bool Antenna::setGainFactor(size_t index, float newGain) {
    if (index >= antennas.size() || newGain <= 0.0f) {
        return false;
    }
    antennas[index].gain_factor = newGain;
    return true;
}

bool Antenna::setFrequencyRange(size_t index, float minRange, float maxRange) {
    if (index >= antennas.size() || minRange < 0.0f || maxRange < minRange) {
        return false;
    }
    antennas[index].frequency_min = minRange;
    antennas[index].frequency_max = maxRange;
    return true;
}

void Antenna::addAntenna(const antenna_s_t& antenna) {
    antennas.push_back(antenna);
}

void Antenna::insertAntenna(size_t index, const antenna_s_t& antenna) {
    if (index <= antennas.size()) {
        antennas.insert(antennas.begin() + index, antenna);
    } else {
        cout << "Помилка: Некоректний індекс для вставки!\n";
    }
}

void Antenna::removeAntenna(size_t index) {
    if (index < antennas.size()) {
        antennas.erase(antennas.begin() + index);
    } else {
        cout << "Помилка: Некоректний індекс для видалення!\n";
    }
}

void Antenna::swapAntennas(size_t index1, size_t index2) {
    if (index1 < antennas.size() && index2 < antennas.size()) {
        swap(antennas[index1], antennas[index2]);
    } else {
        cout << "Помилка: Некоректні індекси для обміну!\n";
    }
}

void Antenna::clearAntennas() {
    antennas.clear();
    cout << "Список антен очищено!\n";
}