#ifndef COLECAO_ESQUINAS_H
#define COLECAO_ESQUINAS_H

#include <vector>
#include "DirecaoFixa.h"
#include "Esquina.h"
#include "Params.h"

class ColecaoEsquinas
{
	private:
		std::vector<Esquina *> vetor;

	public:
		ColecaoEsquinas() {}
		void Adicionar(Esquina* e) { vetor.push_back(e); }
		Esquina * ColecaoEsquinas::Obter_acima(Esquina* esquina);
		void ColecaoEsquinas::Registrar_esquina(Esquina *esquina, Esquina *esq_esquerda, Esquina * esq_cima);
};

#endif
