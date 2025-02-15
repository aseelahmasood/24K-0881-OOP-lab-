#include<iostream>
#include<string>
using namespace std;

struct Employee{
    string name;
    double hoursWorked;
    double hourlyRate;
};
int main(){
    int n;
    cout<<"Enter number of employees: ";
    cin>>n;

    Employee* employees=new Employee[n];

    for(int i=0; i<n;i++){
        cout<<"Enter name,hours worked,and hourly rate for employee "<< i + 1 <<endl;
        cin.ignore();
        getline(cin,employees[i].name);
        cin>>employees[i].hoursWorked>>employees[i].hourlyRate;
    }

    cout<<"employee salaries: "<<endl;
    for (int i= 0;i<n;i++){
        double totalSalary=employees[i].hoursWorked *employees[i].hourlyRate;
        cout <<employees[i].name<<" - $"<<totalSalary<<endl;
    }

    delete[] employees;
    return 0;
}
