#include <iostream>
#include <exception>
using namespace std;

class InvalidTemperatureException : public exception {};

template<typename T>
double convertToFahrenheit(T celsius) {
    if (celsius < -273.15)
        throw InvalidTemperatureException();
    return (celsius * 9.0 / 5.0) + 32;
}

int main() {
    try {
        double result = convertToFahrenheit(-300.0);
        cout << "Fahrenheit: " << result << endl;
    } catch (const exception& e) {
        cout << "Caught InvalidTemperatureException\nwhat(): " << e.what() << endl;
    }

    return 0;
}
