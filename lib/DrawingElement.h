#ifndef DRAWING_ELEMENT_H
#define DRAWING_ELEMENT_H

#include "ICollidable.h"
#include "Position.h"
#include "NullReferenceException.h"
#include "Params.h"

class DrawingElement : public ICollidable
{
public:
DrawingElement(IDrawable *drawing);

void virtual Draw();
int X();
int Y();
void SetPosition(int x, int y);
int Width(); int Height();
Position * GetPosition() {
								return drawing->GetPosition();
}
void SetCentered(bool c) {
								drawing->SetCentered(c);
}
virtual bool PacmanCanEat() {
								return false;
}
virtual bool Visible() {
								return visible;
}
virtual void WasEaten() {
								visible = false;
}
virtual ~DrawingElement() {
}

protected:
DrawingElement();
IDrawable *drawing;
bool visible;

void Initilize();

};

#endif
