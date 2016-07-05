#ifndef GREEDY_GHOST_H
#define GREEDY_GHOST_H

#include "Ghost.h"
#include "Position.h"
#include "FixedDirection.h"
#include "GreedyFollower.h"
#include "IDrawable.h"

class GreedyGhost : public Ghost
{
	protected:
		FixedDirection * NextDirection();

	public:
		GreedyGhost(int jail_time, Position * pos_pacman);

	private:
		GreedyFollower * pacman_follower;
		static int ghosts_created;
		static string GetAlternatedName();
};

#endif
