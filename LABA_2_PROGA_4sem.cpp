#include <iostream>
#include <iomanip>
#include <cstdlib>

class Matrix {
private:
    int** data;
    unsigned int m;
    unsigned int n;

public:
    Matrix(unsigned int rows, unsigned int cols) : m(rows), n(cols) {
        data = new int* [m];
        for (unsigned int i = 0; i < m; ++i) {
            data[i] = new int[n];
        }
    }

    ~Matrix() {
        for (unsigned int i = 0; i < m; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    int* operator[](unsigned int index) {
        return data[index];
    }

    void fillRandomValues() {
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] = rand() % 10;
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (unsigned int i = 0; i < matrix.m; ++i) {
            for (unsigned int j = 0; j < matrix.n; ++j) {
                os << std::setw(2) << matrix.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    Matrix& operator+=(const Matrix& other) {
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }

    Matrix operator+(const Matrix& other) const {
        Matrix result(m, n);
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix& operator-=(const Matrix& other) {
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] -= other.data[i][j];
            }
        }
        return *this;
    }

    Matrix operator-(const Matrix& other) const {
        Matrix result(m, n);
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result(m, other.n);
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < other.n; ++j) {
                result.data[i][j] = 0;
                for (unsigned int k = 0; k < n; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    bool operator==(const Matrix& other) const {
        if (m != other.m || n != other.n) {
            return false;
        }
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                if (data[i][j] != other.data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool operator!=(const Matrix& other) const {
        return !(*this == other);
    }
};

int main() {
    srand(time(nullptr));

    Matrix matrix1(2, 3);
    matrix1.fillRandomValues();
    std::cout << "Matrix 1:" << std::endl << matrix1 << std::endl;

    Matrix matrix2(2, 3);
    matrix2.fillRandomValues();
    std::cout << "Matrix 2:" << std::endl << matrix2 << std::endl;

    Matrix sum = matrix1 + matrix2;
    std::cout << "Sum of matrices:" << std::endl << sum << std::endl;

    Matrix difference = matrix1 - matrix2;
    std::cout << "Difference of matrices:" << std::endl << difference << std::endl;

    Matrix product = matrix1 * matrix2;
    std::cout << "Product of matrices:" << std::endl << product << std::endl;

    if (matrix1 == matrix2) {
        std::cout << "Matrix 1 is equal to Matrix 2" << std::endl;
    }
    else {
        std::cout << "Matrix 1 is not equal to Matrix 2" << std::endl;
    }

    return 0;
}