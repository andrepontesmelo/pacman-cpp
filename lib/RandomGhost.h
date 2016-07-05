#ifndef RANDOM_GHOST_H
#define RANDOM_GHOST_H

#include "Ghost.h"
#include "FixedDirection.h"
#include <string>

class RandomGhost : public Ghost
{
	public:
		RandomGhost(int jail_time);
		
	protected:
		void UpdateDirectionVector();
		FixedDirection* NextDirection();

	private:
		static int ghosts_created;
		static string GetAlternatedName();
};

#endif
