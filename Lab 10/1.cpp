#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("vehicles.txt");

    if (!file.is_open()) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;
        cout << "Read Line: " << line << endl;
    }

    file.close();
    return 0;
}
