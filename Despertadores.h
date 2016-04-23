#ifndef DESPERTADORES_H

#include "IObservador.h"
#include "Despertador.h"

#define DESPERTADORES_H

class Despertadores
{
	public:
		Despertadores * Obter_instancia();
		Despertador* Criar_despertador(int intervalo, IObservador *objeto);
		void Verificar();
		
	private:
		Despertadores();
};

#endif
