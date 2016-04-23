#ifndef DESPERTADOR_H
#include "Assunto.h"
#define DESPERTADOR_H

class Despertador : public Assunto
{
	public:
		void Verificar();
		Despertador();

	private:
		int intervalo_segs;
};

#endif
