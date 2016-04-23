#ifndef FANTASMAALEATORIO_H

#include "Fantasma.h"
#include "DirecaoFixa.h"
#include <string>
//#include "AproximadorGuloso.h"

#define FANTASMAALEATORIO_H

class FantasmaAleatorio : public Fantasma
{
	public:
		FantasmaAleatorio(int tempo_prisao);
		
	protected:
		void Atualizar_vetor_direcao();
		DirecaoFixa* Proxima_direcao();
		//AproximadorGuloso * aproximador;

	private:
		// Contador de fantasmas criados, para geração alternada de nomes
		static int fantasmas_criados;
		static string Nome_alternado();

//		DirecaoFixa* proxima_direcao;
};

#endif
