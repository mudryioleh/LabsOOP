#include <iostream>
#include <vector>
#include <fstream>
#include "transistor.h"
#include "derived_transistors.h"

using namespace std;


void saveDatabase(const vector<Transistor*>& db, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Cannot open file for writing!");
    }

    for (const auto& t : db) {
        t->saveToFile(file);
    }
    file.close();
    cout << "Database saved successfully to " << filename << endl;
}

void loadDatabase(vector<Transistor*>& db, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Cannot open file for reading!");
    }

    for (auto t : db) delete t;
    db.clear();

    char typeMarker;
    while (file >> typeMarker) {
        Transistor* t = nullptr;
        if (typeMarker == 'B') {
            t = new BipolarTransistor();
        } else if (typeMarker == 'F') {
            t = new FieldEffectTransistor();
        }

        if (t) {
            t->readFromFile(file);
            db.push_back(t);
        }
    }
    file.close();
    cout << "Database loaded successfully!" << endl;
}

int main() {
    vector<Transistor*> database;
    string filename = "transistors_db.txt";
    int choice;

    while (true) {
        cout << "\n=== Transistor Database Menu ===\n";
        cout << "1. Add Bipolar Transistor\n";
        cout << "2. Add Field Effect Transistor (FET)\n";
        cout << "3. Show All\n";
        cout << "4. Save to File\n";
        cout << "5. Load from File\n";
        cout << "6. Compare two transistors\n";
        cout << "0. Exit\n";
        cout << "Select option: ";
        cin >> choice;

        try {
            if (choice == 0) break;

            if (choice == 1) {
                Transistor* t = new BipolarTransistor();
                t->input();
                database.push_back(t);
            }
            else if (choice == 2) {
                Transistor* t = new FieldEffectTransistor();
                t->input();
                database.push_back(t);
            }
            else if (choice == 3) {
                cout << "\n--- List of Components ---\n";
                if (database.empty()) cout << "List is empty.\n";
                for (const auto& t : database) {
                    t->print(); 
                }
            }
            else if (choice == 4) {
                saveDatabase(database, filename);
            }
            else if (choice == 5) {
                loadDatabase(database, filename);
            }
            else if (choice == 6) {
                if (database.size() < 2) {
                    cout << "Need at least 2 transistors to compare.\n";
                } else {
                    cout << "Comparing first two elements:\n";
                    database[0]->print();
                    database[1]->print();
                    
                    if (*database[0] > *database[1]) {
                        cout << "Result: First is more powerful than Second.\n";
                    } else {
                        cout << "Result: First is NOT more powerful than Second.\n";
                    }
                }
            }
            else {
                cout << "Invalid option.\n";
            }

        }
        catch (const InvalidDataException& e) {
            cerr << "\n[DATA ERROR]: " << e.what() << endl;
        }
        catch (const runtime_error& e) {
            cerr << "\n[FILE ERROR]: " << e.what() << endl;
        }
        catch (const exception& e) {
            cerr << "\n[UNKNOWN ERROR]: " << e.what() << endl;
        }
    }

    for (auto t : database) delete t;

    return 0;
}