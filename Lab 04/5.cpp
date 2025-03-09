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
    int carID;

public:
    Car(int id,const char* br ="Unknown",const char* mo = "Generic", double price = 0.0, bool avail = true)
        : carID(id), rentalPrice(price),available(avail), totalRevenue(0.0) {
        brand =new char[strlen(br)+1];
        model =new char[strlen(mo)+ 1];
        strcpy(brand,br);
        strcpy(model,mo);
    }

    Car(const Car& other)
        :carID(other.carID),rentalPrice(other.rentalPrice), available(other.available), totalRevenue(other.totalRevenue) {
        brand =new char[strlen(other.brand)+1];
        model =new char[strlen(other.model)+ 1];
        strcpy(brand,other.brand);
        strcpy(model,other.model);
    }

    ~Car(){
        cout<<"Car object destroyed: "<<brand << " " << model <<endl;
        delete[] brand;
        delete[] model;
    }

    double applyDiscount(int days){
        if(days>10) return rentalPrice*0.90* days;
        if(days> 5) return rentalPrice*0.95* days;
        return rentalPrice*days;
    }

    bool processRentalRequest(int days){
        if (!available){
            cout<< "Car is already rented."<<endl;
            return false;
        }
        available =false;
        double totalCost= applyDiscount(days);
        totalRevenue+=totalCost;
        cout<< "Total rental cost: " << totalCost <<endl;
        return true;
    }

    void returnCar(){
        available =true;
    }

    void displayDetails() {
        cout << "Car ID: " << carID <<endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model <<endl;
        cout << "Rental Price: " << rentalPrice <<endl;
        cout << "Availability: " << (available ? "Available" : "Rented") <<endl;
        cout << "Total Revenue: " << totalRevenue <<endl;
    }
};

int main(){
    Car car1(101,"Toyota","Camry",70.0,true);
    Car car2(102,"Honda","Civic",60.0,true);
    
    car1.processRentalRequest(7);
    car1.displayDetails();
    
    car1.returnCar();
    car1.processRentalRequest(12);
    car1.displayDetails();
    
    car2.displayDetails();
    
    return 0;
}