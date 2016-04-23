#ifndef ASSUNTO_H
#include "IObservador.h"
#include <vector>
#define ASSUNTO_H
using std::vector;
class Assunto
{
	public:
		void Adicionar_observador(IObservador *o);
		void Retirar_observador(IObservador *o);
	
	protected:
		void Notificar(int acao);
	
	private:
		vector<IObservador*> observadores;
};

#endif
