#include <iostream>
using namespace std;

class AlarmSystem {
    string securityLevel;
public:
    AlarmSystem(string level) : securityLevel(level) {}
    void display() { cout << "Alarm Security Level: " << securityLevel << "\n"; }
};

class SmartHome {
    AlarmSystem alarm;
    string homeName;
public:
    SmartHome(string name, string level) : homeName(name), alarm(level) {}
    void displayDetails() {
        cout << "Smart Home: " << homeName << "\n";
        alarm.display();
    }
};

int main() {
    SmartHome home("Modern Villa", "High");
    home.displayDetails();
    return 0;
}
