#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream file("vehicles.txt");
    string line;

    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;

        istringstream iss(line);
        string type, id, name, year, extra, cert;

        getline(iss, type, ',');
        getline(iss, id, ',');
        getline(iss, name, ',');
        getline(iss, year, ',');
        getline(iss, extra, ',');
        getline(iss, cert, ',');

        cout << type << " | " << id << " | " << name << " | " << year << " | " << extra << " | " << cert << endl;
    }

    file.close();
    return 0;
}
