#include "Aleatorio.h"

Aleatorio* Aleatorio::instancia = 0;

bool Aleatorio::GerarBool()
{
	return (Gerar(1) == 1);
}

int Aleatorio::Gerar(int max)
{
	return rand() % (max + 1);
}

double Aleatorio::Gerar()
{
	return ((double) rand()-(RAND_MAX/2)) / RAND_MAX;
}

Aleatorio* Aleatorio::Instancia()
{
	if (instancia == 0)
		instancia = new Aleatorio();
	
	return instancia;
}

Aleatorio::Aleatorio()
{
	srand((unsigned) time(0));
}

