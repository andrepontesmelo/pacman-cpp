#ifndef BOX_H
#define BOX_H
#include "Position.h"

class Box
{
public:
	Box(int pos_top_corner_x, int pos_top_corner_y,
		int pos_right_bottom_x, int pos_right_bottom_y);

	Position * Pos1() { return pos1; }
	Position * Pos2() { return pos2; }

	Position * Pos_top_corner() { return pos1; }
	Position * Pos_right_bottom() { return pos2; }

	Position * GetCenterPosition();

private:
	Position * pos1, * pos2, * pos_center;
	Position * CreateCenterPosition();
};

#endif
