#include "Labirinto.h"

Labirinto * Labirinto::instancia = 0;

Labirinto::Labirinto()
{
	esquinas = new ColecaoEsquinas();

	// Carrega a composicao de comidas;
	comidas = new ComposicaoComida();
	
	// Carrega o tabuleiro.
	desenho = new Bitmap(LABIRINTO_BITMAP_ARQUIVO, 0, 0);
	desenho->Set_centralizado(false);
	// Deve-se descarregar bitmap.
	Carregar_transitavel();

}
void Labirinto::Gerar_comidas(Esquina *a, Esquina *b)
{
	Esquina *menor, *maior;

	int x = 0, y = 0;
	//int incrementa_x, incrementa_y;
	bool mesmaLinha = a->Pos()->Mesma_linha(b->Pos());
	int varInicial, varMax; // var pode ser x ou y, depende de qual varia.

	if (mesmaLinha)
	{
		y = a->Pos()->Y();

		// B está à direita de A  (A -- B)
		if (b->Pos()->Direita_de(a->Pos()))
		{
			menor = a; maior = b;
		} else
		{
			menor = b; maior = a;
		}

		varInicial = menor->Pos()->X();
		varMax = maior->Pos()->X();
	
	} else 
	if (a->Pos()->Mesma_coluna(b->Pos()))
	{
		x = a->Pos()->X();

		if (b->Pos()->Baixo_de(a->Pos()))
		{
			menor = a; maior = b;
		} else
		{
			menor = b; maior = a;
		}
		
		varInicial = menor->Pos()->Y();
		varMax = maior->Pos()->Y();

	} else
			throw new Excessao("Comida nao alinhada!");

	bool primeira = true;
	for (int var = varInicial; var + (DISTANCIA_COMIDAS / 2) <= varMax; var += DISTANCIA_COMIDAS)
	{
		if (mesmaLinha) x = var;
		else y = var;
		
		// Na construcao, apenas desenhar comidas nas esquinas.
		#ifdef  CONSTRUINDO_LABIRINTO
		if (primeira)
		#endif
		comidas->Adicionar(new Comida(x, y));
		primeira = false;
	}
	
	// Na construcao, desenhar tambem a ultima comida.
	comidas->Adicionar(new Comida(maior->Pos()->X(), maior->Pos()->Y()));

#ifdef  CONSTRUINDO_LABIRINTO
	((Bitmap *) desenho)->Desenhar_linha(menor->Pos()->X(), menor->Pos()->Y(), 
	maior->Pos()->X(), maior->Pos()->Y(), 
	new Cor(255, 255, 200));
#endif
}
				
void Labirinto::Desenhar() 
{
	ElementoRepresentavel::Desenhar();
	ComposicaoPilula::Instancia()->Desenhar();

	comidas->Desenhar();
}

void Labirinto::Carregar_transitavel()
{
	ifstream arq;
	arq.open(LABIRINTO_TRANSITAVEL_ARQUIVO, ios::in);

	if (!arq)
		throw new ExcessaoArquivoNaoEncontrado(LABIRINTO_TRANSITAVEL_ARQUIVO);

	// Posicao temporaria para leitura dos pontos
	int linha, coluna;

	// Significa que uma esquina nao tem seu percurso transitavel até a proxima.
	bool barreira_h = false;	// |
	bool barreira_v  = false;	// -
	bool sem_comida_v = false;		// ^
	bool sem_comida_h = false;		// <
	bool esquina_inicio_pacman_agora = false;
	bool esquina_inicio_fantasma_agora = false;
	
	// Identificador: L C
	char identificador;

	// Esquinas proximas
	Esquina * nova_esquina = 0, * esq_esquerda = 0;
	
	string comentario;

	while (arq >> identificador)
	{
		bool lerNovamente = false;

		switch (identificador)
		{
			case ' ':
			case '#':
				arq >> comentario;
				lerNovamente = true;
				break;
			case 'L':
				arq >> linha;

				// Apos ler <L> <num_linha>, deve-se obter a coluna.
				lerNovamente = true;

				// Em uma nova linha, nao ha referencia para esquina à esquerda.
				esq_esquerda = 0;
				break;

			case 'C':
				arq >> coluna;
				break;
			case '|':
				barreira_h = true;
				lerNovamente = true;
				break;
			case '-':
				barreira_v = true;
				lerNovamente = true;
				break;
			case '^':
				sem_comida_v = true;
				lerNovamente = true;
				break;
			case '<':
				sem_comida_h = true;
				lerNovamente = true;
				break;
			case 'P':
				esquina_inicio_pacman_agora = true;
				lerNovamente = true;
				break;
			case 'X':
				esquina_inicio_fantasma_agora = true;
				lerNovamente = true;
				break;
			case 'F':
				int L1, C1, L2, C2;
				arq >> L1;
				arq >> C1;
				
				arq >> L2;
				arq >> C2;
				
				area_central = new Caixa(C1, L1, C2, L2);
				lerNovamente = true;
				break;	
			case 'I':
				int l, c;
				arq >> l;
				arq >> c;
				ComposicaoPilula::Instancia()->Adicionar(new Pilula(c, l));
				lerNovamente = true;
				break;

			default:
				string err = "Erro ao interpretar arquivo transitavel. Identificador:"; 
				throw new Excessao(err + identificador);
				break;
		}
	
		if (!lerNovamente)
		{	
			nova_esquina = new Esquina(linha, coluna);
			Esquina * esq_cima = esquinas->Obter_acima(nova_esquina);
			
			if (esquina_inicio_pacman_agora)
			{
				esquina_inicio_pacman = nova_esquina;
				esquina_inicio_pacman_agora = false;
			} 
			if (esquina_inicio_fantasma_agora)
			{
				esquina_inicio_fantasma = nova_esquina;
				esquina_inicio_fantasma_agora = false;
			}
	
			
			// Caso exista barrira, pode esquecer a ultima esquina
			if (barreira_h) esq_esquerda = 0;
			if (barreira_v) esq_cima = 0;

			// Registra esquina atual.
			esquinas->Registrar_esquina(nova_esquina, esq_esquerda, esq_cima);
	
			if ((esq_esquerda != 0) && (!sem_comida_h))
			Gerar_comidas(nova_esquina, esq_esquerda);

			if ((esq_cima != 0) && (!sem_comida_v))
			Gerar_comidas(nova_esquina, esq_cima);

			// Redefine esquina esquerda para a atual, porque a proxima provavelmente estara a dir. desta
			esq_esquerda = nova_esquina;

			barreira_h = false;
			barreira_v = false;
			sem_comida_v  = false;
			sem_comida_h = false;
		}
	}

	arq.close();

}

Labirinto * Labirinto::Instancia()
{
	if (instancia == 0)
		instancia = new Labirinto();

	return instancia;
}


Esquina * Labirinto::Esquina_inicio_pacman()
{

#ifdef DEBUG
	if (esquina_inicio_pacman == 0)
		throw new ExcessaoArgumentoNulo("esquina_inicio_pacman", "Labirinto::Esquina_inicio_pacman()");
#endif
	return esquina_inicio_pacman;
}

Esquina * Labirinto::Esquina_inicio_fantasma()
{

#ifdef DEBUG
	if (esquina_inicio_fantasma == 0)
		throw new ExcessaoArgumentoNulo("esquina_inicio_fantasma", "Labirinto::Esquina_inicio_fantasma()");
#endif
	return esquina_inicio_fantasma;
}


Caixa * Labirinto::Area_central()
{
#ifdef DEBUG
	if (area_central == 0)
		throw new ExcessaoReferenciaNula("area_central", "Labirinto::Area_central()");
#endif	

	return area_central;
}

