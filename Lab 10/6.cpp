#include <iostream>
#include <fstream>
using namespace std;

struct InventoryItem {
    int itemID;
    char itemName[20];
};

int main() {
    InventoryItem item1 = {101, "WidgetX"};
    ofstream out("inventory.dat", ios::binary);
    out.write((char*)&item1, sizeof(item1));
    out.close();

    InventoryItem item2;
    ifstream in("inventory.dat", ios::binary);
    in.read((char*)&item2, sizeof(item2));
    in.close();

    cout << "Loaded Item ID: " << item2.itemID << ", Name: " << item2.itemName << endl;
    return 0;
}
