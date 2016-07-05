#ifndef SMART_H
#define SMART_H

#include "FixedDirection.h"
#include "Position.h"

class Smart
{
	private:
		Smart* instance;
		void CreateHash();
	public:
		Smart * GetInstance();
		FixedDirection * GetDirection(Position *p);
};

#endif
