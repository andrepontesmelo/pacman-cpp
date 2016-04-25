#ifndef IDRAWABLE_H
#define IDRAWABLE_H
#include "Position.h"

class IDrawable
{
public:
	virtual void  SetCentered(bool c) = 0;
	virtual int  Width() = 0;
	virtual int  Height() = 0;
	virtual Position* GetPosition() = 0;
	virtual void  Draw() = 0;
	virtual bool Visible() = 0;

	IDrawable() { 
		imitator_position = 0; 
		sending_position_to_imitator = false; 
	}

	void IncrementPosition(int x, int y) { SetPosition(X() + x, Y() + y);  }
	void SetPosition_x(int x) { SetPosition(x, Y()); }
	void SetPosition_y(int y) { SetPosition(X(), y); }

	int virtual X() { return GetPosition()->X(); }
	int virtual Y() { return GetPosition()->Y(); }
	
	virtual ~IDrawable() {}

	void SetImitatorPosition(IDrawable* i) { imitator_position = i;	}
	
	void virtual SetPosition(int x, int y) 
	{ 
		if ((imitator_position == 0) || (sending_position_to_imitator)) 
			return;

			// Avoid deadlock			
		sending_position_to_imitator = true;
		imitator_position->SetPosition(x, y); 
		sending_position_to_imitator = false;
	}

private:
	IDrawable * imitator_position;
	bool sending_position_to_imitator;
};


#endif
