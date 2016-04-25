#include "DrawingElement.h"

void DrawingElement::Initilize()
{
	visible = true;
}

DrawingElement::DrawingElement(IDrawable * drawing)
{
	this->drawing = drawing;
	Initilize();
}

DrawingElement::DrawingElement()
{
	this->Initilize();
}

int DrawingElement::Height()
{
	return drawing->Height();
	
}

int DrawingElement::Width()
{
	return drawing->Width();
	
}

int DrawingElement::X()
{
	return drawing->X();
	
}

int DrawingElement::Y()
{
	return drawing->Y();
}

void DrawingElement::SetPosition(int x, int y)
{
	drawing->SetPosition(x, y);
}


void DrawingElement::Draw()
{
#ifdef DEBUG
	if (drawing == 0)
		throw new NullReferenceException("drawing", "DrawingElement::Draw()");
#endif

	if (visible) drawing->Draw();
}
