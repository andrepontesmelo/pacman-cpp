#ifndef INTELIGENCIAESPERTO_H

#include "DirecaoFixa.h"
#include "Posicao.h"

#define INTELIGENCIAESPERTO_H

class InteligenciaEsperto
{
	private:
		InteligenciaEsperto* instancia;
//		Hashtable * hashPosicao;
		void Criar_hash();
	public:
		InteligenciaEsperto * Obter_instancia();
		DirecaoFixa * Obter_direcao(Posicao *p);
};

#endif
