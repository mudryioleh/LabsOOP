#include <iostream>
#include <string>
#include "Antenna.h"
#include "Storage.h"

using namespace std;

int main() {
    cout << "=== Lab 17: Templates & Specialization ===\n" << endl;

    Storage<int> intStore(42);
    Storage<string> stringStore("Hello Templates");
    
    Antenna myAntenna("Yagi", 15.5, "400-500 MHz");
    Storage<Antenna> antennaStore(myAntenna);

    cout << "--- Generic Template Usage ---" << endl;
    intStore.display();
    stringStore.display();
    antennaStore.display();
    cout << endl;

    Storage<double> doubleStore(99.99);

    cout << "--- Full Specialization (for double) ---" << endl;
    doubleStore.display(); 
    cout << endl;

    Antenna* ptrToAntenna = &myAntenna;
    Storage<Antenna*> pointerStore(ptrToAntenna);

    int number = 777;
    Storage<int*> pointerIntStore(&number);

    cout << "--- Partial Specialization (for pointers T*) ---" << endl;
    pointerStore.display();
    pointerIntStore.display();
    
    return 0;
}