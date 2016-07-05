#include "Reconstruction.h"

Reconstruction* Reconstruction::instance = 0;

Reconstruction::Reconstruction()
{
}

Reconstruction* Reconstruction::Instance()
{
	if (instance == 0)
		instance = new Reconstruction();

	return instance;
}


void Reconstruction::PacmanDied()
{
	Notify(PACMAN_DIED);
}

void Reconstruction::NewPhase()
{
	Notify(NEW_PHASE);
}

void Reconstruction::FoodEaten()
{
	Notify(FOOD_EATEN);
}
