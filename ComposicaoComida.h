#ifndef COMPOSICAO_COMIDA
class ComposicaoComida;
#define COMPOSICAO_COMIDA
#include "Comida.h"
#include "IObservador.h"
#include "ComposicaoPilula.h"
//#include "ComposicaoFantasma.h"
//#include "Pacman.h"
#include "Assunto.h"
#include "Reconstrucao.h"
#include "Allegro.h"
#include <vector>
using std::vector; 

/* 
	Observa pacman
  	é observado pelo 
*/
class ComposicaoComida : public IObservador
{
	public:
		ComposicaoComida();
		void Adicionar(Comida *comida);
		void Desenhar();
		Comida * Obter_comida_acima(Comida* comida);
		void Atualiza(int acao);

	private:
		vector<Comida*> comidas;
		int comidas_restantes;
		void Repor();
};

#endif
