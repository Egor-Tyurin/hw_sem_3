#ifndef TRIANGLEPYRAMID_H
#define TRIANGLEPYRAMID_H

#include "Shape3D.h"
#include "Triangle.h"

class TriangularPyramid : public Shape3D {
private:
    Triangle baseTriangle;
    float height;

public:
    TriangularPyramid(float base, float height)
        : baseTriangle(base, height), height(height) {
        CalculateVolume();
    }

    void CalculateVolume() override {
        baseTriangle.CalculateArea();
        SetVolume((1.0f / 3.0f) * baseTriangle.GetArea() * height);
    }

    void Scale(float scaleFactor) override {
        baseTriangle.Scale(scaleFactor);
        height *= scaleFactor;
        CalculateVolume();
    }

    void ShowInfo() override {
        std::cout << "Triangular Pyramid with base " << baseTriangle.GetArea()
            << " and height " << height << " has volume " << GetVolume()
            << std::endl;
    }

    std::string GetName() override { return "Triangular Pyramid"; }
};

#endif