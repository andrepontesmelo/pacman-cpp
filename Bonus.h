#ifndef BONUS_H

#include "IObservador.h"
#include "ElementoRepresentavel.h"
#include "ControladorColisoes.h"
#define BONUS_H

class Bonus : public ElementoRepresentavel, public IObservador
{
	public:
		Bonus() : ElementoRepresentavel() { Inicializar(); }
		void Posicionar();
		int Tempo_aparicao();
		int Tempo_escondido();
		void Atualiza(int acao) {}		// Observacao
		virtual bool Comivel_pelo_pacman() { return true; }
	protected:
		void Inicializar();
};

#endif
