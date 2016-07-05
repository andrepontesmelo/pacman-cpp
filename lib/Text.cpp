#include "Text.h"

Text::Text(string text, int x, int y, Color * color)
{
	this->text = text;
	pos = new Position(x, y);
	this->color = color;

	centered = false;
}

void Text::Draw()
{
	Screen::Instance()->DrawText(text, pos->X(), pos->Y(), color, centered);
}
