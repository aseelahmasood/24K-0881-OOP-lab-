#include <iostream>
#include <exception>
#include <vector>
using namespace std;

class DimensionMismatchException : public exception {
    string msg;
public:
    DimensionMismatchException(int r1, int c1, int r2, int c2) {
        msg = "DimensionMismatchException: (" + to_string(r1) + "x" + to_string(c1) +
              " vs " + to_string(r2) + "x" + to_string(c2) + ")";
    }
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

template<typename T>
class Matrix {
    vector<vector<T>> data;
    int rows, cols;

public:
    Matrix(int r, int c, T val = T()) : rows(r), cols(c) {
        data.resize(r, vector<T>(c, val));
    }

    void set(int r, int c, T val) {
        data[r][c] = val;
    }

    Matrix<T> operator+(const Matrix<T>& other) {
        if (rows != other.rows || cols != other.cols)
            throw DimensionMismatchException(rows, cols, other.rows, other.cols);

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] + other.data[i][j];

        return result;
    }
};

int main() {
    try {
        Matrix<int> a(2, 2, 1);
        Matrix<int> b(3, 3, 2);
        Matrix<int> c = a + b;
    } catch (const exception& e) {
        cout << "Caught: " << e.what() << endl;
    }
    return 0;
}
