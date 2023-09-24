/*
1) int *ptr = new int;
2) int *ptrArr = new int[N];
3) delete ptr;
4) delete[] ptrArr

В С++ необходимо освобождать динамическую память с помощью операторов delete и delete[]. 
Освобождать одну и ту же выделенную память дважды нельзя, это может привести к ошибкам выполнения программы. 
Освобождать невыделенную память также нельзя. */




#include <iostream>
using namespace std;




int main() {
    int rows;
    cout << "Введите количество строк треугольника Фибоначчи: " << endl;
    cin >> rows;

    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[i + 1];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == 0 || j == 0 || j == i) 
            {
                arr[i][j] = 1;
            } 
            else 
            {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }
            
            cout << arr[i][j] << " " ;
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}