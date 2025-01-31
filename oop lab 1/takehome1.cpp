#include <iostream>
using namespace std;

int main(){
  const int no_of_cities = 4;
  const int days_week = 7;
  const int days_month = 28;
  int aqi[no_of_cities][days_month];
  


  for (int i=0;i<no_of_cities;i++) {
        cout<<"Enter AQI values for City "<< i+1 <<endl;
        for (int j = 0; j < days_month; j++) {
            cout<<"Day " << j + 1 << ": ";
            cin>>aqi[i][j];
        }
    }
    calculate_weekly_average(aqi);


}

void calculate_weekly_average(int aqi[no_of_cities][days_week]) {
    double avg[no_of_cities] = {0};
    int worstCity = 0;
    double highestAvg = 0;

    cout << "weekly AQI avgs: "<<endl;
    for (int i=0;i<no_of_cities; i++) {
        int sum = 0;
        for (int j=0; j<days_week;j++) {
            sum+=aqi[i][j];
        }
        avg[i]=sum/days_week;
        cout<<"City "<< i + 1 <<": " <<avg[i]<< endl;

        if (avg[i]>highestAvg) {
            highestAvg=avg[i];
            worstCity=i;
        }
    }
    cout << "City with the worst air quality: City " << worstCity + 1 << " (AQI: " << highestAvg << ")\n";
}

