#ifndef SHAPE_H
#define SHAPE_H
#include <cmath>
#include <iostream>
#include <string>

class Shape {
public:
	virtual void Scale(float scaleFactor) = 0;
	virtual void ShowInfo() = 0;
	virtual std::string GetName() = 0;
};

#endif
