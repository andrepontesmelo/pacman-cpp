#include "LifeController.h"

LifeController * LifeController::instance = 0;

LifeController::LifeController()
{
	pacman = 0;
	pos = new Position(LIFE_DISPLAY_POS_X, LIFE_DISPLAY_POS_Y);
}

LifeController* LifeController::Instance()
{
	if (instance == 0)
		instance = new LifeController();

	return instance;
}

void LifeController::PacmanWasEaten()
{
#ifdef DEBUG
	if (pacman == 0)
		throw new NullReferenceException("pacman", "LifeController::PacmanWasEaten(). pacman was not set.");
#endif
	Allegro::Instance()->Wait(1000);	
	
	pacman->WasEaten();
	CollisionDetection::Instance()->Reset();
	lifes.clear();
	CreateLifes();


	if (pacman->LifeQty() < 0)
	{
		Screen * screen = Screen::Instance();

		Text *end = new Text("GAME OVER", screen->Width() / 2, screen->Height() / 2, 
			new Color(255, 5, 20));
		
		end->SetCentered(true);	
		end->Draw();
		screen->Refresh();
		Allegro::Instance()->Wait(8000);
		exit(0);
	}
}

void LifeController::SetPacman(Pacman* pacman)
{
	this->pacman = pacman; 
	CreateLifes();	
}

void LifeController::CreateLifes()
{
	for (int v = 0; v < pacman->LifeQty(); v++)
	{
		lifes.push_back(CreateLife(v));	
	}
}

BonusLife* LifeController::CreateLife(int x)
{
	BonusLife * b = new BonusLife();

	b->SetPosition(LIFE_DISPLAY_POS_X + b->Width() * 2 * x, 
		LIFE_DISPLAY_POS_Y + 50);

	return b;
}


void LifeController::Draw()
{
	vector<BonusLife*>::iterator iterador = lifes.begin();

	for (; iterador < lifes.end(); iterador++)
	{
		(*iterador)->Draw();
	}

}
