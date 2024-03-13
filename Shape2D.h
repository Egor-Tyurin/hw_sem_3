#ifndef SHAPE2D_H
#define SHAPE2D_H
#include "Shape.h"

class Shape2D : public Shape {
private:
    float area = 0;
    void virtual CalculateArea() = 0;

public:
    Shape2D() {}

    float GetArea() { return area; };
    void SetArea(float a) {
        if (a > 0) {
            area = a;
        }
        else {
            throw std::runtime_error("ERROR 300");
        }
    }
    bool operator>(const Shape2D& other) { return area > other.area; };
    bool operator<(const Shape2D& other) { return area < other.area; };
    bool operator==(const Shape2D& other) { return area == other.area; };
};

#endif 
