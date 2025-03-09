#include <iostream>
#include <cstring>
using namespace std;

class Car{
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
        rentalPrice =0.0;
        available=true;
    }

    Car(const char* br, const char* mo, double price, bool avail) {
        brand =new char[strlen(br)+ 1];
        model= new char[strlen(mo) +1];
        strcpy(brand,br);
        strcpy(model,mo);
        rentalPrice =price;
        available=  avail;
    }

    Car(const Car& other){
        brand=new char[strlen(other.brand)+ 1];
        model =new char[strlen(other.model)+ 1];
        strcpy(brand,other.brand);
        strcpy(model,other.model);
        rentalPrice =other.rentalPrice;
        available=other.available;
    }

    ~Car(){
        cout<<"Car object destroyed: " << brand << " " << model <<endl;
        delete[] brand;
        delete[] model;
    }

    void displayCar(){
        cout<<"Brand: "<<brand<<", Model: "<< model <<endl;
    }
};

int main(){
    
    Car car1("Honda","Civic",60.0,true);
    Car car2 = car1; 
    car1.displayCar();
    car2.displayCar();
    
    return 0;
}