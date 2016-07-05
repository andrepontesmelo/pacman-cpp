
#ifndef IGHOST_H
#define IGHOST_H
#include "IDrawable.h" 
#include "IObserver.h"

class IGhost : public IObserver
{
public:
	enum Mode {FIND_PACMAN, AVOID_PACMAN};
	virtual ~IGhost() {}
	virtual void Draw() = 0;
	virtual void UpdatePosition(int time) = 0;
	virtual void PillEaten() = 0;
	virtual void FinishingPill() = 0;
	virtual void PillFinished() = 0;
};

#endif
