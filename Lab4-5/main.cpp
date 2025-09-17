#include <iostream>
#include <vector>

class Antenna {
private:
    std::string type;
    float gain_factor;
    float frequency_range;

public:
    Antenna() {
        type = "Default";
        gain_factor = 1.0;
        frequency_range = 100.0;
    }

    Antenna(std::string t, float g, float f) {
        type = t;
        setGain(g); 
        setFrequency(f);
    }

    Antenna(const Antenna& other) {
        type = other.type;
        gain_factor = other.gain_factor;
        frequency_range = other.frequency_range;
    }

    Antenna& operator=(const Antenna& other) {
        if (this != &other) {
            type = other.type;
            gain_factor = other.gain_factor;
            frequency_range = other.frequency_range;
        }
        return *this;
    }

    ~Antenna() {
        std::cout << "Antenna of type " << type << " is being destroyed." << std::endl;
    }

    std::string getType() const { return type; }
    float getGain() const { return gain_factor; }
    float getFrequency() const { return frequency_range; }

    void setType(std::string t) {
        type = t;
    }

    void setGain(float g) {
        if (g > 0) {
            gain_factor = g;
        } else {
            std::cout << "Invalid gain value: must be greater than 0." << std::endl;
        }
    }

    void setFrequency(float f) {
        if (f > 0) {
            frequency_range = f;
        } else {
            std::cout << "Invalid frequency range: must be greater than 0." << std::endl;
        }
    }


    void inputData() {
        std::cout << "Enter antenna type: ";
        std::cin >> type;

        do {
            std::cout << "Enter gain factor (> 0): ";
            std::cin >> gain_factor;
            if (gain_factor <= 0) {
                std::cout << "Invalid gain value: must be greater than 0. Try again." << std::endl;
            }
        } while (gain_factor <= 0);

        do {
            std::cout << "Enter frequency range (> 0): ";
            std::cin >> frequency_range;
            if (frequency_range <= 0) {
                std::cout << "Invalid frequency range: must be greater than 0. Try again." << std::endl;
            }
        } while (frequency_range <= 0);
    }

    void displayInfo() const {
        std::cout << "Antenna Info: Type: " << type << ", Gain factor: " << gain_factor << ", Frequency range: " << frequency_range << std::endl;
    }

    bool matchesGainCriterion(float min_gain) const {
        return gain_factor >= min_gain;
    }
};

int main() {
   
    Antenna defaultAntenna;
    defaultAntenna.displayInfo();

    Antenna dipoleAntenna("Dipole", 2.15, 300.0); 
    dipoleAntenna.displayInfo();

    Antenna copiedAntenna(dipoleAntenna);
    copiedAntenna.displayInfo();

    Antenna userInputAntenna;
    userInputAntenna.inputData();
    userInputAntenna.displayInfo();

    defaultAntenna.setGain(1.5);  
    defaultAntenna.setFrequency(200.0);  
    defaultAntenna.setGain(-1.0); 
    defaultAntenna.displayInfo();

    Antenna assignedAntenna;
    assignedAntenna = dipoleAntenna;
    assignedAntenna.displayInfo();

    std::vector<Antenna> antennas = {defaultAntenna, dipoleAntenna, copiedAntenna, userInputAntenna, assignedAntenna};

    float min_gain = 2.0;
    std::cout << "Antennas with gain factor >= " << min_gain << ":" << std::endl;
    bool found = false;
    for (const auto& ant : antennas) {
        if (ant.matchesGainCriterion(min_gain)) {
            ant.displayInfo();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No antennas match the criterion." << std::endl;
    }

    return 0;
}