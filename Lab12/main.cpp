#include <iostream>
#include <vector> 
#include <algorithm>
#include "square.h"

void printSquares(const std::string& title, const std::vector<Square>& squares) {
    std::cout << "--- " << title << " ---\n";
    for (const Square& sq : squares) {
        sq.display();
    }
    std::cout << "\n";
}

int main() {
    std::vector<Square> squares;
    squares.push_back(Square(10.0));
    squares.push_back(Square(5.0));
    squares.push_back(Square(12.0));
    squares.push_back(Square(3.0));

    printSquares("1. Початковий масив:", squares);

    std::cout << "--- Тест operator> (10 > 5?) ---\n";
    if (squares[0] > squares[1]) {
        std::cout << "Квадрат 1 (10) БІЛЬШИЙ за Квадрат 2 (5)\n\n";
    }

    std::sort(squares.begin(), squares.end());
    printSquares("2. Масив, відсортований за зростанням діагоналі:", squares);

    double reductionValue = 2.0;
    std::cout << "--- 3. Зменшення кожної сторони на " << reductionValue << " --- \n";
    
    for (Square& sq : squares) {
        sq -= reductionValue;
    }

    printSquares("4. Кінцевий масив (після зменшення):", squares);

    std::cout << "--- Тест operator- (новий об'єкт) ---\n";
    Square originalSquare(20.0);
    Square reducedSquare = originalSquare - 5.0; 

    std::cout << "Оригінал: ";
    originalSquare.display();
    std::cout << "Новий (зменшений): ";
    reducedSquare.display();

    return 0;
}