#ifndef GHOST_H
#define GHOST_H

#include "WalkingElement.h"
#include "IGhost.h"
#include "FixedDirection.h"
#include "Direction.h"
#include "Random.h"
#include "Cronometer.h"
#include "Params.h"
#include "CollisionDetection.h"
#include "GreedyFollower.h"
#include "Box.h"
#include "LifeController.h"
#include "Reconstruction.h"

class Ghost : public WalkingElement, public IGhost
{
	public:
		Ghost(int jail_time);
		FixedDirection* GetDirection();
		void Draw() { WalkingElement::Draw(); }
		virtual bool PacmanCanEat() { return pill_effect; }
		virtual void AtePacman();
		virtual void WasEaten();
		void PillFinished();
		void Reset();
		void PillEaten();
		void FinishingPill();
		
		// Observer design pattern
		void virtual Refresh(int action);
	
	protected:
		enum Action { ARRESTED, RELEASING, RELEASE, RETURNING, ENTERING};
		enum Action action;
		void UpdatePosition(int elapsed_ms);
		GreedyFollower * jail_follower;
		IDrawable *regular_drawing;
		virtual int Interval();
		bool pill_effect, blinking;

	private:
		bool GetPositionOutsideJail();
		void PreparePrisioners();
		void ExitJail();
		void ForceJail();
		int jail_time;

		void LoadBitmaps();

		Direction* random_direction; // Direction dentro da area central
		Box * jail;
		
		Cronometer cronometer_jail;

		IDrawable *bitmap_pill_efect;
		IDrawable *bitmap_blink;
		IDrawable *bitmap_eaten;
};


#endif
