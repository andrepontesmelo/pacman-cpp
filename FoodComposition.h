#ifndef COMPOSICAO_FOOD
class FoodComposition;
#define COMPOSICAO_FOOD
#include "Food.h"
#include "IObserver.h"
#include "PillComposition.h"
//#include "GhostComposition.h"
//#include "Pacman.h"
#include "Subject.h"
#include "Reconstruction.h"
#include "Allegro.h"
#include <vector>
using std::vector; 

/* 
	Observa pacman
  	é observado pelo 
*/
class FoodComposition : public IObserver
{
	public:
		FoodComposition();
		void Add(Food *food);
		void Draw();
		Food * Obter_food_atop(Food* food);
		void Refresh(int action);

	private:
		vector<Food*> foods;
		int foods_restantes;
		void Reset();
};

#endif
