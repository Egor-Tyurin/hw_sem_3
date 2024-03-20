#ifndef VECTOR_H
#define VECTOR_H

#include "Matrix.h"

template <typename T>
class Vector : public Matrix<T> {
public:
    Vector(unsigned int size);

    T dotProduct(const Vector& other) const;
    T scalarProduct(const Vector& other) const;
};

#include "Vector.tpp"

#endif // VECTOR_H