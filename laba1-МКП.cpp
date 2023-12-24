#include <iostream>
#include <cmath>
#include <fstream>
#define EPSILON pow(10, -5)
#define GRV pow(6.6743, pow(10, -20)) // Гравитационная постоянная , км**3/(с**2 * кг)
#define PI 3.1415926535897932384626433832795

using namespace std;

double Iterations_Type(double n, double e, double M) {
    double E1, E = M;
    for (int i = 0; i < 100; i++) {
        E1 = e * sin(E) + M;
        if (abs(E1 - E) < EPSILON)
            return E1;
        E = E1;
    }
    return 0;
}

double Half_Division_Type(double e, double M) {
    double A = M - 2;
    double B = M + 2;
    double C;

    if (((A - e * sin(A) - M) * (B - e * sin(B) - M)) < 0) {
        for (int i = 0; i < 100; i++) {
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

double Golden_Ratio_Type(double e, double M) {
    double A = M - 2;
    double B = M + 2;
    double C;

    if (((A - e * sin(A) - M) * (B - e * sin(B) - M)) < 0) {
        for (int i = 0; i < 200; i++) {
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

double Newton_Type(double e, double M) {
    double E = M;
    double E1 = M;
    double F;
    double F1;
    double tE;
    double tE1;

    for (int i = 0; i < 100; i++) {
        if (i == 0)
            E1 = E - ((E - e * sin(E) - M) / (1 - e * cos(E)));
        else
            E1 = E - ((E - e * sin(E) - M) / ((F1 - F) / (tE1 - tE)));
        if (abs(E1 - E) < EPSILON)
            return E1;

        F = E - e * sin(E) - M;
        F1 = E1 - e * sin(E1) - M;
        tE = E;
        tE1 = E1;

        E = E1;
    }
    return 0;
}


int main() {
    double Ra = 14138.5; // Радиус Апоцентра
    double Rp = 3664.5; // Радиус Перицентра
    double a = (Rp + Ra) / 2; // Большая полуось орбиты
    double e = (Ra - Rp) / (2 * a); // Эксцентриситет орбиты
    double Massa = 0.642 * pow(10, 24); // Масса Марса , кг
    double mu = 42828; //Гравитационный параметр Марса
    double n = sqrt(mu / pow(a, 3)); // Угловая скорость 
    double T_double = (2 * PI) / n;
    int T = static_cast<int>(T_double); //переводим период из double в int


    ofstream out1;
    ofstream out2;
    ofstream out3;
    ofstream out4;
    ofstream out5;
    ofstream out6;
    out1.open("C:/Users/admin/Desktop/projects/hw_sem_3/LABA-1МКП/Результаты мкп лаба 1/мкп1.txt");
    out2.open("C:/Users/admin/Desktop/projects/hw_sem_3/LABA-1МКП/Результаты мкп лаба 1/мкп2.txt");
    out3.open("C:/Users/admin/Desktop/projects/hw_sem_3/LABA-1МКП/Результаты мкп лаба 1/мкп3.txt");
    out4.open("C:/Users/admin/Desktop/projects/hw_sem_3/LABA-1МКП/Результаты мкп лаба 1/мкп4.txt");
    out5.open("C:/Users/admin/Desktop/projects/hw_sem_3/LABA-1МКП/Результаты мкп лаба 1/мкп5.txt");
    out6.open("C:/Users/admin/Desktop/projects/hw_sem_3/LABA-1МКП/Результаты мкп лаба 1/мкп6.txt");
    for (int t = 0; t <= T; t++) {
        double M = n * t;
        double E = Newton_Type(e, M);
        double teta = atan(sqrt(((1 - e) / (1 + e))) * tan(E / 2)) * 2;
        if (teta < 0)
            teta += 2 * PI;
        out1 << Iterations_Type(n, e, M) << endl;
        out2 << Half_Division_Type(e, M) << endl;
        out3 << Golden_Ratio_Type(e, M) << endl;
        out4 << Newton_Type(e, M) << endl;
        out5 << M << endl;
        out6 << teta << endl;

    }
    out1.close();
    out2.close();
    out3.close();
    out4.close();
    out5.close();
    out6.close();
    return 0;
}
