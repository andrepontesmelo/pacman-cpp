#include "Position.h"

string Position::String()
{
								stringstream result;
								result << "(x = " << x << "; y = " << y << ") ";

								return result.str();
}

int Position::X()
{
								return x;
}

int Position::Y()
{
								return y;
}

Position::Position()
{
								x = 0;
								y = 0;
}

Position::Position(int x, int y)
{
								this->x = x;
								this->y = y;
}

int Position::Distance(Position * b)
{
								return HorizontalDistance(b) + VerticalDistance(b);
}

int Position::HorizontalDistance(Position *b)
{
								return abs(b->X() - x);
}

int Position::VerticalDistance(Position *b)
{
								return abs(b->Y() - y);
}

bool Position::GreaterThan(Position *b, FixedDirection *d)
{
								return (x - b->X()) * d->X() +  (y - b->Y()) * d->Y() > 0 ? true : false;
}
