#ifndef TEXTO_H
#define TEXTO_H
#include "IDrawable.h"
#include <string>
#include "Position.h"
#include "Screen.h"
#include "Color.h"

class Text : public IDrawable
{
private:
string text;
Position * pos;
Color * color;
bool centered;

public:
Text(string text, int x, int y, Color * color);

virtual void  SetCentered(bool c) {
								centered = c;
}
virtual int  Width() {
								return 0;
}
virtual int  Height() {
								return 0;
}
virtual Position* GetPosition() {
								return pos;
}
virtual void  Draw();
virtual bool Visible() {
								return true;
}
};

#endif
