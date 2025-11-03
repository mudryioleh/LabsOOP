#include "bipolar_transistor.h"
#include <iostream>

BipolarTransistor::BipolarTransistor() : Transistor(), type("NPN") {
    std::cout << "-> (Derived) Створено BipolarTransistor\n";
}

BipolarTransistor::~BipolarTransistor() {
    std::cout << "<- (Derived) Знищено BipolarTransistor\n";
}