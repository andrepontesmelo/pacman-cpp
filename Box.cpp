#include "Box.h"

Box::Box(int pos_top_corner_x, int pos_top_corner_y,
	int pos_right_bottom_x, int pos_right_bottom_y)
{
	pos1 = new Position(pos_top_corner_x, pos_top_corner_y);
	pos2 = new Position(pos_right_bottom_x, pos_right_bottom_y);

	pos_center = 0;
}

Position* Box::GetCenterPosition()
{
	if (pos_center == 0)
		pos_center = CreateCenterPosition();

	return pos_center;
}

Position* Box::CreateCenterPosition()
{
	return new Position((pos2->X() + pos1->X()) / 2, (pos2->Y() + pos1->Y()) / 2);
}
