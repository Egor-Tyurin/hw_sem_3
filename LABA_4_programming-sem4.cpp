#include <iostream>
#include "Matrix.h"
#include "Vector.h"
#include "Second_maximum_index.h" // Добавлено

int main() {
    // Создание и заполнение матрицы
    Matrix<int> mat1(2, 2);
    mat1.fillRandom();
    std::cout << "Matrix 1:\n" << mat1 << std::endl;

    // Создание и заполнение вектора
    Vector<int> vec1(3);
    vec1.fillRandom();
    std::cout << "Vector 1:\n" << vec1 << std::endl;

    // Пример векторного и скалярного произведения
    std::cout << "Dot product: " << vec1.dotProduct(vec1) << std::endl;
    std::cout << "Scalar product: " << vec1.scalarProduct(vec1) << std::endl;

    // Проверка функции findSecondMaxIndex
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int secondMaxIndex = findSecondMaxIndex(arr, size);
    std::cout << "Second max index in array: " << secondMaxIndex << std::endl;

    return 0;
}