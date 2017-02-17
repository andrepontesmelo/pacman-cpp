#ifndef ANIMATION_H
#define ANIMATION_H
#include <string>
#include <vector>

#include "IDrawable.h"
#include "Cronometer.h"
#include "NullReferenceException.h"
#include "Exception.h"
#include "Bitmap.h"
#include "Params.h"

using std::string;
using std::stringstream;

class Animation : public IDrawable
{
public:
Animation(int time);
void Add_bitmap(Bitmap *bmp);
void Draw();

bool virtual Visible() {
								return true;
}
void virtual SetCentered(bool c);
void SetPosition(int x, int y);
Position* GetPosition();
int Width();
int Height();

private:
int time_ms;
std::vector <Bitmap*> bitmaps;
std::vector<Bitmap*>::iterator iterador;
void Setup();
Cronometer cronometer;
void VerifyBitmaps(string module);
Bitmap * FirstBitmap();
};

#endif
