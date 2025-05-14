#include <iostream>
#include <string>
using namespace std;

int main() {
    string type = "AutonomousCar";
    string id = "AC101";
    string extra = "SW: 4.5";

    size_t pos = extra.find(':');
    if (type == "AutonomousCar" && pos != string::npos) {
        string value = extra.substr(pos + 1);
        float swVersion = stof(value);
        cout << "ID: " << id << ", Software Version: " << swVersion << endl;
    } else if (type == "Electric Vehicle") {
        pos = extra.find(':');
        if (pos != string::npos) {
            int battery = stoi(extra.substr(pos + 1));
            cout << "ID: " << id << ", Battery Capacity: " << battery << " kWh" << endl;
        }
    }

    return 0;
}
