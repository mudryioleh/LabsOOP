#include "antenna.h"

using namespace std;

void addThreeAntennas(Antenna& systemRef) {
    cout << "--- Виклик функції addThreeAntennas (об'єкт передано за посиланням) ---";
    for (int i = 0; i < 3; ++i) {
        cout << "\nВведення даних для антени " << i + 1 << ":\n";
        // **Ми працюємо з оригінальним об'єктом, а не з копією**
        systemRef.inputAntenna();
    }
}

void modifySystem(Antenna& systemRef) {
    cout << "\n--- Виклик функції modifySystem (об'єкт передано за посиланням) ---";

    cout << "\nСпроба змінити коефіцієнт підсилення антени 1 на некоректне значення (-1 дБ):\n";

    if (!systemRef.setGainFactor(0, -1.0f)) {
        cout << "Помилка: Некоректний коефіцієнт підсилення!\n";
    }

    cout << "\nЗміна коефіцієнта підсилення антени 1 на коректне значення (9.0 дБ):\n";
    if (systemRef.setGainFactor(0, 9.0f)) {
        cout << "Коефіцієнт підсилення успішно змінено!\n";
    }

    cout << "\nВставка нової антени на позицію 1:\n";
    antenna_s_t newAntenna = {"Патч", 7.5f, 2400.0f, 2500.0f};
    systemRef.insertAntenna(1, newAntenna);

    cout << "\nОбмін антен 1 і 2:\n";
    systemRef.swapAntennas(0, 1);

    cout << "\nВидалення антени 2:\n";
    systemRef.removeAntenna(1);
}


int main() {
    Antenna system;

    addThreeAntennas(system);

    system.displayAllAntennas();

    modifySystem(system);

    system.displayAllAntennas();

    cout << "\nОчищення списку антен:\n";
    system.clearAntennas();
    system.displayAllAntennas();

    return 0;
}