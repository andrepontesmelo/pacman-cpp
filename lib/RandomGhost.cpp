#include "RandomGhost.h"

int RandomGhost::ghosts_created = 0;

string RandomGhost::GetAlternatedName()
{
	ghosts_created++;

	if (ghosts_created%2)
		return "../img/g_orange.bmp";
	else 
		return "../img/g_beige.bmp";
}

RandomGhost::RandomGhost(int jail_time) : Ghost(jail_time)
{
	regular_drawing = new Bitmap(GetAlternatedName());
	regular_drawing->SetPosition(Maze::Instance()->GetInitialGhostCorner()->GetPosition()->X(), 
		Maze::Instance()->GetInitialGhostCorner()->GetPosition()->Y());

	regular_drawing->SetCentered(true);

	drawing = regular_drawing;
}

FixedDirection* RandomGhost::NextDirection()
{
	return next_corner->DirectionToAnyCorner();
}
