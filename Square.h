#ifndef SQUARE_H
#define SQUARE_H

#include "Shape2D.h"

class Square : public Shape2D {
private:
    float side;

public:
    Square(float side) : side(side) { CalculateArea(); }

    void CalculateArea() override { SetArea(side * side); }

    void Scale(float scaleFactor) override {
        side *= scaleFactor;
        CalculateArea();
    }

    void ShowInfo() override {
        std::cout << "Square with side " << side << " has area " << GetArea()
            << std::endl;
    }

    std::string GetName() override { return "Square"; }
};

#endif