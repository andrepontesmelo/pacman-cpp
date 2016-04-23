

#ifndef FANTASMAGULOSO_H
#include "Fantasma.h"
#include "Posicao.h"
#include "DirecaoFixa.h"
#include "AproximadorGuloso.h"
#include "IDesenhavel.h"
#define FANTASMAGULOSO_H

class FantasmaGuloso : public Fantasma
{
	protected:
		DirecaoFixa * Proxima_direcao();

	public:
		FantasmaGuloso(int tempo_prisao, Posicao * pos_pacman);

	private:
		AproximadorGuloso * aproximador_pacman;
		// Contador de fantasmas criados, para geração alternada de nomes
		static int fantasmas_criados;
		static string Nome_alternado();
};

#endif
