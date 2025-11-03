#include "transistor_database.h"
#include <iostream>
#include <limits>
#include <string>

TransistorDatabase::TransistorDatabase() {}

TransistorDatabase::~TransistorDatabase() {
    std::cout << "\n--- Очищення бази даних ---\n";
    for (Transistor* t : database) {
        delete t;
    }
    database.clear();
}

void TransistorDatabase::inputNewBipolar() {
    BipolarTransistor* bjt = new BipolarTransistor();
    std::cout << "\n--- Введення: Біполярний Транзистор ---\n";

    std::cout << "Введіть маркування: ";
    std::getline(std::cin, bjt->partNumber);
    while (bjt->partNumber.empty()) {
        std::cout << "Маркування не може бути порожнім: ";
        std::getline(std::cin, bjt->partNumber);
    }

    std::cout << "Введіть макс. потужність (мВт): ";
    while (!(std::cin >> bjt->maxPower_mW) || bjt->maxPower_mW <= 0) {
        std::cout << "Введіть коректне додатнє число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Введіть тип (NPN/PNP): ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, bjt->type);
    while (bjt->type != "NPN" && bjt->type != "PNP") {
        std::cout << "Помилка. Введіть 'NPN' або 'PNP': ";
        std::getline(std::cin, bjt->type);
    }
    
    database.push_back(bjt);
    std::cout << "Успішно додано!\n";
}

void TransistorDatabase::inputNewFET() {
    FieldEffectTransistor* fet = new FieldEffectTransistor();
    std::cout << "\n--- Введення: Польовий Транзистор ---\n";
    
    std::cout << "Введіть маркування: ";
    std::getline(std::cin, fet->partNumber);
    while (fet->partNumber.empty()) {
        std::cout << "Маркування не може бути порожнім: ";
        std::getline(std::cin, fet->partNumber);
    }

    std::cout << "Введіть макс. потужність (мВт): ";
    while (!(std::cin >> fet->maxPower_mW) || fet->maxPower_mW <= 0) {
        std::cout << "Введіть коректне додатнє число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Введіть технологію (MOSFET/JFET): ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, fet->technology);
    while (fet->technology != "MOSFET" && fet->technology != "JFET") {
        std::cout << "Помилка. Введіть 'MOSFET' або 'JFET': ";
        std::getline(std::cin, fet->technology);
    }
    
    database.push_back(fet);
    std::cout << "Успішно додано!\n";
}

void TransistorDatabase::displayAll() const {
    if (database.empty()) {
        std::cout << "\nБаза даних порожня.\n";
        return;
    }

    std::cout << "\n--- 4. Виведення всіх даних ---";
    for (const Transistor* t : database) {
        std::cout << "\n--- [ТРАНЗИСТОР] ---\n";
        
        std::cout << "Маркування: \t" << t->partNumber << "\n";
        std::cout << "Макс. потужність: " << t->maxPower_mW << " мВт\n";
        
        if (const BipolarTransistor* bjt = dynamic_cast<const BipolarTransistor*>(t)) {
            std::cout << "Тип (BJT): \t" << bjt->type << "\n"; 
        } 
        else if (const FieldEffectTransistor* fet = dynamic_cast<const FieldEffectTransistor*>(t)) {
            std::cout << "Технологія: \t" << fet->technology << "\n";
        }
    }
}

void TransistorDatabase::calculateAndDisplayMaxPower() const {
    if (database.empty()) {
        std::cout << "\nНеможливо розрахувати: база даних порожня.\n";
        return;
    }
    
    double maxPower = -1.0;
    std::string maxPartNumber = "";
    
    for (const Transistor* t : database) {
        if (t->maxPower_mW > maxPower) {
            maxPower = t->maxPower_mW;
            maxPartNumber = t->partNumber;
        }
    }
    
    std::cout << "\n--- 6. Результат обчислення ---\n";
    std::cout << "Найпотужніший транзистор: " << maxPartNumber << "\n";
    std::cout << "Його потужність: " << maxPower << " мВт\n";
}