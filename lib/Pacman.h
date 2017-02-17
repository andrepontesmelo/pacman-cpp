#ifndef PACMAN_H
class Pacman;
#define PACMAN_H

#include "WalkingElement.h"
#include "Bitmap.h"
#include "Keyboard.h"
#include "FixedDirection.h"
#include "IDrawable.h"
#include "Reconstruction.h"
#include "IObserver.h"

class Pacman : public WalkingElement, public IObserver
{
private:
int lifes;
FixedDirection * next_direction;

IDrawable* flipped_drawings[4];
void LoadBitmaps();
void Initilize();

protected:
virtual FixedDirection* NextDirection() {
								return next_direction;
}
virtual void Flip();
virtual int Interval() {
								return PACMAN_INTERVAL;
}

public:
Pacman();
~Pacman() {
};
void virtual UpdatePosition(int elapsed_ms);
void virtual Draw();
int LifeQty() {
								return lifes;
}
void virtual WasEaten();
void virtual Refresh(int action);

};
#endif
