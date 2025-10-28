#include "bipolar_transistor.h"
#include <limits>

BipolarTransistor::BipolarTransistor() : Transistor(), type("NPN") {}

BipolarTransistor::~BipolarTransistor() {
    std::cout << "<- (Derived) Деструктор BipolarTransistor\n";
}

void BipolarTransistor::inputData() {
    Transistor::inputData(); 

    std::cout << "Введіть тип біполярного (NPN/PNP): ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, this->type);
    while (this->type != "NPN" && this->type != "PNP") { 
        std::cout << "Помилка. Введіть 'NPN' або 'PNP': ";
        std::getline(std::cin, this->type);
    }
}

void BipolarTransistor::displayData() const {
    std::cout << "\n--- [БІПОЛЯРНИЙ ТРАНЗИСТОР] ---\n";
   
    Transistor::displayData(); 

    std::cout << "Тип (BJT): \t" << this->type << "\n";
}