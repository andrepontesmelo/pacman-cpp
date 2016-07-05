#ifndef CORNER_H
#define CORNER_H

#include "FixedDirection.h"
#include "Position.h"
#include "NullArgumentException.h"
#include "Params.h"
#include "Random.h"

#include <iostream>
class Corner
{
private:
	Corner * corners[4];
	bool wallkables[4];
	Position * position;
	void Initilize();

public:
	Corner(int row, int column);

	Corner * GetCorner(int pos) { 	return corners[pos]; }
	
	FixedDirection* DirectionToAnyCorner();
	
	void SetCorner(int pos, Corner * neibor, bool wallkable);

	Position * GetPosition() { return position; }
};

#endif
