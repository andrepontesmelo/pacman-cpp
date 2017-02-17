#include "Screen.h"

Screen* Screen::instance = 0;

Screen::Screen(int width, int height)
{
								this->width = width;
								this->height = height;

								buffer = create_bitmap(width, height);
								clear_bitmap(buffer);
}


int Screen::Width()
{
								return width;
}

int Screen::Height()
{
								return height;
}


Screen* Screen::Instance()
{
								if (instance == 0)
								{
																Allegro * allegro = Allegro::Instance();
																instance = new Screen(allegro->Width(), allegro->Height());
								}

								return instance;
}

void Screen::Refresh()
{

								vsync();
								blit(buffer, screen, 0, 0, 0, 0, width, height);
								clear_bitmap(buffer);
}

void Screen::Draw(BITMAP * bitmap, int x, int y)
{
								draw_sprite(buffer, bitmap, x, y);
}

void Screen::DrawText(string text, int x, int y, Color * color, bool centered)
{
								if (centered)
																textout_centre_ex(buffer, font, text.c_str(), x, y, makecol(color->R(), color->G(), color->B()), -1);
								else
																textout_ex(buffer, font, text.c_str(), x, y, makecol(color->R(), color->G(), color->B()), -1);
}
