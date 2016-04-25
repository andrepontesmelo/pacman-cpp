#include "Direction.h"

string Direction::String()
{
	stringstream result;	
	result << "X: " << x << " Y: " << y << " ";

	return result.str();
}

Direction* Direction::GetRandomly(double min_abs)
{
	Direction *new_obj = new Direction();
	new_obj->SetRandomly(min_abs);

	return new_obj;
}

void Direction::SetRandomly(double min_abs)
{
	Random * random = Random::Instance();

	x = 0; y = 0;

	while(fabs(x) < min_abs)
		x = random->Generate();
	
	while(fabs(y) < min_abs)
		y = random->Generate();
}
