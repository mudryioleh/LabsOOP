#include "transistor.h"
#include <limits>

Transistor::Transistor() : partNumber("N/A"), maxPower_mW(0.0) {}

Transistor::~Transistor() {
    std::cout << "<- (Base) Деструктор Transistor\n";
}

void Transistor::inputData() {
    std::cout << "Введіть маркування: ";
    std::getline(std::cin, this->partNumber); 
    while (this->partNumber.empty()) {
        std::cout << "Маркування не може бути порожнім: ";
        std::getline(std::cin, this->partNumber);
    }

    std::cout << "Введіть макс. потужність (мВт): ";
    while (!(std::cin >> this->maxPower_mW) || this->maxPower_mW <= 0) {
        std::cout << "Введіть коректне додатнє число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void Transistor::displayData() const {
    std::cout << "Маркування: \t" << this->partNumber << "\n";
    std::cout << "Макс. потужність: " << this->maxPower_mW << " мВт\n";
}

double Transistor::getPowerInWatts() const {
    return this->maxPower_mW / 1000.0;
}

std::string Transistor::getPartNumber() const {
    return this->partNumber;
}