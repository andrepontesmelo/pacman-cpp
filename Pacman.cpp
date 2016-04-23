#include "Pacman.h"

void Pacman::Inicializar()
{
	Esquina * esquina_inicial = Labirinto::Instancia()->Esquina_inicio_pacman();
	proxima_direcao = DirecaoFixa::Direita();
	this->desenho = desenhos_girados[proxima_direcao->Cod()];	

	desenho->Set_pos(Labirinto::Instancia()->Esquina_inicio_pacman()->Pos()->X(), Labirinto::Instancia()->Esquina_inicio_pacman()->Pos()->Y());

	proxima_esquina = esquina_inicial->Obter_esquina(proxima_direcao->Cod());
}

Pacman::Pacman()
{
	Abrir_desenhos();

	// Abre a quantidade de vidas
	num_vidas = PACMAN_QTD_VIDAS_INCIAL;

	Inicializar();	
	desenho->Set_centralizado(true);
	
	if (proxima_esquina == 0)
		throw new Excessao("A esquina inicio do pacman está incorreta, uma vez que não pode se deslocar para sua proxima esquina.");

	// Adiciona a si proprio nos elementos reconstruiveis
	Reconstrucao::Instancia()->Adicionar_observador(this);
}


void Pacman::Abrir_desenhos()
{
	Animacao * ani;
	stringstream nome_arq;
	Posicao * pos_inicial = Labirinto::Instancia()->Esquina_inicio_pacman()->Pos();
	IDesenhavel * primeiro = 0;
	IDesenhavel * ultimo_criado = 0;
	

	for (int direcao_nr = 0; direcao_nr < 4; direcao_nr++)
	{
		// Cada uma das 4 direcoes
		DirecaoFixa * direcao_atual = DirecaoFixa::Obter_pelo_codigo(direcao_nr);

		// Gera nova animacao para cada direcao
		ani = new Animacao(PACMAN_PERIODO_BOCA);

		// Cada direcao tem uma sigla
		string sigla_direcao = direcao_atual->Sigla();
	
		for (int x = 0; x <= 4; x++)
		{
			nome_arq.str("");
			nome_arq << "img/pacman" << x << "_" << sigla_direcao << ".bmp";

			ani->Inserir_bitmap(new Bitmap(nome_arq.str(), pos_inicial->X(), pos_inicial->Y()));
		}

		for (int x = 3; x >= 1; x--)
		{
			nome_arq.str("");
			nome_arq << "img/pacman" << x << "_" << sigla_direcao << ".bmp";

			ani->Inserir_bitmap(new Bitmap(nome_arq.str(), pos_inicial->X(), pos_inicial->Y()));
		}

		// Toda animacao de pacman eh centralizada
		ani->Set_centralizado(true);

		// Grava no pacman a animacao
		desenhos_girados[direcao_atual->Cod()] = ani;

		// Uma animacao imita a outra em posicao
		if (ultimo_criado == 0)
		{
			//primeiro!
			primeiro = ani;
		} else
		{
			ani->Set_imitador_posicao(ultimo_criado);
		}
		
		ultimo_criado = ani;	

	} // For 4 direcoes

	//ultimo_criado->Set_imitador_posicao(primeiro);
	primeiro->Set_imitador_posicao(ultimo_criado);
}

void Pacman::Girar()
{
//	IDesenhavel * atual = desenho;
	IDesenhavel * proximo = desenhos_girados[proxima_direcao->Cod()];

//	proximo->Set_pos(atual->X(), atual->Y());
	
	this->desenho = proximo;
}


void Pacman::Atualizar_posicao(int tempo_passado_Ms)
{
	switch (Teclado::Instancia()->Tecla_pressionada())
	{
		case Teclado::BAIXO:
			proxima_direcao = DirecaoFixa::Baixo();
			break;

		case Teclado::ESQUERDA:
			proxima_direcao = DirecaoFixa::Esquerda();
			break;

		case Teclado::DIREITA:
			proxima_direcao = DirecaoFixa::Direita();
			break;

		case Teclado::CIMA:
			proxima_direcao = DirecaoFixa::Cima();
			break;

		default:
			break;
	}

	//cout << "Direcao Atual: " << direcao->String() << " Direcao Pressionada: " << proxima_direcao->String() << "\n";
	
	//cout << "Oposto a direcao: " << direcao->Oposto() << "   &Pressionada: " << proxima_direcao << "\n";
	
	if (direcao->Oposto() == proxima_direcao)
	{
		// Muda de diracao para a oposta
		proxima_esquina = proxima_esquina->Obter_esquina(proxima_direcao->Cod());
		direcao = proxima_direcao;
		parado = false;
		Girar();
	}

	ElementoAmbulante::Atualizar_posicao(tempo_passado_Ms);
}

void Pacman::Desenhar()
{
	ElementoAmbulante::Desenhar();
}

void Pacman::Foi_comido()
{
	num_vidas--;

	// Informa aos reconstruiveis
	Reconstrucao::Instancia()->Pacman_morreu();
}

void Pacman::Atualiza(int acao)
{
	switch (acao)
	{
		case Reconstrucao::NOVA_FASE:
		case Reconstrucao::PACMAN_MORREU:
			Inicializar();
		break;
	}
}

