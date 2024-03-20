#include "Matrix.h"
#include <iostream>

template <typename T>
Matrix<T>::Matrix(unsigned int m, unsigned int n) : m(m), n(n) {
    data = new T*[m];
    for (unsigned int i = 0; i < m; i++) {
        data[i] = new T[n];
    }
}

template <typename T>
Matrix<T>::~Matrix() {
    for (unsigned int i = 0; i < m; i++) {
        delete[] data[i];
    }
    delete[] data;
}

template <typename T>
T* Matrix<T>::operator[](int i) const {
    return data[i];
}


template <typename T>
void Matrix<T>::fillRandom() {
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            data[i][j] = rand() % 10;
        }
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix) {
    for (unsigned int i = 0; i < matrix.m; i++) {
        for (unsigned int j = 0; j < matrix.n; j++) {
            out << matrix.data[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& matrix) {
    if (m != matrix.m || n != matrix.n) {
        std::cerr << "Matrices must have the same dimensions" << std::endl;
        return *this;
    }
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            data[i][j] += matrix.data[i][j];
        }
    }
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& matrix) const {
    Matrix<T> result(m, n);
    result = *this;
    result += matrix;
    return result;
}

template <typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& matrix) {
    if (m != matrix.m || n != matrix.n) {
        std::cerr << "Matrices must have the same dimensions" << std::endl;
        return *this;
    }
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            data[i][j] -= matrix.data[i][j];
        }
    }
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& matrix) const {
    Matrix<T> result(m, n);
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            result.data[i][j] = data[i][j] - matrix.data[i][j];
        }
    }
    return result;
}

template <typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& matrix) {
    if (n != matrix.m) {
        std::cerr << "Matrices must have compatible dimensions for multiplication" << std::endl;
        return *this;
    }
    Matrix<T> result(m, matrix.n);
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < matrix.n; j++) {
            result.data[i][j] = 0;
            for (unsigned int k = 0; k < n; k++) {
                result.data[i][j] += data[i][k] * matrix.data[k][j];
            }
        }
    }
    *this = result;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& matrix) const {
    if (n != matrix.m) {
        std::cerr << "Matrices must have compatible dimensions for multiplication" << std::endl;
        return Matrix<T>(0, 0);
    }
    Matrix<T> result(m, matrix.n);
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < matrix.n; j++) {
            result.data[i][j] = 0;
            for (unsigned int k = 0; k < n; k++) {
                result.data[i][j] += data[i][k] * matrix.data[k][j];
            }
        }
    }
    return result;
}

template <typename T>
bool Matrix<T>::operator!=(const Matrix<T>& matrix) const {
    if (m != matrix.m || n != matrix.n) {
        return true;
    }
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            if (data[i][j] != matrix.data[i][j]) {
                return true;
            }
        }
    }
    return false;
}

template <typename T>
bool Matrix<T>::operator==(const Matrix<T>& matrix) const {
    return !(*this != matrix);
}