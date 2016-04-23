#ifndef APROXIMADOR_H
#define APROXIMADOR_H
#include "Posicao.h"
#include "DirecaoFixa.h"
#include "ElementoAmbulante.h"

class Aproximador
{
	protected:
		Aproximador(Posicao * pos_alvo, ElementoAmbulante *perseguidor);		
		// Se direcao aproxima do perseguidore conversão é possivel
		bool Validar_proxima_direcao(DirecaoFixa * d);
		ElementoAmbulante * perseguidor;
		Posicao * pos_alvo;

	public:
		
		Posicao * Pos_alvo() { return pos_alvo; }
		virtual DirecaoFixa * Direcao_aproximacao() = 0;
		// Direcao inversao da Proxima_direcao(), porem valida.
		DirecaoFixa * Direcao_afastamento();
		virtual ~Aproximador() {}
};	
#endif
