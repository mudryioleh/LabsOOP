#include "transistor.h"
#include <iostream>

Transistor::Transistor() : partNumber("N/A"), maxPower_mW(0.0) {
    std::cout << "-> (Base) Створено Transistor\n";
}

Transistor::~Transistor() {
    std::cout << "<- (Base) Знищено Transistor\n";
}