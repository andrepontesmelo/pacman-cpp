#include "Allegro.h"
#include "Bitmap.h"
#include "Teclado.h"
#include "Labirinto.h"
#include "Tela.h"
#include "Posicao.h"
#include "Params.h"
#include "Pacman.h"
#include "ControladorColisoes.h"
#include "ControladorVidas.h"
#include "Cronometro.h"
#include "ComposicaoFantasma.h"
#include "ComposicaoPilula.h"

int main()
{
	
	// Biblioteca grafica
	Allegro * allegro = Allegro::Instancia();
	allegro->Inicializa(LARGURA_TELA, ALTURA_TELA);

	Tela * tela = Tela::Instancia();
		
	// Carrega o labirinto, o pacman e os fantasmas
	Labirinto * labirinto =  Labirinto::Instancia();

	Pacman * pacman = new Pacman();
	
	// Abre o controlador de vidas
	ControladorVidas * vidas = ControladorVidas::Instancia();
	vidas->Set_pacman(pacman);

	ComposicaoFantasma * fantasmas = ComposicaoFantasma::Instancia();

	fantasmas->Gerar_fantasmas(pacman);
	
	// O controlador de pilulas conhece o controlador de fantasmas
	ComposicaoPilula::Instancia()->Set_fantasmas(fantasmas);

	// Gera o controlador colisoes singleton e informa a referencia do pacman
	ControladorColisoes * controlador_colisoes = ControladorColisoes::Instancia();
	controlador_colisoes->Set_pacman(pacman);

	// Controle do teclado
	Teclado *teclado = Teclado::Instancia();

	// Controle de tempo
	Cronometro cronometro;
	int tempo_passado = 0;
	//exit(0);
	// Iteração principal do jogo
	while (teclado->Tecla_pressionada() != Teclado::ESC)
	{
		// Inicia contagem de tempo da iteracao principal
		cronometro.Iniciar();
		teclado->Tecla_pressionada();

		// Atualiza a posicao dos objetos em funcao do tempo passado
		pacman->Atualizar_posicao(tempo_passado);
		teclado->Tecla_pressionada();

		fantasmas->Atualizar_posicao(tempo_passado);

		teclado->Tecla_pressionada();

		// Desenha objetos no buffer
		labirinto->Desenhar();
		teclado->Tecla_pressionada();
		
		fantasmas->Desenhar();
		teclado->Tecla_pressionada();

		pacman->Desenhar();
		teclado->Tecla_pressionada();

		// Desenha o controlador de vidas.
		vidas->Desenhar();

		// Atualiza a tela com o novo buffer 
		tela->Atualizar();
		teclado->Tecla_pressionada();				
		
		allegro->Esperar(10);

		// Verifica colisoes
		controlador_colisoes->Verificar_colisoes();
		teclado->Tecla_pressionada();		

		// Contabiliza tempo da iteracao principal
		cronometro.Atualizar_leitura();
		tempo_passado = cronometro.Leitura_Ms();
		
	}
	
	allegro->Finaliza();
	return 0;
}
END_OF_MAIN();

