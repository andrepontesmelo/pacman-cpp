#include "FoodComposition.h"

FoodComposition::FoodComposition()
{
								remaining_food = 0;
								Reconstruction::Instance()->AddObserver(this);
}

void FoodComposition::Add(Food* food)
{
								foods.push_back(food);
								food->AddObserver(this);
								remaining_food++;
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
																remaining_food--;

																if (remaining_food == 0)
																{
																								Allegro::Instance()->Wait(3000);
																								Reconstruction::Instance()->NewPhase();
																}
																break;
								}
}

void FoodComposition::Reset()
{
								vector<Food*>::iterator iterador = foods.begin();

								for (; iterador < foods.end(); iterador++)
																(*iterador)->Reset();

								remaining_food = foods.size();
}
