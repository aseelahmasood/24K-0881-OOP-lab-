#include <iostream>
#include <cstring>
using namespace std;

class Car {
private:
    char* brand;
    char* model;
    double rentalPrice;
    bool available;

public:
    Car(){
        brand= new char[8];
        model=new char[8];
        strcpy(brand, "Unknown");
        strcpy(model,"Generic");
        rentalPrice =0.0;
        available= true;
    }


    Car(const char* br, const char* mo, double price, bool avail) {
        brand = new char[strlen(br)+1];
        model = new char[strlen(mo)+ 1];
        strcpy(brand,br);
        strcpy(model,mo);
        rentalPrice =price;
        available=avail;
    }

    ~Car(){
        delete[] brand;
        delete[] model;
    }

    double applyDiscount(int days) {
        if (days>10) return rentalPrice*0.90*days;
        if (days> 5) return rentalPrice*0.95* days;
        return rentalPrice * days;
    }

    bool processRentalRequest(int days) {
        if (!available) {
            cout<<"Car is already rented."<<endl;
            return false;
        }
        available= false;
        double totalCost =applyDiscount(days);
        cout<<"Total rental cost: " << totalCost <<endl;
        return true;
    }

    void returnCar(){
        available=true;
    }
};

int main(){
    Car car1("Toyota","Corolla",50.0,  true);
    car1.processRentalRequest(7);
    car1.returnCar();
    car1.processRentalRequest(12);
    return 0;
}
