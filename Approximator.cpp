#include "Approximator.h"

Approximator::Approximator(Position * target, WalkingElement * follower) 
{
	this->target = target;
	this->follower = follower;
}


bool Approximator::CheckNextDirection(FixedDirection * d)
{
	return target->GreaterThan(follower->GetPosition(), d)	&& 
	(follower->NextCorner()->GetCorner(d->GetCode()) != 0);
}

FixedDirection * Approximator::DirectionAway()
{
	FixedDirection * approximity = FollowingDirection();
	FixedDirection * opposit = approximity->Opposit();
	
	if (follower->NextCorner()->GetCorner(opposit->GetCode()) != 0)
		return opposit;
	else
		return follower->NextCorner()->DirectionToAnyCorner();
	
}
