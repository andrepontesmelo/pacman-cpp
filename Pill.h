#ifndef PILL_H
#define PILL_H
#include "Bonus.h"
#include "Animation.h"
#include "Params.h"
#include "IGhost.h"
#include "NullReferenceException.h"
#include "Reconstruction.h"

class Pill : public Bonus
{
	public:
		Pill(int x, int y);
		virtual void WasEaten();
		void Set_ghosts(IGhost * ghosts) { this->ghosts = ghosts; }
		void Refresh(int action);

	private:
		IGhost * ghosts;
		Animation * Construir_animation(int x, int y);

};

#endif
