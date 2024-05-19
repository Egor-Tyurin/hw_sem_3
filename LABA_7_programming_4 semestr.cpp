#include <iostream>
#include <vector>
#include <list>
#include <chrono>

int main() {
    const int size = 10000;

    // Инициализация вектора и списка
    std::vector<int> vec;
    std::list<int> lst;


   // Расчет занимаемой памяти
    std::cout << "Size of vector: " << sizeof(vec) << " bytes" << std::endl;
    std::cout << "Size of list: " << sizeof(lst) << " bytes" << std::endl;

    // Заполнение вектора
    for (int i = 0; i < size; ++i) {
        vec.push_back(i);
    }

    // Заполнение списка
    for (int i = 0; i < size; ++i) {
        lst.push_back(i);
    }

    // Измерение времени доступа к элементам вектора
    auto start_vec = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; ++i) {
        int temp = vec[i];
    }
    auto end_vec = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_vec = end_vec - start_vec;
    std::cout << "Time taken for vector: " << duration_vec.count() << " seconds\n";

    // Измерение времени доступа к элементам списка
    auto start_lst = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; ++i) {
        for (auto it = lst.begin(); it != lst.end(); ++it) {
            int temp = *it;
        }
    }
    auto end_lst = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_lst = end_lst - start_lst;
    std::cout << "Time taken for list: " << duration_lst.count() << " seconds\n";

    return 0;
}