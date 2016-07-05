#ifndef GHOST_COMPOSITION
class GhostComposition;
#define GHOST_COMPOSITION

#include "IGhost.h"
#include "RandomGhost.h"
#include "GreedyGhost.h"
#include "Params.h"
#include "Position.h"
#include "NullReferenceException.h"
#include "Cronometer.h"
#include "Pacman.h"
#include "Exception.h"
#include "Reconstruction.h"

#include <vector>
using std::vector;

class GhostComposition : public IGhost
{
public:
	void SwitchMode(enum Mode novo_modo) {}
	void UpdatePosition(int time);
	void Draw();
	void PillEaten();
	void Generate_ghosts(Pacman * pacman);
	static GhostComposition * Instance();
	void FinishingPill(){}
	void PillFinished(){}
	void Refresh(int action);

private:
	vector<IGhost*> ghosts;

	static GhostComposition * instance;
	GhostComposition();
	Position * pos_pacman;

	Cronometer pill_effect;
	Cronometer end_pill;
	enum EstagioPill { DISABLED, ACTIVATED, FINISHING };
	enum EstagioPill pill_stage;
};

#endif

