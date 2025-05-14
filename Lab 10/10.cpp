#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("data_records.txt");
    file.seekg(18);  // Assuming Record 1 + \n + Record 2 + \n = 9 + 1 + 9 + 1 = 20
    string line;
    getline(file, line);
    cout << "Record 3: " << line << endl;
    file.close();
    return 0;
}
