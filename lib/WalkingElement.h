#ifndef WALKING_ELEMENT_H
#define WALKING_ELEMENT_H

#include "FixedDirection.h"
#include "DrawingElement.h"
#include "Corner.h"
#include "Maze.h"
#include "Params.h"

class WalkingElement : public DrawingElement
{

public:
WalkingElement();
WalkingElement(FixedDirection * direction);
virtual ~WalkingElement() {
}
virtual void UpdatePosition(int elapsed_ms);
virtual void Draw();
Corner* NextCorner() {
								return next_corner;
}

protected:
FixedDirection *direction;
bool stopped;
Corner* next_corner;
int acc_time;
virtual int Interval() = 0;
virtual FixedDirection* NextDirection() = 0;
virtual void Flip() {
};

private:
void Initilize();
void FindNextCorner();
};

#endif
