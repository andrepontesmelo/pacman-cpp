#include "Posicao.h"

string Posicao::String()
{
	stringstream resposta;
	resposta << "(x = " << x << "; y = " << y << ") ";

	return resposta.str();
}

int Posicao::X()
{
	return x;
}

int Posicao::Y()
{
	return y;
}

Posicao::Posicao()
{
	x = 0;
	y = 0;
}

Posicao::Posicao(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Posicao::Distancia(Posicao * b)
{
	// Nao eh a distancia direta via hipotenusa, mas a soma dos caminhos.
	return  Distancia_horizontal(b) + Distancia_vertical(b);
}

int Posicao::Distancia_horizontal(Posicao *b)
{
	return abs(b->X() - x);
}

int Posicao::Distancia_vertical(Posicao *b)
{
	return abs(b->Y() - y);
}
	
bool Posicao::Maior_que(Posicao *b, DirecaoFixa *d)
{
	/* A primeira parcela é o quanto a posicao b esta na frete de a.
	ao multiplicarmos pela componente X() da direção, zeramos o valor
	caso estejamos interessados em direção perpendicular.
    */
//bool resposta = (x - b->X()) * d->X() +  (y - b->Y()) * d->Y() > 0 ? true: false;

//	cout << "Posicao " << String() << " > " << b->String() << " (dir " << d->String() << " ) ? " << resposta << "\n";
	
	return (x - b->X()) * d->X() +  (y - b->Y()) * d->Y() > 0 ? true: false;
}

