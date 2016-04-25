#include "GreedyGhost.h"

int GreedyGhost::ghosts_created = 0;

string GreedyGhost::GetAlternatedName()
{
	ghosts_created++;

	if (ghosts_created%2)
		return "img/g_red.bmp";
	else 
		return "img/g_blue.bmp";
}

GreedyGhost::GreedyGhost(int jail_time, Position * pos_pacman) : Ghost(jail_time)
{
	pacman_follower = new GreedyFollower(pos_pacman, this);

	regular_drawing = new Bitmap(GetAlternatedName());
	regular_drawing->SetPosition(Maze::Instance()->GetInitialGhostCorner()->GetPosition()->X(), 
		Maze::Instance()->GetInitialGhostCorner()->GetPosition()->Y());

	regular_drawing->SetCentered(true);

	drawing = regular_drawing;
}

FixedDirection * GreedyGhost::NextDirection()
{
	if (action == RETURNING)
	{
		return jail_follower->FollowingDirection();
	} else
	{
		if (pill_effect)	
	 		return pacman_follower->DirectionAway();
		else
			return pacman_follower->FollowingDirection();
	}
}
