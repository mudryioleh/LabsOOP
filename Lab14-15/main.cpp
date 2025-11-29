#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

void printMenu() {
    cout << "\n=== Antenna Manager (Doubly Linked List) ===" << endl;
    cout << "1. Push Front" << endl;
    cout << "2. Push Back" << endl;
    cout << "3. Insert After Index" << endl;
    cout << "4. Pop Front" << endl;
    cout << "5. Pop Back" << endl;
    cout << "6. Remove by Value" << endl;
    cout << "7. Display Forward" << endl;
    cout << "8. Display Backward" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose option: ";
}

Antenna createAntenna() {
    string type, freq;
    double gain;
    cout << "Enter Type: "; cin >> type;
    cout << "Enter Gain: "; cin >> gain;
    cout << "Enter Freq Range: "; cin >> freq;
    return Antenna(type, gain, freq);
}

int main() {
    DoublyLinkedList list;
    int choice;

    do {
        printMenu();

        while (!(cin >> choice)) {
            cout << "Invalid input. Enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
        case 1: {
            Antenna temp; 
            if (temp.input()) { // Якщо ввели правильно - додаємо
                list.pushFront(temp);
            }
            break;
        }
        case 2: {
            Antenna temp;
            if (temp.input()) {
                list.pushBack(temp);
            }
            break;
        }
        case 3: {
            int idx;
            cout << "Enter index to insert after: ";
            cin >> idx;
            
            Antenna temp;
            if (temp.input()) { // Спочатку вводимо дані, якщо ОК - вставляємо
                list.insertAfter(idx, temp);
            }
            break;
        }
        case 4:
            list.popFront();
            break;
        case 5:
            list.popBack();
            break;
        case 6: {
            cout << "Введіть дані антени, яку треба видалити:" << endl;
            Antenna temp;
            if (temp.input()) {
                list.removeByValue(temp);
            }
            break;
        }
        case 7:
            list.displayForward();
            break;
        case 8:
            list.displayBackward();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid option!" << endl;
        }
    } while (choice != 0);

    return 0;
}