#ifndef TRANSISTOR_H
#define TRANSISTOR_H

#include <string>
#include <iostream>
#include <fstream>
#include <exception>

using namespace std;

class InvalidDataException : public exception {
private:
    string message;
public:
    InvalidDataException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class Transistor {
protected:
    string model;
    double maxPower;

public:
    Transistor();
    Transistor(string model, double maxPower);
    virtual ~Transistor();

    virtual void input();
    virtual void print() const;
    
    virtual void saveToFile(ofstream& ofs) const;
    virtual void readFromFile(ifstream& ifs);

    string getModel() const { return model; }
    double getMaxPower() const { return maxPower; }

    bool operator>(const Transistor& other) const;
    bool operator<(const Transistor& other) const;
};

#endif