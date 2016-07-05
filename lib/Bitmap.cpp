#include "Bitmap.h"

void Bitmap::Initialize(BITMAP * bitmap, Position * pos)
{

#ifdef DEBUG
	if (bitmap == 0)
		throw new NullArgumentException("bitmap", "Bitmap Constructor");

	if (pos == 0)
		throw new NullReferenceException("position", "Bitmap::Bitmap(...)");
#endif		

	this->bmp = bitmap;

	this->position = pos;

	this->width = bitmap->w;
	this->height = bitmap->h;

	centered = false;
	instance_screen = Screen::Instance();
}


Bitmap::Bitmap(string file, int x, int y)
{
	BITMAP * bitmap = load_bmp(file.c_str(), NULL);
#ifdef DEBUG
	if (bitmap == NULL)
		throw new FileNotFoundException(file);
#endif
	Initialize(bitmap, new Position(x, y));
}

Bitmap::Bitmap(int width, int height, int x, int y)
{	
	bmp = create_bitmap(width, height);
	Clean();

	Initialize(bmp, new Position(x, y));
}

Bitmap::~Bitmap()
{
	destroy_bitmap(bmp);
}


void Bitmap::SetPosition(int x, int y)
{
#ifdef DEBUG
	if (position == 0)
		throw new NullReferenceException("position", "bitmap::SetPosition()");
#endif

	position->SetX(x);
	position->SetY(y);

	IDrawable::SetPosition(x, y);
}

void Bitmap::Clean()
{
	clear_bitmap(bmp);
}


void Bitmap::DrawFilledCircle(int x, int y, int radius, Color * color)
{
#ifdef DEBUG
	if (color == 0)
		throw new NullArgumentException("color", "Bitmap::DrawFilledCircle(...)");
#endif
	circlefill(bmp, x, y, radius, makecol(color->R(), color->G(), color->B()));
	
	
}

void Bitmap::DrawLine(int x, int y, int x1, int y1, Color * color)
{
#ifdef DEBUG
	if (color == 0)
		throw new NullArgumentException("color", "Bitmap::DrawLine(...)");
#endif
	line(bmp, x, y, x1, y1, makecol(color->R(), color->G(), color->B()));

}

void Bitmap::Draw()
{
#ifdef DEBUG
	if (position == 0)
		throw new NullReferenceException("position", "Bitmap::Draw()");
#endif

	if (centered)
		instance_screen->Draw(bmp, position->X() - (width / 2), position->Y() - (height / 2));
	else
		instance_screen->Draw(bmp, position->X(), position->Y());
}
