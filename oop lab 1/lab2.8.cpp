#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int** arr = new int*[n];

    for (int i = 0; i < n; i++) {
        arr[i] = new int;
        cout << "Enter value for element " << i + 1 << ": ";
        cin >> *arr[i];
    }

    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
        cout << *arr[i] << " ";

    for (int i = 0; i < n; i++)
        delete arr[i];

    delete[] arr;
    return 0;
}
