
#ifndef IFANTASMA_H
#define IFANTASMA_H
#include "IDesenhavel.h" 
#include "IObservador.h"

class IFantasma : public IObservador
{
	public:
		enum Modo {PROCURA_PACMAN, FOGE_DO_PACMAN};
		virtual ~IFantasma() {}
		virtual void Desenhar() = 0;
		virtual void Atualizar_posicao(int tempo) = 0;
		virtual void Pilula_comida() = 0;
		virtual void Pilula_acabando() = 0;
		virtual void Pilula_acabou() = 0;
		//virtual void Reiniciar() = 0;
};

#endif
