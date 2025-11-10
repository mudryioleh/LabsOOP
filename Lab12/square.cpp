#include "square.h"
#include <cmath>
#include <iostream>

Square::Square() : side(0.0) {}

Square::Square(double s) {
    setSide(s);
}

void Square::setSide(double s) {
    if (s < 0) {
        this->side = 0.0;
    } else {
        this->side = s;
    }
}

double Square::getSide() const {
    return this->side;
}

double Square::getDiagonal() const {
    return this->side * std::sqrt(2.0);
}

void Square::display() const {
    std::cout << "Квадрат [Сторона: " << this->side
              << ", Діагональ: " << this->getDiagonal() << "]\n";
}

bool Square::operator>(const Square& other) const {
    return this->getDiagonal() > other.getDiagonal();
}

bool Square::operator<(const Square& other) const {
    return this->getDiagonal() < other.getDiagonal();
}

Square Square::operator-(double value) const {
    Square newSquare = *this; 
    newSquare.setSide(this->side - value);
    return newSquare;
}

Square& Square::operator-=(double value) {
    this->setSide(this->side - value);
    return *this;
}