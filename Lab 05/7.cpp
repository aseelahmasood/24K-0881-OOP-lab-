#include <iostream>
#include <algorithm>
using namespace std;

class Product {
public:
    int id;
    string name;
    int quantity;

    Product(int pid, string pname, int pquantity) : id(pid), name(pname), quantity(pquantity) {}
    void display() {
        cout << "ID: " << id << ", Name: " << name << ", Quantity: " << quantity << endl;
    }
};

class Inventory {
private:
    Product* products[100];
    int count;
public:
    Inventory() : count(0) {}
    void addProduct(int id, string name, int quantity) {
        products[count++] = new Product(id, name, quantity);
    }
    void sortProducts() {
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (products[j]->name > products[j + 1]->name) {
                    swap(products[j], products[j + 1]);
                }
            }
        }
    }
    Product* searchByID(int id) {
        for (int i = 0; i < count; i++) {
            if (products[i]->id == id) return products[i];
        }
        return nullptr;
    }
    void displayProducts() {
        for (int i = 0; i < count; i++) {
            products[i]->display();
        }
    }
};

int main() {
    Inventory inventory;
    inventory.addProduct(101, "Table", 10);
    inventory.addProduct(102, "Chair", 20);
    inventory.addProduct(103, "Lamp", 15);
    
    cout << "Before Sorting:" << endl;
    inventory.displayProducts();
    
    inventory.sortProducts();
    cout << "\nAfter Sorting:" << endl;
    inventory.displayProducts();
    
    int searchID = 102;
    Product* found = inventory.searchByID(searchID);
    if (found) {
        cout << "\nProduct Found:" << endl;
        found->display();
    } else {
        cout << "\nProduct with ID " << searchID << " not found." << endl;
    }
    return 0;
}