
#ifndef SMART_GHOST_H
#define SMART_GHOST_H 

#include "Ghost.h"

class SmartGhost : public Ghost
{
public:
	SmartGhost();
protected:
	void UpdateDirectionVector();
	
};

#endif	
