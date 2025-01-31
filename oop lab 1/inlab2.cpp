#include <iostream>
#include <string>
using namespace std;

int main(){

    string Event1[5], Event2[5];

    for(int i=0; i<5; i++){
        cout << "Enter the participant name of " << i+1 << " partcipant for the 1st event: ";
        cin >> Event1[i];
    }

    for(int i=0; i<5; i++){
        cout << "Enter the participant name of " << i+1 << " partcipant for the 2nd event: ";
        cin >> Event2[i];
    }

    AttendanceChecker(Event1, Event2);


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