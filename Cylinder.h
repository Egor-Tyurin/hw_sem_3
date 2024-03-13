#ifndef CYLINDER_H
#define CYLINDER_H
#include "Shape3D.h"
#include "Circle.h"

class Cylinder : public Shape3D {
private:
    Circle baseCircle;
    float height;

public:
    Cylinder(float radius, float height) : baseCircle(radius), height(height) {}

    void CalculateVolume() override {
        baseCircle.CalculateArea();
        SetVolume(baseCircle.GetArea() * height);
    }

    void Scale(float scaleFactor) override {
        baseCircle.Scale(scaleFactor);
        height *= scaleFactor;
        CalculateVolume();
    }

    void ShowInfo() override {
        std::cout << "Cylinder with radius " << baseCircle.GetArea()
            << " and height " << height << " has volume " << GetVolume()
            << std::endl;
    }

    std::string GetName() override { return "Cylinder"; }
};

#endif