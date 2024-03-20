#include "Vector.h"
#include <iostream>

template <typename T>
Vector<T>::Vector(unsigned int size) : Matrix<T>(size, 1) {
    // Конструктор, который инициализирует вектор как матрицу размером size x 1
}

template <typename T>
T Vector<T>::dotProduct(const Vector<T>& other) const {
    T result = 0;
    for (unsigned int i = 0; i < this->m; ++i) {
        result += (*this)[i][0] * other[i][0];
    }
    return result;
}

template <typename T>
T Vector<T>::scalarProduct(const Vector& other) const {
    // Предполагается, что векторы имеют одинаковую длину
    return this->dotProduct(other);
}