#include "ElementoRepresentavel.h"

void ElementoRepresentavel::Inicializar()
{
	visivel = true;
}

ElementoRepresentavel::ElementoRepresentavel(IDesenhavel * desenho)
{
	this->desenho = desenho;
//	Alterar_desenho(desenho);
	Inicializar();
}

ElementoRepresentavel::ElementoRepresentavel()
{
	this->Inicializar();
}

/*
void ElementoRepresentavel::Alterar_desenho(IDesenhavel * desenho)
{
	this->desenho = desenho;
}
*/

int ElementoRepresentavel::Altura()
{
	return desenho->Altura();
	
}

int ElementoRepresentavel::Largura()
{
	return desenho->Largura();
	
}

int ElementoRepresentavel::X()
{
	return desenho->X();
	
}

int ElementoRepresentavel::Y()
{
	return desenho->Y();
}

void ElementoRepresentavel::Set_pos(int x, int y)
{
	desenho->Set_pos(x, y);
}


void ElementoRepresentavel::Desenhar()
{
#ifdef DEBUG
	if (desenho == 0)
		throw new ExcessaoReferenciaNula("desenho", "ElementoRepresentavel::Desenhar()");
#endif

	if (visivel) desenho->Desenhar();
}
