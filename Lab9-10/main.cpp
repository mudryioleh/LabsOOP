#include <iostream>
#include <vector>
#include <limits>
#include "transistor.h"
#include "bipolar_transistor.h"
#include "field_effect_transistor.h"

int main() {
    std::vector<Transistor*> database;

    std::cout << "--- 1. Додавання Біполярного Транзистора ---\n";
    Transistor* bjt = new BipolarTransistor();
    bjt->inputData();
    database.push_back(bjt);

    std::cout << "\n--- 2. Додавання Польового Транзистора ---\n";
    Transistor* fet = new FieldEffectTransistor();
    fet->inputData(); 
    database.push_back(fet);

    
    std::cout << "\n--- 4. Виведення всіх даних ---";
    for (const Transistor* t : database) {
        t->displayData();
    }

    double maxPower = -1.0;
    std::string maxPartNumber = "";
    
    for (const Transistor* t : database) {
        if (t->getPowerInWatts() > maxPower) {
            maxPower = t->getPowerInWatts();
            maxPartNumber = t->getPartNumber();
        }
    }
    
    std::cout << "\n--- 6. Результат обчислення ---\n";
    std::cout << "Найпотужніший транзистор: " << maxPartNumber << "\n";
    std::cout << "Його потужність: " << maxPower * 1000 << " мВт (або " << maxPower << " Вт)\n";

    std::cout << "\n--- 7. Очищення пам'яті ---\n";
    for (Transistor* t : database) {
        delete t;
    }
    database.clear();

    return 0;
}