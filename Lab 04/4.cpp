#include <iostream>
#include <cstring>
using namespace std;
class Car {
private:
    char* brand;
    char* model;
    double rentalPrice;
    bool available;
    double totalRevenue;

public:
    Car(){
        brand=new char[8];
        model= new char[8];
        strcpy(brand,"Unknown");
        strcpy(model,"Generic");
        rentalPrice=0.0;
        available=true;
        totalRevenue= 0.0;
    }

    Car(const char* br, const char* mo, double price, bool avail) {
        brand =new char[strlen(br)+ 1];
        model =new char[strlen(mo)+1];
        strcpy(brand,br);
        strcpy(model, mo);
        rentalPrice=price;
        available=avail;
        totalRevenue= 0.0;
    }

    Car(const Car& other){
        brand =new char[strlen(other.brand)+1];
        model= new char[strlen(other.model)+ 1];
        strcpy(brand,other.brand);
        strcpy(model,other.model);
        rentalPrice=other.rentalPrice;
        available= other.available;
        totalRevenue =other.totalRevenue;
    }

    ~Car(){
        cout<<"Car object destroyed: "<<brand<< " " << model <<endl;
        delete[] brand;
        delete[] model;
    }

    double applyDiscount(int days) {
        if(days>10) return rentalPrice*0.90* days;
        if(days> 5) return rentalPrice*0.95* days;
        return rentalPrice*days;
    }

    bool processRentalRequest(int days) {
        if(!available){
            cout<<"Car is already rented."<<endl;
            return false;
        }
        available=false;
        double totalCost=applyDiscount(days);
        totalRevenue+=totalCost;
        cout<<"Total rental cost: "<< totalCost <<endl;
        return true;
    }

    void returnCar(){
        available =true;
    }

    void displayRevenue(){
        cout<<"Total Revenue: " << totalRevenue <<endl;
    }
};

int main(){
    Car car1("Toyota", "Camry", 70.0, true);
    car1.processRentalRequest(7);
    car1.displayRevenue();
    
    car1.returnCar();
    car1.processRentalRequest(12);
    car1.displayRevenue();
    
    return 0;
}