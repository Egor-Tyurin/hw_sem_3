#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

template <typename T>
class Matrix {
protected:
    T** data;
    unsigned int m;
    unsigned int n;

public:
    Matrix(unsigned int m, unsigned int n);
    ~Matrix();

    T* operator[](int i) const;

    void fillRandom();

    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const Matrix<U>& matrix);

    Matrix& operator+=(const Matrix& matrix);
    Matrix operator+(const Matrix& matrix) const;
    Matrix& operator-=(const Matrix& matrix);
    Matrix operator-(const Matrix& matrix) const;
    Matrix& operator*=(const Matrix& matrix);
    Matrix operator*(const Matrix& matrix) const;

    bool operator!=(const Matrix& matrix) const;
    bool operator==(const Matrix& matrix) const;
};



#include "Matrix.tpp"

#endif  MATRIX_H