#ifndef BONUS_H
#define BONUS_H

#include "IObserver.h"
#include "DrawingElement.h"
#include "CollisionDetection.h"

class Bonus : public DrawingElement, public IObserver
{
public:
	Bonus() : DrawingElement() { Initilize(); }
	void Place();
	int GetVisibleTime();
	int GetHiddenTime();
	void Refresh(int action) {}	
	virtual bool PacmanCanEat() { return true; }
protected:
	void Initilize();
};

#endif
