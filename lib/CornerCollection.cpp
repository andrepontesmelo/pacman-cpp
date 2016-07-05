#include "CornerCollection.h"

Corner * CornerCollection::GetAbove(Corner* corner)
{
	Corner * closet_corner = 0;
	int smallest_distance = SCREEN_WIDTH; 
	Position * corner_pos = corner->GetPosition();

	std::vector<Corner*>::iterator iterador = vector.begin();
	
	for (; iterador < vector.end(); iterador++)
	{
		Corner * c = (*iterador);
		Position * c_pos = c->GetPosition();		

		int dist = corner_pos->Distance(c_pos);

		if ((dist != 0) && (dist < smallest_distance) && (corner_pos->SameColumn(c_pos)))
		{
			smallest_distance = dist;
			closet_corner = c;
		}
	}

	return closet_corner; 
}

void CornerCollection::RegisterCorner(Corner *corner, Corner *left_corner, Corner * top_corner)
{
#ifdef DEBUG
	if (corner == 0)
		throw new NullArgumentException("corner", "CornerCollection::RegisterCorner(...)");
#endif

	Add(corner);

	if (left_corner != 0)
	{
		left_corner->SetCorner(FixedDirection::Right()->GetCode(), corner, true);
		corner->SetCorner(FixedDirection::Left()->GetCode(), left_corner, true);
	}

	if (top_corner != 0)
	{
		top_corner->SetCorner(FixedDirection::Bottom()->GetCode(), corner, true);
		corner->SetCorner(FixedDirection::Top()->GetCode(), top_corner, true);
	}
}
