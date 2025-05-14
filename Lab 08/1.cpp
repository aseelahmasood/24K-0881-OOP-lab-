#include <iostream>
#include <cmath>
using namespace std;

class Complex{
private:
    double real;
    double imag;

public:
    Complex(double r=0,double i=0){
        real= r;
        imag =i;
    }

    Complex operator+(const Complex& other) {
        return Complex(real+other.real,imag+other.imag);
    }

    Complex operator-(const Complex& other){
        return Complex(real-other.real,imag - other.imag);
    }

    Complex operator*(const Complex& other) {
        return Complex(real * other.real - imag * other.imag,
                       real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex& other) {
        double denom = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denom,
                       (imag * other.real - real * other.imag) / denom);
    }

    double magnitude() {
        return sqrt(real * real + imag * imag);
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;
        if (c.imag >= 0)
            out << " + " << c.imag << "i";
        else
            out << " - " << -c.imag << "i";
        return out;
    }
};

int main() {
    Complex a(3, 4), b(1, 2);
    Complex sum = a + b;
    Complex diff = a - b;
    Complex prod = a * b;
    Complex div = a / b;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "Sum = " << sum << endl;
    cout << "Difference = " << diff << endl;
    cout << "Product = " << prod << endl;
    cout << "Division = " << div << endl;
    cout << "Magnitude of a = " << a.magnitude() << endl;

    return 0;
}
