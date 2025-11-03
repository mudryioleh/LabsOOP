#include "field_effect_transistor.h"
#include <iostream>

FieldEffectTransistor::FieldEffectTransistor() : Transistor(), technology("MOSFET") {
     std::cout << "-> (Derived) Створено FieldEffectTransistor\n";
}

FieldEffectTransistor::~FieldEffectTransistor() {
    std::cout << "<- (Derived) Знищено FieldEffectTransistor\n";
}