#include "PillComposition.h"

PillComposition* PillComposition::instance = 0;

void PillComposition::Add(Pill* pill)
{
								pills.push_back(pill);
								pill->Set_ghosts(ghosts);
}

void PillComposition::Draw()
{
								vector<Pill*>::iterator iterador = pills.begin();

								for (; iterador < pills.end(); iterador++)
																(*iterador)->Draw();
}

void PillComposition::Set_ghosts (IGhost * ghosts)
{
								vector<Pill*>::iterator iterador = pills.begin();

								for (; iterador < pills.end(); iterador++)
																(*iterador)->Set_ghosts(ghosts);
}

PillComposition* PillComposition::Instance()
{
								if (instance == 0)
																instance = new PillComposition();

								return instance;
}
