#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
#define EPSILON pow(10, -5)
#define GRV pow(6.6743, pow(10, -11))

using namespace std;

double Iterations_Type(double n, double e, double M) { // Метод итераций
    double Ek1;
    double Ek = M;
    for (int i = 0; i < 70; i++) {
        Ek1 = e * sin(Ek) + M;
        if (abs(Ek1 - Ek) < EPSILON)
            return Ek1;
        Ek = Ek1;
    }
    return 0;
}

double Half_Division_Type(double e, double M) { // Метод половинного деления
    double A = M - 2; // Левая граница рассматриваемого интервала
    double B = M + 2; // Правая граница рассматриваемого интервала
    double C; // Новая граница

    if (((A - e * sin(A) - M) * (B - e * sin(B) - M)) < 0) {
        for (int i = 0; i < 70; i++) {
            C = (A + B) / 2;
            if (abs(C - e * sin(C) - M) < EPSILON)
                return C;
            if (((A - e * sin(A) - M) * (C - e * sin(C) - M)) < 0)
                B = C;
            else
                A = C;
        }
    }
    return 0;
}

double Golden_Ratio_Type(double e, double M) { // Метод золотого сечения
    double A = M - 2; // Левая граница рассматриваемого интервала
    double B = M + 2; // Правая граница рассматриваемого интервала
    double C; // Новая граница

    if (((A - e * sin(A) - M) * (B - e * sin(B) - M)) < 0) {
        for (int i = 0; i < 70; i++) {
            C = A + ((B - A) / ((sqrt(5) + 1) / 2));
            if (abs(C - e * sin(C) - M) < EPSILON)
                return C;
            if (((A - e * sin(A) - M) * (C - e * sin(C) - M)) < 0)
                B = C;
            else
                A = C;
        }
    }
    return 0;
}


double Newton_Type(double e, double M) { // Метод Ньютона(Метод касательных)
    double Ek = M;
    double Ek1 = M;
    double F;
    double F1;
    double tE;
    double tE1;

    for (int i = 0; i < 100; i++) {
        if (i == 0)
            Ek1 = Ek - ((Ek - e * sin(Ek) - M) / (1 - e * cos(Ek)));
        else
            Ek1 = Ek - ((Ek - e * sin(Ek) - M) / ((F1 - F) / (tE1 - tE)));
        if (abs(Ek1 - Ek) < EPSILON)
            return Ek1;

        F = Ek - e * sin(Ek) - M;
        F1 = Ek1 - e * sin(Ek1) - M;
        tE = Ek;
        tE1 = Ek1;

        Ek = Ek1;
    }
    return 0;
}


int main() {
    double Ra = 10749; // Радиус Апоцентра
    double Rp = 275; // Радиус Перицентра
    double a = (Rp + Ra) / 2; // Большая полуось орбиты
    double e = (Ra - Rp) / (2 * a); // Эксцентриситет орбиты
    double n = sqrt(GRV / pow(a, 3)); // Угловая скорость 
    double T = 7.08 * 3600; // Период обращения , с
    ofstream out1;
    ofstream out2;
    ofstream out3;
    ofstream out4;
    out1.open("C:/Users/admin/Desktop/Результаты мкп лаба 1/мкп1.txt");
    out2.open("C:/Users/admin/Desktop/Результаты мкп лаба 1/мкп2.txt");
    out3.open("C:/Users/admin/Desktop/Результаты мкп лаба 1/мкп3.txt");
    out4.open("C:/Users/admin/Desktop/Результаты мкп лаба 1/мкп4.txt");
    for (int t = 0; t <= T; t++) {
        double M = n * t;
        if (out1.is_open() and out2.is_open() and out3.is_open() and out4.is_open())
            out1 << Iterations_Type(n, e, M) << endl;
        out2 << Half_Division_Type(e, M) << endl;
        out3 << Golden_Ratio_Type(e, M) << endl;
        out4 << Newton_Type(e, M) << endl;
    }
    out1.close();
    out2.close();
    out3.close();
    out4.close();
    return 0;
}