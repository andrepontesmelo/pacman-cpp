#include "Animation.h"

void Animation::Add_bitmap(Bitmap *bmp)
{
#ifdef DEBUG
								if (bmp == 0)
																throw new NullReferenceException("bmp", "Animation::Add_bitmap()");
#endif

								bitmaps.push_back(bmp);
								Setup();
}

void Animation::Setup()
{
								iterador = bitmaps.begin();
								cronometer.Start();
}

Animation::Animation(int time)
{
								time_ms = time;
}

void Animation::Draw()
{
#ifdef DEBUG
								VerifyBitmaps("Draw()");
#endif

								if (iterador == bitmaps.end())
																iterador = bitmaps.begin();

								(*iterador)->Draw();

								cronometer.Refresh();
								if (cronometer.ReadMs() > time_ms)
								{
																iterador++;
																cronometer.Start();
								}
}


void Animation::SetCentered(bool c)
{
								std::vector<Bitmap*>::iterator i;

								i = bitmaps.begin();

								for (; i < bitmaps.end(); i++)
																(*i)->SetCentered(c);

}

void Animation::SetPosition(int x, int y)
{
#ifdef DEBUG
								VerifyBitmaps("GetPosition()");
#endif
								std::vector<Bitmap*>::iterator i;
								i = bitmaps.begin();

								for (; i < bitmaps.end(); i++)
																(*i)->SetPosition(x, y);

								IDrawable::SetPosition(x, y);
}

Position* Animation::GetPosition()
{
#ifdef DEBUG
								VerifyBitmaps("GetPosition()");
#endif

								return FirstBitmap()->GetPosition();
}

int Animation::Height()
{
								return FirstBitmap()->Height();
}

int Animation::Width()
{
								return FirstBitmap()->Width();
}

#ifdef DEBUG
void Animation::VerifyBitmaps(string module)
{
								if (bitmaps.size() == 0)
								{
																throw new Exception("Draw() was called for an animation with empty set of bitmaps.. \nError in Animation::" + module);
								}
}
#endif

Bitmap * Animation::FirstBitmap()
{
								return (*bitmaps.begin());
}
