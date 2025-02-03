#include <iostream>
#include <string>

using namespace std;void input(int aqi[4][28],int days){
    for (int i=0;i<4;i++){
        cout<< "Enter AQI values for city "<<i+1<<endl;
        for(int j=0; j< days;j++){
            cout <<"Day "<<j+ 1<<endl;
            cin >>aqi[i][j];
        }
    }
}

void average(int aqi[4][28], int days, double cityAvg[]){
    int worstCity=0;
    double highest =0;

    cout<< "Average AQI for each city "<<endl;
    for (int i=0;i<4;i++){
        double sum=0;
        for (int j=0;j<days;j++){
            sum +=aqi[i][j];
        }
        cityAvg[i] =sum/days;

        cout<<"City "<<i+1<<": "<<cityAvg[i]<<endl;

        if(cityAvg[i]>highest){
            highest =cityAvg[i];
            worstCity= i;
        }
    }

    cout<<"City with the worst air quality: "<<worstCity+1<<"AQI: "<<highest<<endl;
}

void pollution(int aqi[4][28],int days){
    for (int i =0;i<4;i++) {
        bool found= 0;
        for (int j= 0; j<days; j++){
            if (aqi[i][j]>150){
                cout<<"Day "<<j+ 1<<"(AQI: " << aqi[i][j] << ")  ";
                found=1;
            }
        }
        if (!found) {
            cout << "None of the cities have critical pollution";
        }
        cout << endl;
    }
}

void visualizeAQI(int aqi[4][28], int days){
    cout << "AQI Data Visualization (* = 50): "<<endl;
    for (int i=0; i<4;i++) {
        for (int j =0;j<days;j++){
            cout<<"Day "<<j+1 << ": ";
            int num=aqi[i][j]/ 50;
            for (int k= 0;k< num;k++) {
                cout<<"*";
            }
            cout << " (" << aqi[i][j] << ")\n";
        }
        cout << endl;
    }
}

void calMonthly(int aqi[4][28]) {
    double firstWeek[4] = {0}, lastWeek[4] = {0}, monthlyAvg[4] = {0};
    int city=0;
    double largest=0;

    cout << "Monthly AQI Averages: "<<endl;
    for (int i=0;i<4;i++){
        double sum= 0;
        for (int j= 0;j< 28;j++){
            sum+=aqi[i][j];

            if (j< 7) firstWeek[i] += aqi[i][j];
            if (j>=21) lastWeek[i] += aqi[i][j];
        }
        monthlyAvg[i]=sum/28;
        firstWeek[i]/=7;
        lastWeek[i]/=7;

        cout<<"City "<<i+1<<" have monthly average of"<< monthlyAvg[i]<<endl;


        double improvement = firstWeek[i] - lastWeek[i];
        if (improvement > largest) {
            largest= improvement;
            city = i;
        }
    }

    cout << "\nCity with the most improved air quality: " << city+1 << " (Improvement: " << largest << " AQI points)\n";
}

void generateReport(int aqi[4][28], int days){
    double cityAvg[4] = {0};
    average(aqi, days, cityAvg);

    cout << " AQI Report "<<endl;
    cout << "Weekly Averages: "<<endl;
    for (int i=0; i<4; i++) {
        cout << "City " << i+1 << " have avg of: "<<cityAvg[i] << endl;
    }

    pollution(aqi, days);
    
    cout << "Comparison of highest and lowest AQI values: "<<endl;
    for (int i=0;i< 4;i++){
        int highest=aqi[i][0],lowest= aqi[i][0];
        for (int j=1; j<days;j++){
            if (aqi[i][j]>highest) highest=aqi[i][j];
            if (aqi[i][j]< lowest) lowest=aqi[i][j];
        }
        cout << "City "<< i+1 << " - Highest AQI: " << highest << ", Lowest AQI: " << lowest << endl;
    }
}

int main(){
    int aqi[4][28];
    cout<<"Enter AQI value for a week: "<<endl;
    input(aqi,7);
    double avg[4] ={0};
    average(aqi,7,avg);
    pollution(aqi,7);
    visualizeAQI(aqi,7);

    cout<<"Enter AQI data for the full month: "<<endl;
    input(aqi,28);
    calMonthly(aqi);

    generateReport(aqi,28);

    return 0;
}