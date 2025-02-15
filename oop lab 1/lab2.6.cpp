#include<iostream>
#include<string>
using namespace std;

struct Student{
    string name;
    int rollNumber;
    float marks[3];
};
int main(){
    int n;
    cout<<"Enter number of students";
    cin>>n;

    Student* students=new Student[n];

    for (int i=0; i<n;i++){
        cout<< "Enter name,roll no and marks for 3 subjects for student "<<i+ 1 <<endl;
        cin.ignore();
        getline(cin,students[i].name);
        cin>>students[i].rollNumber>>students[i].marks[0]>>students[i].marks[1]>>students[i].marks[2];
    }

    cout<<"student records: "<<endl;
    for (int i =0;i< n;i++) {
        float avg=(students[i].marks[0]+ students[i].marks[1]+students[i].marks[2]) /3.0;
        cout<<students[i].name<<"(Roll No: "<<students[i].rollNumber<< ")-Average Marks: " << avg << endl;
    }
    delete[] students;
    return 0;
}
