#ifndef GREEDY_FOLLOWER_H
#define GREEDY_FOLLOWER_H

#include "WalkingElement.h"
#include "Corner.h"
#include "FixedDirection.h"
#include "Random.h"
#include "Approximator.h"

class GreedyFollower : public Approximator
{
	
public:
	GreedyFollower(Position * target, WalkingElement *follower);
	virtual FixedDirection * FollowingDirection();
	
};

#endif
