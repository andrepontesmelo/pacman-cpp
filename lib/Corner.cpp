#include "Corner.h"

void Corner::Initilize()
{
								for (int x = 0; x < 4; x++)
								{
																corners[x] = 0;
																wallkables[x] = false;
								}
}

Corner::Corner(int row, int column)
{
								position = new Position(column, row);
								Initilize();
}

void Corner::SetCorner(int pos, Corner * neibor, bool wallkable)
{
								corners[pos] = neibor;
								wallkables[pos] = wallkable;
}

FixedDirection* Corner::DirectionToAnyCorner()
{
								int Attemptt = Random::Instance()->Generate(3);

								while (corners[Attemptt] == 0)
																Attemptt = Random::Instance()->Generate(3);

								return FixedDirection::GetByCode(Attemptt);
}
