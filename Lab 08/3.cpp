#include <iostream>
using namespace std;
class Vector2D {
private:
    double x, y;

public:
    Vector2D(double xVal=0,double yVal=0) {
        x=xVal;
        y =yVal;
    }

    Vector2D operator+(const Vector2D& other) {
        return Vector2D(x +other.x,y+other.y);
    }

    Vector2D operator-(const Vector2D& other) {
        return Vector2D(x -other.x,y-other.y);
    }

    Vector2D operator*(double scalar) {
        return Vector2D(x * scalar, y * scalar);
    }

    friend double dotProduct(const Vector2D& a, const Vector2D& b) {
        return a.x * b.x + a.y * b.y;
    }

    friend ostream& operator<<(ostream& out, const Vector2D& v) {
        out << "(" << v.x << ", " << v.y << ")";
        return out;
    }
};

int main() {
    Vector2D v1(3, 4), v2(1, 2);
    Vector2D sum = v1 + v2;
    Vector2D diff = v1 - v2;
    Vector2D scaled = v1 * 2;
    double dot = dotProduct(v1, v2);

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    cout << "Sum = " << sum << endl;
    cout << "Difference = " << diff << endl;
    cout << "Scaled = " << scaled << endl;
    cout << "Dot Product = " << dot << endl;

    return 0;
}
