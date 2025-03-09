#include <iostream>
#include <cstring>
using namespace std;

class Apartment {
    int id;
    char address[100];
    char* owner;
public:
    Apartment(int aptID, const char* aptAddress, const char* aptOwner) : id(aptID) {
        strcpy(address, aptAddress);
        owner = new char[strlen(aptOwner) + 1];
        strcpy(owner, aptOwner);
    }
    Apartment(const Apartment& other) : id(other.id) {
        strcpy(address, other.address);
        owner = other.owner;
    }
    ~Apartment() { delete[] owner; }
    void display() {
        cout << "Apartment ID: " << id << "\nAddress: " << address << "\nOwner: " << owner << "\n";
    }
};

int main() {
    Apartment apt1(101, "123 Main St", "John Doe"), apt2 = apt1;
    cout << "Original Apartment:\n"; apt1.display();
    cout << "Copied Apartment:\n"; apt2.display();
    return 0;
}
