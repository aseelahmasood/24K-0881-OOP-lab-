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


}
