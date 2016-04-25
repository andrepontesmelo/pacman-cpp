#ifndef CORNER_COLLECTION_H
#define CORNER_COLLECTION_H

#include <vector>
#include "FixedDirection.h"
#include "Corner.h"
#include "Params.h"

class CornerCollection
{
private:
	std::vector<Corner *> vector;

public:
	CornerCollection() {}
	void Add(Corner* e) { vector.push_back(e); }
	Corner * GetAbove(Corner* corner);
	void RegisterCorner(Corner *corner, Corner *left_corner, Corner * top_corner);
};

#endif
