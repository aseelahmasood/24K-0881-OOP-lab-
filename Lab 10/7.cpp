#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("sensor_log.txt");
    file << "Sensor 1: 25.5 C\n";
    cout << "Position after line 1: " << file.tellp() << endl;

    file << "Sensor 2: 98.1 %RH\n";
    cout << "Position after line 2: " << file.tellp() << endl;

    file.close();
    return 0;
}
