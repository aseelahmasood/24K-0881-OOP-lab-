#include <iostream>
using namespace std;

// Abstract Class
class WeatherSensor {
public:
    virtual void readData() = 0;
    virtual void displayReport() = 0;
    virtual ~WeatherSensor() {}
};

// Derived Thermometer
class Thermometer : public WeatherSensor {
private:
    double temperature;

public:
    void readData() override {
        // Simulated temperature reading
        temperature = 23.5;
    }

    void displayReport() override {
        cout << "Temperature: " << temperature << " °C\n";
    }
};

// Derived Barometer
class Barometer : public WeatherSensor {
private:
    double pressure;

public:
    void readData() override {
        // Simulated pressure reading
        pressure = 1013.25;
    }

    void displayReport() override {
        cout << "Pressure: " << pressure << " hPa\n";
    }
};

int main() {
    WeatherSensor* s1 = new Thermometer();
    WeatherSensor* s2 = new Barometer();

    s1->readData();
    s2->readData();

    s1->displayReport();
    s2->displayReport();

    delete s1;
    delete s2;
    return 0;
}
