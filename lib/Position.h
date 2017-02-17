
#ifndef POSITION_H
#define POSITION_H

#include "FixedDirection.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

class Position
{
private:
int x, y;
public:
Position();
Position(int x, int y);
int X();
int Y();
void SetX(int x_) {
								x = x_;
}
void SetY(int y_) {
								y = y_;
}
int Distance(Position *b);
int HorizontalDistance(Position *b);
int VerticalDistance(Position *b);
static int Distance(Position *a, Position *b);
string String();

bool SameRow(Position *b) {
								return (y == b->Y());
}
bool SameColumn(Position *b) {
								return (x == b->X());
}
bool RightOf(Position *b) {
								return x > b->X();
}
bool Below(Position *b)   {
								return y > b->Y();
}
bool Above(Position *b) {
								return !Below(b);
}
bool LeftOf(Position *b) {
								return !RightOf(b);
}
bool GreaterThan(Position *b, FixedDirection *d);
bool LessThan(Position *b, FixedDirection *d) {
								return !GreaterThan(b, d);
}
};

#endif
