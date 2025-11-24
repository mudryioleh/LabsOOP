#ifndef DERIVED_TRANSISTORS_H
#define DERIVED_TRANSISTORS_H

#include "transistor.h"
class BipolarTransistor : public Transistor {
private:
    double gain;
    string type;

public:
    BipolarTransistor() : Transistor(), gain(0), type("NPN") {}
    BipolarTransistor(string m, double p, double g, string t);

    void input() override;
    void print() const override;
    void saveToFile(ofstream& ofs) const override;
    void readFromFile(ifstream& ifs) override;
};

class FieldEffectTransistor : public Transistor {
private:
    double gateThreshold; 
    string channelType;

public:
    FieldEffectTransistor() : Transistor(), gateThreshold(0), channelType("N-CH") {}
    FieldEffectTransistor(string m, double p, double gt, string ct);

    void input() override;
    void print() const override;
    void saveToFile(ofstream& ofs) const override;
    void readFromFile(ifstream& ifs) override;
};

#endif