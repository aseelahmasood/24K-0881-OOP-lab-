#include <iostream>
#include <vector>
using namespace std;

class Doctor {
private:
    string name, specialization;
    int experience;
public:
    Doctor(string n, string s, int e) : name(n), specialization(s), experience(e) {}
    string getName() { return name; }
    void display() {
        cout << "Doctor: " << name << ", Specialization: " << specialization << ", Experience: " << experience << " years\n";
    }
};

class Hospital {
private:
    string name, location;
    vector<Doctor*> doctors;
public:
    Hospital(string n, string l) : name(n), location(l) {}
    void addDoctor(Doctor* d) { doctors.push_back(d); }
    void display() {
        cout << "Hospital: " << name << ", Location: " << location << "\nDoctors:\n";
        for (auto d : doctors) d->display();
    }
};

int main() {
    Doctor d1("Dr. Smith", "Cardiology", 10);
    Doctor d2("Dr. Johnson", "Neurology", 8);
    Hospital h("City Hospital", "Downtown");
    h.addDoctor(&d1);
    h.addDoctor(&d2);
    h.display();
    return 0;
}

