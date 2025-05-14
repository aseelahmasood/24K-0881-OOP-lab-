#include <iostream>
#include <string>
using namespace std;

class Person{
protected:
    string name;
    int age;
    string contactNumber;
    string address;

public:
    Person(string n, int a, string contact, string addr = "")
        : name(n), age(a), contactNumber(contact), address(addr) {}

    virtual void displayInfo() const {
        cout << "Name: " << name << ", Age: " << age
             << ", Contact: " << contactNumber << ", Address: " << address << endl;
    }

    virtual void updateInfo(string newContact, string newAddress) {
        contactNumber = newContact;
        address = newAddress;
    }
};

class Patient : public Person {
    int patientID;
    string medicalHistory;
    string doctorAssigned;

public:
    Patient(string n, int a, string contact, string addr,
            int pid, string history, string doctor)
        : Person(n, a, contact, addr), patientID(pid),
          medicalHistory(history), doctorAssigned(doctor) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Patient ID: " << patientID << ", History: " << medicalHistory
             << ", Doctor: " << doctorAssigned << endl;
    }
};

class Doctor : public Person {
    string specialization;
    double consultationFee;
    int patientCount;

public:
    Doctor(string n, int a, string contact, string addr,
           string spec, double fee, int count)
        : Person(n, a, contact, addr), specialization(spec),
          consultationFee(fee), patientCount(count) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Specialization: " << specialization << ", Fee: $" << consultationFee
             << ", Patients: " << patientCount << endl;
    }

    void updateInfo(string newContact, string newAddress) override {
        Person::updateInfo(newContact, newAddress);
    }
};

class Nurse : public Person {
    string assignedWard;
    string shiftTimings;

public:
    Nurse(string n, int a, string contact, string addr,
          string ward, string shift)
        : Person(n, a, contact, addr), assignedWard(ward), shiftTimings(shift) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Ward: " << assignedWard << ", Shift: " << shiftTimings << endl;
    }
};

class Administrator : public Person {
    string department;
    double salary;

public:
    Administrator(string n, int a, string contact, string addr,
                  string dept, double sal)
        : Person(n, a, contact, addr), department(dept), salary(sal) {}

    void updateInfo(string newContact, string newAddress) override {
        Person::updateInfo(newContact, newAddress);
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << department << ", Salary: $" << salary << endl;
    }
};

int main() {
    Patient p("Ali", 30, "1234567890", "Street A", 1001, "Diabetes", "Dr. Ahmad");
    Doctor d("Dr. Ahmad", 45, "9876543210", "Street B", "Cardiology", 1500.0, 25);
    Nurse n("Sara", 28, "111223344", "Street C", "Ward 3", "Night");
    Administrator a("Kamal", 50, "999888777", "Street D", "HR", 80000.0);

    p.displayInfo();
    d.displayInfo();
    n.displayInfo();
    a.displayInfo();

    return 0;
}
