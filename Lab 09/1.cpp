#include <iostream>
using namespace std;

class Patient {
protected:
    string name;
    string id;

public:
    Patient(string n, string i) : name(n), id(i) {}

    virtual void displayTreatment() = 0;
    virtual double calculateCost() = 0;

    virtual ~Patient() {}
};

class InPatient : public Patient {
public:
    InPatient(string n, string i) : Patient(n, i) {}

    void displayTreatment() override {
        cout << "In-Patient Treatment Plan for " << name << " (ID: " << id << "):\n";
        cout << "- Admitted for 5 days\n- Medication and Surgery included\n";
    }

    double calculateCost() override {
        return 5 * 2000 + 5000; // Days * daily charge + surgery
    }
};

class OutPatient : public Patient {
public:
    OutPatient(string n, string i) : Patient(n, i) {}

    void displayTreatment() override {
        cout << "Out-Patient Treatment Plan for " << name << " (ID: " << id << "):\n";
        cout << "- Routine check-up\n- Medication prescribed\n";
    }

    double calculateCost() override {
        return 500 + 200; // Consultation + medication
    }
};

int main() {
    Patient* p1 = new InPatient("Alice", "IP001");
    Patient* p2 = new OutPatient("Bob", "OP002");

    p1->displayTreatment();
    cout << "Total Cost: $" << p1->calculateCost() << "\n\n";

    p2->displayTreatment();
    cout << "Total Cost: $" << p2->calculateCost() << "\n";

    delete p1;
    delete p2;
    return 0;
}
