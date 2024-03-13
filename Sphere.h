#ifndef SPHERE_H
#define SPHERE_H
#include "Shape3D.h"

class Sphere : public Shape3D {
private:
    float radius;

public:
    Sphere(float radius) : radius(radius) {}

    void CalculateVolume() override {

        SetVolume((4 * 3.14159f * pow(radius, 3)) / 3);
    }
    void Scale(float scaleFactor) override {
        radius *= scaleFactor;
        CalculateVolume();
    }

    void ShowInfo() override {
        std::cout << "Sphere with radius " << radius << " has volume "
            << GetVolume() << std::endl;
    }

    std::string GetName() override { return "Sphere"; }
};

#endif