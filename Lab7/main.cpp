#include "antenna.h"

using namespace std;

int main() {
    Antenna system;

    for (int i = 0; i < 3; ++i) {
        cout << "\nВведення даних для антени " << i + 1 << ":\n";
        system.inputAntenna();
    }

    system.displayAllAntennas();

    cout << "\nСпроба змінити коефіцієнт підсилення антени 1 на некоректне значення (-1 дБ):\n";
    if (!system.setGainFactor(0, -1.0f)) {
        cout << "Помилка: Некоректний коефіцієнт підсилення!\n";
    }

    cout << "\nЗміна коефіцієнта підсилення антени 1 на коректне значення (9.0 дБ):\n";
    if (system.setGainFactor(0, 9.0f)) {
        cout << "Коефіцієнт підсилення успішно змінено!\n";
    }

    cout << "\nВставка нової антени на позицію 1:\n";
    antenna_s_t newAntenna = {"Патч", 7.5f, 2400.0f, 2500.0f};
    system.insertAntenna(1, newAntenna);

    cout << "\nОбмін антен 1 і 2:\n";
    system.swapAntennas(0, 1);

    cout << "\nВидалення антени 2:\n";
    system.removeAntenna(1);

    system.displayAllAntennas();

    cout << "\nОчищення списку антен:\n";
    system.clearAntennas();
    system.displayAllAntennas();

    return 0;
}