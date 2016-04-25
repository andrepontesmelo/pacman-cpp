#ifndef PILL_COMPOSITION
class PillComposition;
#define PILL_COMPOSITION

#include <vector>
#include "Pill.h"
#include "Cronometer.h"
using std::vector; 

class PillComposition
{
	public:
	
		void Add(Pill *pill);
		void Draw();
		void Set_ghosts (IGhost * ghost);
		static PillComposition* Instance();
		
		void Reset();

	private:
		vector<Pill*> pills;
		PillComposition() { ghosts = 0; }	
		IGhost * ghosts;
		static PillComposition* instance;
};

#endif
