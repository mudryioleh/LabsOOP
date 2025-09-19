#include "antenna.h"

int main() {
    Antenna system;

    for (int i = 0; i < 3; ++i) {
        std::cout << "\nВведення даних для антени " << i + 1 << ":\n";
        system.inputAntenna(i);
    }

    system.displayAllAntennas();

    return 0;
}