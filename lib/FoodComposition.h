#ifndef FOOD_COMPOSITION
class FoodComposition;
#define FOOD_COMPOSITION
#include "Food.h"
#include "IObserver.h"
#include "PillComposition.h"
#include "Subject.h"
#include "Reconstruction.h"
#include "Allegro.h"
#include <vector>
using std::vector;

class FoodComposition : public IObserver
{
public:
FoodComposition();
void Add(Food *food);
void Draw();
Food * Get_food_atop(Food* food);
void Refresh(int action);

private:
vector<Food*> foods;
int remaining_food;
void Reset();
};

#endif
