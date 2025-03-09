#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
    float salary;
public:
    Employee(string empName,float empSalary) :name(empName),salary(empSalary){}
    virtual void displayDetails(){
        cout<<"Name: " <<name<<", Salary: "<<salary <<endl;
    }
};

class Manager : public Employee {
private:
    float bonus;
public:
    Manager(string mgrName,float mgrSalary,float mgrBonus): Employee(mgrName,mgrSalary),bonus(mgrBonus){}
    void displayDetails()override{
        cout<< "Name: "<<name<<", Salary: "<<salary << ", Bonus: "<< bonus<<endl;
    }
};

int main() {
    string name;
    float salary, bonus;
    cout<<"Enter Manager Name: ";
    cin>>name;
    cout<<"Enter Salary: ";
    cin>>salary;
    cout<< "Enter Bonus: ";
    cin >>bonus;
    
    Manager mgr(name,salary,bonus);
    mgr.displayDetails();
    
    return 0;
}
