#include <iostream>
using namespace std;

struct Product {
    int productID;
    string name;
    int quantity;
    float price;
};

int main() {
    int n;
    cout << "Enter the number of products: ";
    cin >> n;

    Product* inventory = new Product[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter Product ID, Name, Quantity, and Price for product " << i + 1 << ": ";
        cin >> inventory[i].productID >> inventory[i].name >> inventory[i].quantity >> inventory[i].price;
    }

    float totalValue = 0;
    for (int i = 0; i < n; i++)
        totalValue += inventory[i].quantity * inventory[i].price;

    cout << "Total Inventory Value: " << totalValue << endl;

    delete[] inventory;
    return 0;
}
