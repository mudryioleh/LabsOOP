#include "antenna.h"

Antenna::Antenna() {
    for (int i = 0; i < SIZE; ++i) {
        antennas[i].type = "";
        antennas[i].gain_factor = 0.0f;
        antennas[i].frequency_range = 0.0f;
    }
}

Antenna::~Antenna() {
    std::cout << "Antenna system destroyed.\n";
}

void Antenna::inputAntenna(int index) {
    if (index < 0 || index >= SIZE) {
        std::cout << "Помилка: Некоректний індекс!\n";
        return;
    }

    std::cout << "Введіть дані для антени " << index + 1 << ":\n";
    
    std::cout << "Тип: ";
    std::string type;
    std::getline(std::cin, type);
    if (!setType(index, type)) {
        std::cout << "Помилка: Некоректний тип антени!\n";
        return;
    }

    std::cout << "Коефіцієнт підсилення (дБ): ";
    float gain;
    std::cin >> gain;
    if (!setGainFactor(index, gain)) {
        std::cout << "Помилка: Некоректний коефіцієнт підсилення!\n";
        return;
    }

    std::cout << "Частота (МГц): ";
    float range;
    std::cin >> range;
    if (!setFrequencyRange(index, range)) {
        std::cout << "Помилка: Некоректна частота!\n";
        return;
    }

    std::cin.ignore();
    std::cout << "Дані успішно введено для антени " << index + 1 << "!\n";
}

void Antenna::displayAllAntennas() const {
    std::cout << "\nСписок антен:\n";
    std::cout << "----------------\n";
    for (int i = 0; i < SIZE; ++i) {
        if (!antennas[i].type.empty()) {
            std::cout << "Антена " << i + 1 << ":\n";
            std::cout << "Тип: " << antennas[i].type << "\n";
            std::cout << "Коефіцієнт підсилення: " << antennas[i].gain_factor << " дБ\n";
            std::cout << "Частота: " << antennas[i].frequency_range << " МГц\n";
            std::cout << "----------------\n";
        }
    }
}

bool Antenna::setType(int index, const std::string& newType) {
    if (index < 0 || index >= SIZE || newType.empty() || newType.length() < 3) {
        return false;
    }
    antennas[index].type = newType;
    return true;
}

bool Antenna::setGainFactor(int index, float newGain) {
    if (index < 0 || index >= SIZE || newGain <= 0.0f) {
        return false;
    }
    antennas[index].gain_factor = newGain;
    return true;
}

bool Antenna::setFrequencyRange(int index, float newRange) {
    if (index < 0 || index >= SIZE || newRange < 0.0f) {
        return false;
    }
    antennas[index].frequency_range = newRange;
    return true;
}