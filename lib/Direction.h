#ifndef DIRECTION_H
#define DIRECTION_H
#include "Random.h"
#include <math.h>
#include <iostream>
#include <string>
#include <sstream>
using std::string;
using std::stringstream;
using std::cout;
class Direction
{
public:
Direction(float x, float y) {
								this->x = x; this->y = y;
}
Direction() {
}
virtual ~Direction() {
}

float X() {
								return x;
}
float Y() {
								return y;
}

virtual void SetRandomly(double min_abs);

virtual void InvertX() {
								x *= -1;
}
virtual void InvertY() {
								y *= -1;
}

string String();
static Direction* GetRandomly(double min_abs);

private:
float x, y;

public:
virtual void SetX(float x) {
								this->x = x;
}
virtual void SetY(float y) {
								this->y = y;
}
};

#endif
