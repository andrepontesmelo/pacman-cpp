
#ifndef BITMAP_H
#include "Allegro.h"
#include "IDrawable.h"
#include "FileNotFoundException.h"
#include "NullArgumentException.h"
#include "NullReferenceException.h"
#include "Position.h"
#include "Color.h"
#include "Screen.h"
#include <string>
#include "Params.h"
#define BITMAP_H

class Bitmap : public IDrawable
{
private:
BITMAP *bmp;
Position *position;
int width, height;
bool centered;
Screen * instance_screen;
void Initialize(BITMAP * bitmap, Position * pos);

public:

int Width() {
								return width;
}
int Height()  {
								return height;
}
void SetPosition(int x, int y);
Position * GetPosition() {
								return position;
}
void SetCentered(bool c) {
								centered = c;
}
bool Visible() {
								return true;
}
Bitmap(string file, int x = 0, int y = 0);

Bitmap(int width, int height, int x = 0, int y = 0);

virtual ~Bitmap();

void Collided(IDrawable * other);
BITMAP* Bmp() {
								return bmp;
}
void Clean();
void DrawFilledCircle(int x, int y, int radius, Color * color);
void DrawLine(int x, int y, int x1, int y1, Color * color);
void Draw();

};

#endif
