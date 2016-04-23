#include "Fantasma.h"

void Fantasma::Atualiza(int acao)
{
	switch (acao)
	{
		case Reconstrucao::NOVA_FASE:
		case Reconstrucao::PACMAN_MORREU:
			Reiniciar();
		break;
	}
}

void Fantasma::Reiniciar()
{
	Labirinto * labirinto = Labirinto::Instancia();
	Esquina * esquina_inicial = labirinto->Esquina_inicio_fantasma();

	Pilula_acabou();	
	Preparar_prisioneiro();

	desenho->Set_pos(esquina_inicial->Pos()->X(), esquina_inicial->Pos()->Y());
}

Fantasma::Fantasma(int tempo_prisao)
{
	Labirinto * labirinto = Labirinto::Instancia();
	
	this->tempo_prisao = tempo_prisao;
//	this->desenho_normal = desenho_normal;

	proxima_esquina = Labirinto::Instancia()->Esquina_inicio_fantasma();
	Esquina * esquina_inicial = labirinto->Esquina_inicio_fantasma();
	aproximador_prisao = new AproximadorGuloso(esquina_inicial->Pos(), this);

	area_central = labirinto->Area_central();

	Abrir_desenhos();
	
	// Registra si mesmo no controlador de colisoes:
	ControladorColisoes::Instancia()->Adicionar(this);
	
	// Registra si mesmo na reconstrução
//	Reconstrucao::Instancia()->Adicionar_observador(this);

	Preparar_prisioneiro();
}

void Fantasma::Abrir_desenhos()
{
	Labirinto * labirinto = Labirinto::Instancia();
	Esquina * esquina_inicial = labirinto->Esquina_inicio_fantasma();
	Posicao * pos_inicial = esquina_inicial->Pos();

	// Cria animação acabando_pilula
	Animacao * animacao_piscando;
	animacao_piscando = new Animacao(FANTASMA_PERIODO_PISCANDO_ACABANDO_PILULA);
	animacao_piscando->Inserir_bitmap(new Bitmap("img/fantasma_foge.bmp", pos_inicial->X()));
	animacao_piscando->Inserir_bitmap(new Bitmap("img/fantasma_foge_b.bmp", pos_inicial->X()));
	animacao_piscando->Set_centralizado(true);
	
	desenho_piscando = animacao_piscando;
	
	// Cria desenho fugindo, quando sobre o efeito da pilula
	desenho_efeito_pilula = new Bitmap("img/fantasma_foge.bmp", pos_inicial->X(), pos_inicial->Y());
	desenho_efeito_pilula->Set_centralizado(true);

	// Cria desenho oculos
	desenho_comido = new Bitmap("img/olho.bmp", pos_inicial->X(), pos_inicial->Y());
	desenho_comido->Set_centralizado(true);

	efeito_pilula = false;
	piscando = false;

}

/* O posicionamento é armazenado apenas no IDesenhavel a ser mostrado.
*/
void Fantasma::Pilula_comida()
{
	if (acao != VOLTANDO)
	{
		desenho_efeito_pilula->Set_pos(desenho->X(), desenho->Y());
		
		desenho = desenho_efeito_pilula;
		efeito_pilula = true;
	}
}

void Fantasma::Pilula_acabando()
{
	if ((acao == SOLTO) && (efeito_pilula))
	{
		desenho_piscando->Set_pos(desenho->X(), desenho->Y());
	
		desenho = desenho_piscando;
	}
}

void Fantasma::Pilula_acabou()
{
	//if ((acao == SOLTO) || (acao == SAINDO) || (acao == PRESO))
	if (acao != VOLTANDO)
	{
		desenho_normal->Set_pos(desenho->X(), desenho->Y());
		desenho = desenho_normal;
		efeito_pilula = false;
	}
}

/*Insere o fantasma na area de prisao*/
void Fantasma::Preparar_prisioneiro()
{
	proxima_esquina = Labirinto::Instancia()->Esquina_inicio_fantasma();

	if (proxima_esquina == 0)
		throw new Excessao("A esquina inicio do fantasma está incorreta, uma vez que não pode se deslocar para sua proxima esquina.");

	acao = PRESO;
	direcao_aleatoria = Direcao::Obter_aleatoriamente(0.2);

	//proxima_esquina = labirinto->Esquina_inicio_fantasma()->Obter_esquina(DirecaoFixa::Direita()->Cod());
	cronometro_prisao.Iniciar();
}

void Fantasma::Sair_da_prisao()
{
	efeito_pilula = false;
	acao = SAINDO;	
	Pilula_acabou();
	
	proxima_esquina = Labirinto::Instancia()->Esquina_inicio_fantasma();
}

void Fantasma::Atualizar_posicao(int tempo_passado_Ms)
{
	// Contagem de tempo
	acumulador_tempo += tempo_passado_Ms;
	int pixels_a_andar = acumulador_tempo / Periodo();
	acumulador_tempo = acumulador_tempo % Periodo();
/*
	if (pixels_a_andar > MAX_SALTO_PIXELS)
	{
		pixels_a_andar = MAX_SALTO_PIXELS;
		acumulador_tempo = 0;
	}
*/
	int incremento_x, incremento_y;

	switch (acao)
	{
		case PRESO:
		

		incremento_x = (int) (direcao_aleatoria->X() * pixels_a_andar);
		incremento_y = (int) (direcao_aleatoria->Y() * pixels_a_andar);
	/*
		if ((abs(incremento_x) < 1) && (abs(incremento_y) < 1))
		{
			// Metodo foi chamado muito rapidamente. faz nada.
			acumulador_tempo = antigo_acumulador_tempo + tempo_passado_Ms;	
			return;
		}	
*/
		desenho->Incrementa_pos(incremento_x, incremento_y); 

		Enquadrar_na_prisao();
		
		cronometro_prisao.Atualizar_leitura();
		if (cronometro_prisao.Leitura_Ms() > tempo_prisao)
			Sair_da_prisao();

		break;

		case ENTRANDO:
#ifdef DEBUG
			if (proxima_esquina != Labirinto::Instancia()->Esquina_inicio_fantasma())
				throw new Excessao("O Fantasma estava entrando e sua proxima_esquina nao estava correta");
#endif
			// Verifica se já entrou
			if (desenho->Pos()->Baixo_de(area_central->Pos_centro()))
			{
				Preparar_prisioneiro();
			}

			// Não tem break porque a logica do caminhamento de entrada eh igual a de saida
		case SAINDO:
#ifdef DEBUG
			if (proxima_esquina != Labirinto::Instancia()->Esquina_inicio_fantasma())
				throw new Excessao("O Fantasma estava saindo e sua proxima_esquina nao estava correta");
#endif

			if (desenho->Pos()->Distancia_horizontal(proxima_esquina->Pos()) < pixels_a_andar)
			{
				desenho->Set_pos_x(proxima_esquina->Pos()->X());
				
				if (acao == SAINDO)
					desenho->Incrementa_pos(0, -1 * pixels_a_andar);
				else if (acao == ENTRANDO)
					desenho->Incrementa_pos(0, pixels_a_andar);

				if ((acao == SAINDO && desenho->Pos()->Cima_de(proxima_esquina->Pos())))				
				{
					acao = SOLTO; 		
				}

			} else
			{
				// Aproxima o fantasma da coluna da saida
				if (desenho->Pos()->Direita_de(proxima_esquina->Pos()))	
					desenho->Incrementa_pos(-1 * pixels_a_andar, 0); 
				else
					desenho->Incrementa_pos(pixels_a_andar, 0); 
			}

		break;

		case VOLTANDO:
			
			if (proxima_esquina->Pos()->Distancia(Labirinto::Instancia()->Esquina_inicio_fantasma()->Pos()) 
			<= pixels_a_andar)
			{
				// Ja chegou em cima da prisao. desce.
				acao = ENTRANDO;
				proxima_esquina = Labirinto::Instancia()->Esquina_inicio_fantasma();
			} else
			{
				ElementoAmbulante::Atualizar_posicao(tempo_passado_Ms);
			}
			break;

		case SOLTO:
			// Quando solto, se comporta normalmente.	
			ElementoAmbulante::Atualizar_posicao(tempo_passado_Ms);
			break;		
	}
}
/*
void Fantasma::Desenhar()
{
	ElementoAmbulante::Desenhar();
}
*/

/* 
Enquadra o fantasma na prisao,
alterando sua direcao de forma que ele nao saia dela.
*/
void Fantasma::Enquadrar_na_prisao()
{
	Posicao * desenho_pos = desenho->Pos();

	if (desenho_pos->Direita_de(area_central->Pos2()))
		direcao_aleatoria->Set_x(-1);

	if (desenho_pos->Esquerda_de(area_central->Pos1()))
		direcao_aleatoria->Set_x(1);
	
	if (desenho_pos->Cima_de(area_central->Pos1()))
		direcao_aleatoria->Set_y(1);
	
	if (desenho_pos->Baixo_de(area_central->Pos2()))
		direcao_aleatoria->Set_y(-1);
}

void Fantasma::Foi_comido()
{
	acao = VOLTANDO;
	
	desenho_comido->Set_pos(desenho->X(), desenho->Y());
	
	desenho = desenho_comido;
}

int Fantasma::Periodo()
{
	if ((acao == VOLTANDO) || (acao == ENTRANDO))
		return FANTASMA_PERIODO_VOLTANDO;

	return efeito_pilula ? FANTASMA_PERIODO_PILULA : FANTASMA_PERIODO;
}

void Fantasma::Comeu_pacman()
{
	ControladorVidas * vidas = ControladorVidas::Instancia();
	vidas->Pacman_foi_comido();
}
