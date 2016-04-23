#ifndef APROXIMADOR_GULOSO_H
#include "ElementoAmbulante.h"
#include "Esquina.h"
#include "DirecaoFixa.h"
#include "Aleatorio.h"
#include "Aproximador.h"
#define APROXIMADOR_GULOSO_H

class AproximadorGuloso : public Aproximador
{
	
	public:
		AproximadorGuloso(Posicao * pos_alvo, ElementoAmbulante *perseguidor);
		virtual DirecaoFixa * Direcao_aproximacao();
	
};

#endif
