#include "Food.h"

void Food::Initilize(Position * position) 
{
	this->position = position;
	drawing = CreateBitmap(position);
	CollisionDetection::Instance()->Add(this);
}

Food::Food(int x, int y)
{
	Initilize(new Position(x - FOOD_RADIUS, y - FOOD_RADIUS));
}

Food::Food(Position * position)
{
	Initilize(position);
}


Bitmap * Food::CreateBitmap(Position * position)
{
#ifdef DEBUG
	if (position == 0)
		throw new NullReferenceException("position", "Food::CreateBitmap");
#endif

	Bitmap * bmp = new Bitmap(2 * FOOD_RADIUS + 1, 2 * FOOD_RADIUS + 1, position->X(), position->Y());
	Color * color = new Color(FOOD_COLOR_R, FOOD_COLOR_G, FOOD_COLOR_B);

	bmp->Clean();
	bmp->DrawFilledCircle(FOOD_RADIUS, FOOD_RADIUS, FOOD_RADIUS, color);

	return bmp;
}

void Food::WasEaten()
{
	DrawingElement::WasEaten(); 
	Reconstruction::Instance()->FoodEaten();
}
