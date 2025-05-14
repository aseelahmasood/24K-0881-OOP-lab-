#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream initFile("config.txt");
    initFile << "AAAAABBBBBCCCCC";
    initFile.close();

    fstream file("config.txt", ios::in | ios::out);
    if (!file) {
        cout << "Error opening file for update." << endl;
        return 1;
    }

    file.seekp(5);
    file << "XXXXX";
    file.close();

    ifstream in("config.txt");
    string content;
    getline(in, content);
    cout << "Updated File Content: " << content << endl;
    in.close();

    return 0;
}

