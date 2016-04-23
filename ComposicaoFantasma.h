#ifndef COMPOSICAOFANTASMA
class ComposicaoFantasma;
#define COMPOSICAOFANTASMA

#include "IFantasma.h"
#include "FantasmaAleatorio.h"
#include "FantasmaGuloso.h"
#include "Params.h"
#include "Posicao.h"
#include "ExcessaoReferenciaNula.h"
#include "Cronometro.h"
#include "Pacman.h"
#include "Excessao.h"
#include "Reconstrucao.h"

#include <vector>
using std::vector;

class ComposicaoFantasma : public IFantasma
{
	public:
		void Alterar_modo(enum Modo novo_modo) {}
		void Atualizar_posicao(int tempo);
		void Desenhar();
		void Pilula_comida();
		void Gerar_fantasmas(Pacman * pacman);
		static ComposicaoFantasma * Instancia();
		void Pilula_acabando(){}
		void Pilula_acabou(){}
		//void Reiniciar();
		void Atualiza(int acao);

	private:
//		IFantasma* fantasmas[FANTASMAS_QTD];
		vector<IFantasma*> fantasmas;

		static ComposicaoFantasma * instancia;
		ComposicaoFantasma();
		Posicao * pos_pacman;

		Cronometro crono_efeito_pilula;
		Cronometro crono_fim_pilula;
		enum EstagioPilula { DESATIVADA, ATIVADA, ACABANDO };
		enum EstagioPilula estagio_pilula;
};

#endif
	
