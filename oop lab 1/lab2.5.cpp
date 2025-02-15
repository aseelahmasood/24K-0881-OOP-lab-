#include<iostream>
using namespace std;

int main(){
    int n,sum=0;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int* arr=new int[n];
    cout<<"Enter elements: ";
    
    for(int i=0;i<n;i++)
        cin>>*(arr+i);
    cout<<"Array elements: ";
    for (int i=0;i<n;i++)
        cout<<*(arr+i);
    for(int i=0;i<n;i++)
        sum+=*(arr+i);

    cout<<"Sum of elements: "<<sum <<endl;
    delete[] arr;
    return 0;
}
