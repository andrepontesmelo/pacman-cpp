#ifndef ICOLLIDABLE_H
#define ICOLLIDABLE_H
#include "IDrawable.h"

class ICollidable : public IDrawable
{
public:
bool virtual PacmanCanEat() = 0;
void virtual WasEaten() = 0;
void virtual AtePacman() {
}
virtual ~ICollidable() {
}
};
#endif
