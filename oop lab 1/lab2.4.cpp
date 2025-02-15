#include <iostream>
#include <string>
using namespace std;

void sortStrings(string arr[],int n){
    for (int i= 0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                string temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]= temp;
            }
        }
    }
}

int main(){
    int n;
    cout<<"Enter number of strings: ";
    cin>>n;

    string* strArray=new string[n];

    cout<<"Enter strings:"<<endl;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,strArray[i]);
    }
    sortStrings(strArray,n);

    cout<<"sorted strings: "<<endl;
    for(int i=0;i<n;i++){
        cout<<strArray[i]<<endl;
    }
    delete[] strArray;
    return 0;
}
