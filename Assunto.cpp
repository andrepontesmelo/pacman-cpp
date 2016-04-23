#include "Assunto.h"

void Assunto::Adicionar_observador(IObservador *o)
{
	observadores.push_back(o);
}

void Assunto::Notificar(int acao)
{
	vector<IObservador*>::iterator iterador = observadores.begin();

	for (; iterador < observadores.end(); iterador++)
		(*iterador)->Atualiza(acao);
}
