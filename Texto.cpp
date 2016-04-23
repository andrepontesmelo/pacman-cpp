#include "Texto.h"

Texto::Texto(string texto, int x, int y, Cor * cor)
{
	this->texto = texto;
	pos = new Posicao(x, y);
	this->cor = cor;

	centralizado = false;
}

void Texto::Desenhar()
{
	Tela::Instancia()->Desenhar_texto(texto, pos->X(), pos->Y(), cor, centralizado);
}
