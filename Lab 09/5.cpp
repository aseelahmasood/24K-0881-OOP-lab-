#include <iostream>
using namespace std;

class Shipment {
protected:
    string trackingNumber;
    double weight;

public:
    Shipment(string tn,double wt) :trackingNumber(tn), weight(wt) {}

    virtual double estimateDeliveryTime()=0;
    virtual void showDetails() =0;

    virtual ~Shipment(){}
};

class AirFreight:public Shipment{
public:
    AirFreight(string tn,double wt):Shipment(tn,wt){}

    double estimateDeliveryTime() override {
        return 1.5 + (weight * 0.1);
    }

    void showDetails() override {
        cout << "Air Freight - Tracking: " << trackingNumber
             << ", Weight: " << weight << " kg"
             << ", Estimated Delivery: " << estimateDeliveryTime() << " days\n";
    }
};


class GroundShipment : public Shipment {
public:
    GroundShipment(string tn, double wt) : Shipment(tn, wt) {}

    double estimateDeliveryTime() override {
        return 3.0 + (weight * 0.2);  
    }

    void showDetails() override {
        cout << "Ground Shipment - Tracking: " << trackingNumber
             << ", Weight: " << weight << " kg"
             << ", Estimated Delivery: " << estimateDeliveryTime() << " days\n";
    }
};

int main() {
    Shipment* s1 = new AirFreight("AF123456", 12.5);
    Shipment* s2 = new GroundShipment("GS789101", 20.0);

    s1->showDetails();
    s2->showDetails();

    delete s1;
    delete s2;

    return 0;
}
