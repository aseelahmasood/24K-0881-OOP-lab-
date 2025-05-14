#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("large_log.txt");
    char buffer[11];
    file.read(buffer, 10);
    buffer[10] = '\0';
    cout << "First Read: " << buffer << ", Position: " << file.tellg() << endl;

    file.read(buffer, 10);
    buffer[10] = '\0';
    cout << "Second Read: " << buffer << ", Position: " << file.tellg() << endl;

    file.close();
    return 0;
}
