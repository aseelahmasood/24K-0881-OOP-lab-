#include <iostream>
#include <exception>
using namespace std;

class NegativeStockException : public exception {};
class OverCapacityException : public exception {};

template<typename T>
class InventoryItem {
    T stock;
    const T MAX_CAPACITY = 100;

public:
    void setStock(T s) {
        if (s < 0)
            throw NegativeStockException();
        if (s > MAX_CAPACITY)
            throw OverCapacityException();
        stock = s;
    }
};

int main() {
    InventoryItem<int> item;

    try {
        item.setStock(-5);
    } catch (const exception& e) {
        cout << "Caught NegativeStockException\nwhat(): " << e.what() << endl;
    }

    try {
        item.setStock(120);
    } catch (const exception& e) {
        cout << "Caught OverCapacityException\nwhat(): " << e.what() << endl;
    }

    return 0;
}
