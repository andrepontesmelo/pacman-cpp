#ifndef RECONSTRUCTION_H
#define RECONSTRUCTION_H
#include "Subject.h"

class Reconstruction : public Subject
{
	private:
		static Reconstruction * instance;
		Reconstruction();

	public:
		static Reconstruction* Instance();
		enum Action { PACMAN_DIED, NEW_PHASE, FOOD_EATEN };
		
		void PacmanDied();
		void NewPhase();
		void FoodEaten();
};

#endif
