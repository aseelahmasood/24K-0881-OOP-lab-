#include <iostream>
#include <string>
using namespace std;

int main() {
    string type = "HybridTruck";
    string extra = "Cargo:5000 | Battery:75";
    size_t colon1 = extra.find(':');
    size_t pipe = extra.find('|');
    size_t colon2 = extra.find(':', pipe);

    if (type == "HybridTruck" && colon1 != string::npos && pipe != string::npos && colon2 != string::npos) {
        int cargo = stoi(extra.substr(colon1 + 1, pipe - colon1 - 2));
        int battery = stoi(extra.substr(colon2 + 1));
        cout << "Cargo: " << cargo << " kg, Battery: " << battery << " kWh" << endl;
    } else {
        cout << "Unknown vehicle type or format error." << endl;
    }

    return 0;
}
