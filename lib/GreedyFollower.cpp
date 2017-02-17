#include "GreedyFollower.h"

GreedyFollower::GreedyFollower(Position * target, WalkingElement * follower)
								: Approximator(target, follower)
{
}

FixedDirection * GreedyFollower::FollowingDirection()
{
								if (Random::Instance()->Generate(1) == 1)
								{
																if (CheckNextDirection(FixedDirection::Left()))
																								return FixedDirection::Left();

																if (CheckNextDirection(FixedDirection::Right()))
																								return FixedDirection::Right();

								} else
								{
																if (CheckNextDirection(FixedDirection::Top()))
																								return FixedDirection::Top();

																if (CheckNextDirection(FixedDirection::Bottom()))
																								return FixedDirection::Bottom();

																return FixedDirection::Right();

								}
								return follower->NextCorner()->DirectionToAnyCorner();
}
