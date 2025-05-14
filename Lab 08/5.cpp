#include <iostream>
using namespace std;
class Matrix2x2;

class MatrixHelper{
public:
    void updateElement(Matrix2x2& m,int row,int col,int value);
};

class Matrix2x2 {
private:
    int a,b,c,d;

public:
    Matrix2x2(int a=0,int b=0, int c=0, int d = 0) {
        this->a=a;
        this->b= b;
        this->c =c;
        this->d = d;
    }

    Matrix2x2 operator+(const Matrix2x2& other) {
        return Matrix2x2(a + other.a, b + other.b, c + other.c, d + other.d);
    }

    Matrix2x2 operator-(const Matrix2x2& other) {
        return Matrix2x2(a - other.a, b - other.b, c - other.c, d - other.d);
    }

    Matrix2x2 operator*(const Matrix2x2& other) {
        return Matrix2x2(
            a * other.a + b * other.c,
            a * other.b + b * other.d,
            c * other.a + d * other.c,
            c * other.b + d * other.d
        );
    }

    friend int determinant(const Matrix2x2& m) {
        return m.a * m.d - m.b * m.c;
    }

    friend class MatrixHelper;

    friend ostream& operator<<(ostream& out, const Matrix2x2& m) {
        out << m.a << " " << m.b << endl;
        out << m.c << " " << m.d << endl;
        return out;
    }
};

void MatrixHelper::updateElement(Matrix2x2& m, int row, int col, int value) {
    if (row == 0 && col == 0) m.a = value;
    else if (row == 0 && col == 1) m.b = value;
    else if (row == 1 && col == 0) m.c = value;
    else if (row == 1 && col == 1) m.d = value;
}

int main() {
    Matrix2x2 m1(1, 2, 3, 4), m2(5, 6, 7, 8);

    cout << "Matrix 1:\n" << m1;
    cout << "Matrix 2:\n" << m2;

    Matrix2x2 sum = m1 + m2;
    Matrix2x2 diff = m1 - m2;
    Matrix2x2 prod = m1 * m2;

    cout << "\nSum:\n" << sum;
    cout << "\nDifference:\n" << diff;
    cout << "\nProduct:\n" << prod;

    cout << "\nDeterminant of Matrix 1: " << determinant(m1) << endl;

    MatrixHelper helper;
    helper.updateElement(m1, 0, 1, 9);
    cout << "\nMatrix 1 after updating element (0,1) to 9:\n" << m1;

    return 0;
}
