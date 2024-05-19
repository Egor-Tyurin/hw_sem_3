#include <iostream>
#include <vector>
#include <list>
#include <chrono>

int main() {
    const int size = 10000;

    // ������������� ������� � ������
    std::vector<int> vec;
    std::list<int> lst;


   // ������ ���������� ������
    std::cout << "Size of vector: " << sizeof(vec) << " bytes" << std::endl;
    std::cout << "Size of list: " << sizeof(lst) << " bytes" << std::endl;

    // ���������� �������
    for (int i = 0; i < size; ++i) {
        vec.push_back(i);
    }

    // ���������� ������
    for (int i = 0; i < size; ++i) {
        lst.push_back(i);
    }

    // ��������� ������� ������� � ��������� �������
    auto start_vec = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; ++i) {
        int temp = vec[i];
    }
    auto end_vec = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_vec = end_vec - start_vec;
    std::cout << "Time taken for vector: " << duration_vec.count() << " seconds\n";

    // ��������� ������� ������� � ��������� ������
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