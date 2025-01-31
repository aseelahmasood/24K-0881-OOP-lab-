#include <iostream>
#include <string>
using namespace std;

int main(){
    const int num=5;

    string Event1[num], Event2[num];

    for(int i=0; i<num; i++){
        cout << "Enter the participant name of " << i+1 << " partcipant for the 1st event: ";
        cin >> Event1[i];
    }

    for(int i=0; i<num; i++){
        cout << "Enter the participant name of " << i+1 << " partcipant for the 2nd event: ";
        cin >> Event2[i];
    }

    AttendanceChecker(Event1, Event2);
    cout<<endl<<"The total donation collected from both events are: "<< 2*num<< "$"<<endl;
    ReverseOrder(Event1, Event2);




}
void AttendanceChecker(string Event1[], string Event2[]){
    int flag=0;
    string name;
    cout<<"Enter the participant name to check: ";
    cin>>name;

    for(int i=0; i<5; i++){
        if(Event1[i] == name || Event2[i]==name){
            flag=1;
        }
    }
    if(flag==1){
        cout << "Participant is registered!" << endl;
    }
    else{
        cout << "Participant is not registered!" << endl;
    }
}

void ReverseOrder(string Event1[], string Event2[]){
    cout<<endl<< "First Event participant names in reverse order are: "<<endl;
    for(int i=4; i>=0; i++){
        cout << i+1 <<". " << Event1[i] << endl;
    }

    cout<<endl<<"Second Event participant names in reverse order are: "<<endl;
    for(int i=4; i>=0; i++){
        cout << i+1 <<". " << Event2[i] << endl;
    }
}
