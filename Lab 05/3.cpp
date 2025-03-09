#include <iostream>
#include <vector>
using namespace std;

class Employee {
    string name, designation;
public:
    Employee(string n, string d) : name(n), designation(d) {}
    string getName() { return name; }
};

class Project {
    string title, deadline;
    vector<Employee*> employees;
public:
    Project(string t, string d) : title(t), deadline(d) {}
    void addEmployee(Employee* e) { employees.push_back(e); }
    void displayDetails() {
        cout << "Project: " << title << "\nDeadline: " << deadline << "\nEmployees: ";
        for (auto e : employees) cout << e->getName() << " ";
        cout << "\n";
    }
};

int main() {
    Employee e1("Alice", "Developer"), e2("Bob", "Manager");
    Project p1("AI System", "30-06-2025");
    p1.addEmployee(&e1);
    p1.addEmployee(&e2);
    p1.displayDetails();
    return 0;
}
