#include <iostream>
#include "Square.h"
#include "Triangle.h"
#include "TrianglePyramid.h"
#include "Circle.h"
#include "Cylinder.h"
#include "Sphere.h"

void TestSquare() {
    Square square(5);
    square.ShowInfo();
    square.Scale(2);
    square.ShowInfo();
}

void TestTriangle() {
    Triangle triangle(5, 10);
    triangle.ShowInfo();
    triangle.Scale(2);
    triangle.ShowInfo();
}

void TestTrianglePyramid() {
    TriangularPyramid pyramid(5, 10);
    pyramid.ShowInfo();
    pyramid.Scale(2);
    pyramid.ShowInfo();
}

void TestCircle() {
    Circle circle(5);
    circle.ShowInfo();
    circle.Scale(2);
    circle.ShowInfo();
}

void TestCylinder() {
    Cylinder cylinder(5, 10);
    cylinder.ShowInfo();
    cylinder.Scale(2);
    cylinder.ShowInfo();

}
void TestSphere() {
    Sphere sphere(5);
    sphere.ShowInfo();
    sphere.Scale(2);
    sphere.ShowInfo();
}

int main() {

    TestSquare();

    TestTriangle();

    TestTrianglePyramid();

    TestCircle();

    TestCylinder();

    TestSphere();

    return 0;
}