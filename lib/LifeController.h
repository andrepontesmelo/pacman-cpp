#ifndef LIFE_DISPLAY_H
#define LIFE_DISPLAY_H
#include "Pacman.h"
#include "Params.h"
#include "BonusLife.h"
#include "NullReferenceException.h"
#include "Text.h"
#include "Position.h"
#include "Screen.h"
#include "Allegro.h"
#include <vector>
using std::vector;

class LifeController : IDrawable
{
private:
static LifeController * instance;
Pacman * pacman;
Position * pos;
vector<BonusLife*> lifes;
void CreateLifes();

public:
LifeController();
static LifeController* Instance();
void PacmanWasEaten();
void SetPacman(Pacman* pacman);
BonusLife* CreateLife(int qual);

virtual bool Visible() {
								return true;
}
virtual void SetCentered(bool c) {
};
virtual int Width() {
								return 0;
}
virtual int Height() {
								return 0;
}
virtual Position* GetPosition() {
								return pos;
}
virtual void Draw();
};

#endif
