#include <iostream>
using namespace std;

class Vehicle {
protected:
    string brand;
    int speed;
public:
    Vehicle(string b, int s) : brand(b), speed(s) {}
    virtual void displayDetails() {
        cout << "Brand: " << brand << ", Speed: " << speed << " km/h" << endl;
    }
};

class Car : public Vehicle {
protected:
    int seats;
public:
    Car(string b, int s, int seatCount) : Vehicle(b, s), seats(seatCount) {}
    void displayDetails() override {
        Vehicle::displayDetails();
        cout << "Seats: " << seats << endl;
    }
};

class ElectricCar : public Car {
private:
    int batteryLife;
public:
    ElectricCar(string b, int s, int seatCount, int battery) : Car(b, s, seatCount), batteryLife(battery) {}
    void displayDetails() override {
        Car::displayDetails();
        cout << "Battery Life: " << batteryLife << " hours" << endl;
    }
};

int main() {
    ElectricCar myCar("Tesla", 200, 5, 12);
    myCar.displayDetails();
    return 0;
}
#include <iostream>
using namespace std;

class Vehicle {
protected:
    string brand;
    int speed;
public:
    Vehicle(string b, int s) : brand(b), speed(s) {}
    virtual void displayDetails() {
        cout << "Brand: " << brand << ", Speed: " << speed << " km/h" << endl;
    }
};

class Car : public Vehicle {
protected:
    int seats;
public:
    Car(string b, int s, int seatCount) : Vehicle(b, s), seats(seatCount) {}
    void displayDetails() override {
        Vehicle::displayDetails();
        cout << "Seats: " << seats << endl;
    }
};

class ElectricCar : public Car {
private:
    int batteryLife;
public:
    ElectricCar(string b, int s, int seatCount, int battery) : Car(b, s, seatCount), batteryLife(battery) {}
    void displayDetails() override {
        Car::displayDetails();
        cout << "Battery Life: " << batteryLife << " hours" << endl;
    }
};

int main() {
    ElectricCar myCar("Tesla", 200, 5, 12);
    myCar.displayDetails();
    return 0;
}
