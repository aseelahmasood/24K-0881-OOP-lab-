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
        brand=new char[8];
        model=new char[8];
        strcpy(brand,"Unknown");
        strcpy(model,"Generic");
        rentalPrice=0.0;
        available =true;
    }

    ~Car(){
        delete[] brand;
        delete[] model;
    }


    void processRentalRequest(){
        if (!available) {
            cout<< "Car is already rented."<<endl;
            return;
        }
        available= false;
        cout<<"Car rented successfully."<<endl;
    }

    void returnCar(){
        available=true;
    }
};

int main(){
    Car car1;
    car1.processRentalRequest();
    car1.processRentalRequest();
    car1.returnCar();
    car1.processRentalRequest();
    return 0;
}
