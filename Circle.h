#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape2D.h"

class Circle : public Shape2D {
private:
    float radius;

public:
    Circle(float radius) : radius(radius) {}

    void CalculateArea() override { SetArea(3.14159f * pow(radius, 2)); }

    void Scale(float scaleFactor) override {
        radius *= scaleFactor;
        CalculateArea();
    }

    void ShowInfo() override {
        std::cout << "Circle with radius " << radius << " has area " << GetArea()
            << std::endl;
    }

    std::string GetName() override { return "Circle"; }
};

#endif
