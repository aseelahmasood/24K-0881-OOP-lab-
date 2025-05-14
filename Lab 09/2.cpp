#include <iostream>
using namespace std;

class MenuItem {
protected:
    string dishName;
    double price;

public:
    MenuItem(string name, double p) : dishName(name), price(p) {}

    virtual void showDetails() = 0;
    virtual void prepare() = 0;

    virtual ~MenuItem() {}
};

class Appetizer : public MenuItem {
public:
    Appetizer(string name, double p) : MenuItem(name, p) {}

    void showDetails() override {
        cout << "Appetizer: " << dishName << " - $" << price << "\n";
    }

    void prepare() override {
        cout << "Preparing appetizer: Chopping and light seasoning...\n";
    }
};

class MainCourse : public MenuItem {
public:
    MainCourse(string name, double p) : MenuItem(name, p) {}

    void showDetails() override {
        cout << "Main Course: " << dishName << " - $" << price << "\n";
    }

    void prepare() override {
        cout << "Preparing main course: Cooking with spices and sides...\n";
    }
};

int main() {
    MenuItem* d1 = new Appetizer("Spring Rolls", 5.99);
    MenuItem* d2 = new MainCourse("Grilled Chicken", 14.99);

    d1->showDetails();
    d1->prepare();
    cout << "\n";

    d2->showDetails();
    d2->prepare();

    delete d1;
    delete d2;
    return 0;
}
