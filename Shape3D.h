#ifndef SHAPE3D_H
#define SHAPE3D_H

#include "Shape.h"

class Shape3D : public Shape {
private:
    float volume = 0;
    void virtual CalculateVolume() = 0;

public:
    Shape3D() { }

    float GetVolume() { return volume; };
    void SetVolume(float v) {
        if (v > 0) {
            volume = v;
        }
        else {
            throw std::runtime_error("ERROR 300");
        }
    }
    bool operator>(const Shape3D& other) { return volume > other.volume; };
    bool operator<(const Shape3D& other) { return volume < other.volume; };
    bool operator==(const Shape3D& other) { return volume == other.volume; };
};

#endif