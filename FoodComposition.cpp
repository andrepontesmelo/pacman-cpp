#include "FoodComposition.h"

FoodComposition::FoodComposition()
{
	foods_restantes = 0;
	Reconstruction::Instance()->AddObserver(this);
}

void FoodComposition::Add(Food* food)
{
	foods.push_back(food);
	food->AddObserver(this);
	foods_restantes++;
}

void FoodComposition::Draw()
{
	vector<Food*>::iterator iterador = foods.begin();

	for (; iterador < foods.end(); iterador++)
		(*iterador)->Draw();
}

void FoodComposition::Refresh(int action)
{
	switch (action)
	{
		case Reconstruction::NEW_PHASE:
			Reset();
		break;
			
		case Reconstruction::PACMAN_DIED:
		break;

		case Reconstruction::FOOD_EATEN:
			foods_restantes--;

			if (foods_restantes == 0)
			{
				// Passou de fase!
				Allegro::Instance()->Wait(3000);
				Reconstruction::Instance()->NewPhase();
			}
		break;		
	}
}

/* Volta com as foods */
void FoodComposition::Reset()
{
	vector<Food*>::iterator iterador = foods.begin();

	for (; iterador < foods.end(); iterador++)
		(*iterador)->Reset();

	foods_restantes = foods.size();
}
