#ifndef SCREEN
#define SCREEN

#include "IDrawable.h"
#include "Allegro.h"
#include "Color.h"

class Screen
{
public:
static Screen* Instance();
int Width();
int Height();
void Draw(BITMAP * bitmap, int x, int y);
void DrawText(string text, int x, int y, Color * color, bool centered);

void Refresh();

private:
Screen(int width, int height);
static Screen* instance;
BITMAP* buffer;
int width;
int height;
};

#endif
