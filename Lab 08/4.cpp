#include <iostream>
#include <string>
using namespace std;
class Car {
private:
    string model;
    double price;

public:
    Car(string m,double p) {
        model=m;
        price=p;
    }

    friend class InventoryManager;
    friend void comparePrice(const Car& c1, const Car& c2);
};

class InventoryManager {
public:
    void updateModel(Car& car, string newModel) {
        car.model= newModel;
    }

    void updatePrice(Car& car, double newPrice) {
        car.price = newPrice;
    }

    void display(const Car& car) {
        cout << "Model: " << car.model << ", Price: " << car.price << endl;
    }
};

void comparePrice(const Car& c1, const Car& c2) {
    if (c1.price > c2.price)
        cout << c1.model << " is more expensive." << endl;
    else if (c1.price < c2.price)
        cout << c2.model << " is more expensive." << endl;
    else
        cout << "Both cars have the same price." << endl;
}

int main() {
    Car car1("Sedan", 25000), car2("SUV", 30000);
    InventoryManager manager;

    manager.display(car1);
    manager.display(car2);

    manager.updatePrice(car1, 31000);
    manager.display(car1);

    comparePrice(car1, car2);

    return 0;
}
