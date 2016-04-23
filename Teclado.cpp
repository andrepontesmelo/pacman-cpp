#include "Teclado.h"

Teclado * Teclado::instancia = 0;

Teclado::Teclado()
{
	ultima_tecla = NADA;
}

void Teclado::Pausa()
{
	readkey();
}


Teclado* Teclado::Instancia()
{
	if (instancia == 0)
		instancia = new Teclado();
	
	return instancia;
}

enum Teclado::Tecla Teclado::Tecla_pressionada()
{
	if (key[KEY_ESC])
		ultima_tecla = ESC;

	if (key[KEY_DOWN])
		ultima_tecla = BAIXO;

	if (key[KEY_UP])
		ultima_tecla = CIMA;

	if (key[KEY_LEFT])
		ultima_tecla = ESQUERDA;

	if (key[KEY_RIGHT])
		ultima_tecla = DIREITA;
	
//	cout << "Li " << ultima_tecla << "\n";
	return ultima_tecla;
}
