#ifndef ELEMENTOAMBULANTE_H
#define ELEMENTOAMBULANTE_H

#include "DirecaoFixa.h"
#include "ElementoRepresentavel.h"
#include "Esquina.h"
#include "Labirinto.h"
#include "Params.h"


class ElementoAmbulante : public ElementoRepresentavel
{

	public:
		ElementoAmbulante();
		ElementoAmbulante(DirecaoFixa * direcao);
		virtual ~ElementoAmbulante() {}
//		void Mudar_direcao(DirecaoFixa *direcao);		// Substitui a direcao externamente
//		void Atualizar_direcao();		
		virtual void Atualizar_posicao(int tempo_passado_Ms);
		virtual void Desenhar();
		Esquina* Proxima_esquina() { return proxima_esquina; }

	protected:
		DirecaoFixa *direcao;
		bool parado;
		Esquina* proxima_esquina; 
		int acumulador_tempo;
		virtual int Periodo() = 0;
		virtual DirecaoFixa* Proxima_direcao() = 0;
		// Solicita que corrija a direcao do elemento (atualize o IDesenhavel desenho)
		virtual void Girar() {};
	
	private:
		void Inicializar();
		void Descobrir_proxima_esquina();
};		

#endif
