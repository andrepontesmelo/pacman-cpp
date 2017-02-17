#include "Random.h"

Random* Random::instance = 0;

bool Random::GenerateBool()
{
								return (Generate(1) == 1);
}

int Random::Generate(int max)
{
								return rand() % (max + 1);
}

double Random::Generate()
{
								return ((double) rand() - (RAND_MAX / 2)) / RAND_MAX;
}

Random* Random::Instance()
{
								if (instance == 0)
																instance = new Random();

								return instance;
}

Random::Random()
{
								srand((unsigned) time(0));
}
