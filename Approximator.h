#ifndef APROXIMADOR_H
#define APROXIMADOR_H
#include "Position.h"
#include "FixedDirection.h"
#include "WalkingElement.h"

class Approximator
{
protected:
	Approximator(Position *target, WalkingElement *follower);		
	bool CheckNextDirection(FixedDirection * d);
	WalkingElement * follower;
	Position * target;

public:
	Position * GetTargetPosition() { return target; }
	virtual FixedDirection * FollowingDirection() = 0;
	FixedDirection * DirectionAway();
	virtual ~Approximator() {}
};	
#endif
