/*
	Cada herdeiro deve, em sua construtora de preferencia, criar o IDesenhavel 'desenho'
*/
#ifndef FANTASMA_H
#include "ElementoAmbulante.h"
#include "IFantasma.h"
#include "DirecaoFixa.h"
#include "Direcao.h"
#include "Aleatorio.h"
#include "Cronometro.h"
#include "Params.h"
#include "ControladorColisoes.h"
#include "AproximadorGuloso.h"
#include "Caixa.h"
#include "ControladorVidas.h"
#include "Reconstrucao.h"

#define FANTASMA_H


class Fantasma : public ElementoAmbulante, public IFantasma
{
	public:
		Fantasma(int tempo_prisao);
		DirecaoFixa* Obter_direcao();
		void Desenhar() { ElementoAmbulante::Desenhar(); }
		virtual bool Comivel_pelo_pacman() { return efeito_pilula; }
		virtual void Comeu_pacman();

		virtual void Foi_comido();
		void Pilula_acabou();
		void Reiniciar();

		// Chamado pelo controlador de fantasmas quando pilula é comida.
		void Pilula_comida();
		void Pilula_acabando();
		
		// Observacao. Observa a morte do pacman
		void virtual Atualiza(int acao);
	
	protected:
		enum Acao { PRESO, SAINDO, SOLTO, VOLTANDO, ENTRANDO};
		enum Acao acao;
		void Atualizar_posicao(int tempo_passado_Ms);
		AproximadorGuloso * aproximador_prisao;
		IDesenhavel *desenho_normal;
		virtual int Periodo();
		bool efeito_pilula, piscando;

	private:
		bool Posicao_fora_da_prisao();
		void Preparar_prisioneiro();
		void Sair_da_prisao();
		void Enquadrar_na_prisao();
		int tempo_prisao;

		void Abrir_desenhos();

		//Animacao* ani_piscando; Bitmap 
		
		Direcao* direcao_aleatoria; // Direcao dentro da area central
		Caixa * area_central;
		
		// Conta o tempo que o fantasma fica na prisao
		Cronometro cronometro_prisao;

		// Representacoes graficas:

		IDesenhavel *desenho_efeito_pilula;
		IDesenhavel *desenho_piscando;
		IDesenhavel *desenho_comido;
};


#endif
