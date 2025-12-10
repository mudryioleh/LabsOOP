#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
using namespace std;

template <typename T>
class Storage {
private:
    T data;
public:
    Storage(T d) : data(d) {}
    
    void display() const {
        cout << "[Generic Storage]: " << data << endl;
    }
};

template <>
class Storage<double> {
private:
    double data;
public:
    Storage(double d) : data(d) {}

    void display() const {
        cout << "[Double Specialization]: Precision data -> " << data << " (Exact)" << endl;
    }
};

template <typename T>
class Storage<T*> {
private:
    T* ptrData;
public:
    Storage(T* d) : ptrData(d) {}

    void display() const {
        if (ptrData) {
            cout << "[Pointer Specialization]: Dereferenced value -> " << *ptrData << endl;
        } else {
            cout << "[Pointer Specialization]: NULL POINTER!" << endl;
        }
    }
};

#endif