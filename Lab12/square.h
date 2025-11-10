#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>

class Square {
private:
    double side;

public:
    Square();
    Square(double s);

    void setSide(double s);
    double getSide() const;
    double getDiagonal() const;
    void display() const;

    bool operator>(const Square& other) const;

    bool operator<(const Square& other) const;

    Square operator-(double value) const;

    Square& operator-=(double value);
};

#endif