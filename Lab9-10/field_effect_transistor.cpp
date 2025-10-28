#include "field_effect_transistor.h"
#include <limits>

FieldEffectTransistor::FieldEffectTransistor() : Transistor(), technology("MOSFET") {}

FieldEffectTransistor::~FieldEffectTransistor() {
    std::cout << "<- (Derived) Деструктор FieldEffectTransistor\n";
}

void FieldEffectTransistor::inputData() {
    Transistor::inputData(); 

    std::cout << "Введіть технологію (MOSFET/JFET): ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, this->technology);
    while (this->technology != "MOSFET" && this->technology != "JFET") { 
        std::cout << "Помилка. Введіть 'MOSFET' або 'JFET': ";
        std::getline(std::cin, this->technology);
    }
}

void FieldEffectTransistor::displayData() const {
    std::cout << "\n--- [ПОЛЬОВИЙ ТРАНЗИСТОР (FET)] ---\n";
    Transistor::displayData();

    std::cout << "Технологія: \t" << this->technology << "\n";
}