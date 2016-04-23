#include "ComposicaoPilula.h"

ComposicaoPilula* ComposicaoPilula::instancia = 0;

void ComposicaoPilula::Adicionar(Pilula* pilula)
{
	pilulas.push_back(pilula);
	pilula->Set_fantasmas(fantasmas);
}
/*
void ComposicaoPilula::Repor()
{
	vector<Pilula*>::iterator iterador = pilulas.begin();

	for (; iterador < pilulas.end(); iterador++)
		(*iterador)->Repor();
}
*/

void ComposicaoPilula::Desenhar()
{
	vector<Pilula*>::iterator iterador = pilulas.begin();

//	cout << "Desenhando as comidinhas...\n";	
	for (; iterador < pilulas.end(); iterador++)
		(*iterador)->Desenhar();
}

void ComposicaoPilula::Set_fantasmas (IFantasma * fantasmas)
{
	vector<Pilula*>::iterator iterador = pilulas.begin();

	for (; iterador < pilulas.end(); iterador++)
		(*iterador)->Set_fantasmas(fantasmas);
}

ComposicaoPilula* ComposicaoPilula::Instancia()
{
	if (instancia == 0)
		instancia = new ComposicaoPilula();

	return instancia;
}
