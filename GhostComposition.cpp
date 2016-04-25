#include "GhostComposition.h"

GhostComposition * GhostComposition::instance = 0;

void GhostComposition::Refresh(int action)
{
	vector<IGhost*>::iterator iterador;
	for (iterador = ghosts.begin(); iterador < ghosts.end(); iterador++)
		(*iterador)->Refresh(action);

	switch (action)
	{
		case Reconstruction::NEW_PHASE:
		ghosts.push_back(new GreedyGhost(MIN_TIME_JAIL + JAIL_TIME * ghosts.size(), pos_pacman));
		
		break;
	}
}

GhostComposition::GhostComposition()
{
	pos_pacman = 0;
	pill_stage = DISABLED;

	Reconstruction::Instance()->AddObserver(this);
}

void GhostComposition::Generate_ghosts(Pacman * pacman)
{
	if (pos_pacman != 0)
		throw new Exception("Generate_ghosts chamado mais de uma vez na composition de ghosts.");
	
	pos_pacman = pacman->GetPosition();

	if (pos_pacman == 0)
		throw new NullReferenceException("pos_pacman", "GhostComposition::Generate_ghosts()");

	ghosts.push_back(new GreedyGhost(MIN_TIME_JAIL + JAIL_TIME * 0, pos_pacman));

	ghosts.push_back(new RandomGhost(MIN_TIME_JAIL + JAIL_TIME * 1));
	
	ghosts.push_back(new GreedyGhost(MIN_TIME_JAIL + JAIL_TIME * 2, pos_pacman));
	
	ghosts.push_back(new RandomGhost(MIN_TIME_JAIL + JAIL_TIME * 3));
}

void GhostComposition::Draw()
{
	vector<IGhost*>::iterator iterador;
	for (iterador = ghosts.begin(); iterador < ghosts.end(); iterador++)
		(*iterador)->Draw();
	
	switch (pill_stage)
	{
		case ACTIVATED:
		pill_effect.Refresh();
		if (pill_effect.ReadMs() > PILL_TIME)
		{
			for (iterador = ghosts.begin(); iterador < ghosts.end(); iterador++)
				(*iterador)->FinishingPill();

			pill_stage = FINISHING;
			end_pill.Start();
		}
		break;
		case FINISHING:
		end_pill.Refresh();
		if (end_pill.ReadMs() > PILL_FINISHING_DURATION)
		{
			for (iterador = ghosts.begin(); iterador < ghosts.end(); iterador++)
				(*iterador)->PillFinished();

			pill_stage = DISABLED;
		}
		break;
		case DISABLED:
		break;
	}
}

void GhostComposition::UpdatePosition(int time)
{
	vector<IGhost*>::iterator iterador;
	for (iterador = ghosts.begin(); iterador < ghosts.end(); iterador++)
		(*iterador)->UpdatePosition(time);
}

void GhostComposition::PillEaten()
{
	vector<IGhost*>::iterator iterador;
	for (iterador = ghosts.begin(); iterador < ghosts.end(); iterador++)
		(*iterador)->PillEaten();
	
	pill_stage = ACTIVATED;
	pill_effect.Start();
}

GhostComposition* GhostComposition::Instance()
{
	if (instance == 0)
		instance = new GhostComposition();

	return instance;
}