#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

// ������� ��� ������ ����������� ������� � ������� Range-based for-loop
void printVectorRange( const vector<string>& vec) {
    for (const auto& elem : vec) {
        cout << elem << " ";
    }
    cout << endl;
}
void printVectorRange1(const vector<int>& vec) {
    for (const auto& elem : vec) {
        cout << elem << " ";
    }
    cout << endl;
}

// ������� ��� ������ ����������� ������� � ������� ���������
void printVectorIterator( vector<int>& vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

// ������� ��� ������ ����������� ������� � ������� �������� ����������� �����
void printVectorIndex(const vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

// ������� ��� ���������� �������� �������� ������
double calculateAverage(const vector<int>& grades) {
    int sum = 0;
    for (const auto& grade : grades) {
        sum += grade;
    }
    return static_cast<double>(sum) / grades.size();
}

// ������� ��� ���������� ������� ������
double calculateMedian(vector<int>& grades) {
    sort(grades.begin(), grades.end());
    int size = grades.size();
    if (size % 2 == 0) {
        return static_cast<double>(grades[size / 2 - 1] + grades[size / 2]) / 2;
    }
    else {
        return grades[size / 2];
    }
}

// ������� ��� ���������� ���� ������
vector<int> calculateMode(const vector<int>& grades) {
    unordered_map<int, int> frequency;
    for (const auto& grade : grades) {
        frequency[grade]++;
    }

    int maxFrequency = 0;
    for (const auto& pair : frequency) {
        maxFrequency = max(maxFrequency, pair.second);
    }

    vector<int> mode;
    for (const auto& pair : frequency) {
        if (pair.second == maxFrequency) {
            mode.push_back(pair.first);
        }
    }

    return mode;
}

int main() {
    setlocale(LC_ALL, "rus"); //���������� ������������� �������� ��������
    vector<string> names;
    vector<int> grades;

    int choice;
    cout << "�������� ������� ������������� ��������:" << endl;
    cout << "1. ���������������� ������ �� ��������� ������� ���������" << endl;
    cout << "2. ������ �� ��������� ������� ���������" << endl;
    cout << "3. ������ �� ������� ��������� �� ������������" << endl;
    cin >> choice;

    if (choice == 1) {
        names = { "����", "����", "�������", "�����", "�����", "�����", "������", "������", "�������", "�������" };
        grades = { 85, 72, 90, 93, 87, 78, 95, 88, 92, 80};
    }
    else if (choice == 2) {
        int size;
        cout << "������� �������� ������ �������: ";
        cin >> size;

        // ��������� ��������� ���� � ������
        // ��� �������� �������, ������ ����� ���������� ������� �� 0 �� 100
        for (int i = 0; i < size; ++i) {
            names.push_back("��� " + to_string(i));
            grades.push_back(rand() % 101);
        }
    }
    else if (choice == 3) {
        int size;
        cout << "������� ������ �������: ";
        cin >> size;

        cout << "������� ����� � ������:" << endl;
        for (int i = 0; i < size; ++i) {
            string name;
            int grade;
            cin >> name >> grade;

            names.push_back(name);
            grades.push_back(grade);
        }
    }

    cout << "���������� ������� ����:" << endl;
    printVectorRange(names);

    cout << "���������� ������� ������:" << endl;
    printVectorRange1(grades);

    cout << "������� �������� ������: " << calculateAverage(grades) << endl;

    cout << "������� ������: " << calculateMedian(grades) << endl;

    cout << "���� ������: ";
    vector<int> mode = calculateMode(grades);
    for (const auto& grade : mode) {
        cout << grade << " ";
    }
    cout << endl;

    return 0;
}