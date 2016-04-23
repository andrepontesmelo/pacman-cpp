#include "ColecaoEsquinas.h"

Esquina * ColecaoEsquinas::Obter_acima(Esquina* esquina)
{
	// A esquina de menor distancia e sua distancia:
	Esquina * esquina_mais_perto = 0;
	int menor_distancia = LARGURA_TELA; // Inicializacao com maior distancia possivel
	Posicao * esquina_pos = esquina->Pos();

	std::vector<Esquina*>::iterator iterador = vetor.begin();
	
	for (; iterador < vetor.end(); iterador++)
	{
		Esquina * c = (*iterador);
		Posicao * c_pos = c->Pos();		

		int dist = esquina_pos->Distancia(c_pos);

		// Se for zero é a propria esquina!
		if ((dist != 0) && (dist < menor_distancia) && (esquina_pos->Mesma_coluna(c_pos)))
		{
			// Encontrei menor distancia
			menor_distancia = dist;
			esquina_mais_perto = c;
		}
	}

	return esquina_mais_perto; 
}


/* 
	Registra a esquina no vetor, e associa suas esquinas.

	Faz parte do esquema de leitura do arquivo transitavel.
	É chamado por Carregar_transitavel() do tabuleiro
*/
void ColecaoEsquinas::Registrar_esquina(Esquina *esquina, Esquina *esq_esquerda, Esquina * esq_cima)
{
#ifdef DEBUG
	if (esquina == 0)
		throw new ExcessaoArgumentoNulo("esquina", "Labirinto::Registrar_esquina(...)");
#endif

	// Arqui temos nova par linha, coluna para ser inserido.
	Adicionar(esquina);

	// Define referencia para esquerda
	if (esq_esquerda != 0)
	{
		esq_esquerda->Setar_esquina(DirecaoFixa::Direita()->Cod(), esquina, true);
		esquina->Setar_esquina(DirecaoFixa::Esquerda()->Cod(), esq_esquerda, true);
	}

	// Define referencia para cima
	if (esq_cima != 0)
	{
		esq_cima->Setar_esquina(DirecaoFixa::Baixo()->Cod(), esquina, true);
		esquina->Setar_esquina(DirecaoFixa::Cima()->Cod(), esq_cima, true);
	}
}
