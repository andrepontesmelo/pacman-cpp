#ifndef FOOD_H
class Food;
#define FOOD_H

#include "Position.h"
#include "DrawingElement.h"
#include "NullReferenceException.h"
#include "Color.h"
#include "Bitmap.h"
#include "Params.h"
#include "CollisionDetection.h"
#include "Reconstruction.h"

class Food : public DrawingElement, public Subject
{
private:
	Position * position;
	Bitmap * CreateBitmap(Position * position);
	void Initilize(Position * position);

public:
	Food(Position * position);
	Food(int x, int y);
	virtual ~Food(){}
	Position * GetPosition() { return position; }
	virtual bool PacmanCanEat() { return true; }
	virtual void WasEaten();
	void Reset() { visible = true; }
};

#endif
