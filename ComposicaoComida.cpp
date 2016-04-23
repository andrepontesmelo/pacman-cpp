#include "ComposicaoComida.h"

ComposicaoComida::ComposicaoComida()
{
	comidas_restantes = 0;
	Reconstrucao::Instancia()->Adicionar_observador(this);
}

void ComposicaoComida::Adicionar(Comida* comida)
{
	comidas.push_back(comida);
	comida->Adicionar_observador(this);
	comidas_restantes++;
}

void ComposicaoComida::Desenhar()
{
	vector<Comida*>::iterator iterador = comidas.begin();

	for (; iterador < comidas.end(); iterador++)
		(*iterador)->Desenhar();
}

void ComposicaoComida::Atualiza(int acao)
{
	switch (acao)
	{
		case Reconstrucao::NOVA_FASE:
			Repor();
		break;
			
		case Reconstrucao::PACMAN_MORREU:
		break;

		case Reconstrucao::COMIDA_COMIDA:
			comidas_restantes--;

			if (comidas_restantes == 0)
			{
				// Passou de fase!
				Allegro::Instancia()->Esperar(3000);
				Reconstrucao::Instancia()->Nova_fase();
			}
		break;		
	}
}

/* Volta com as comidas */
void ComposicaoComida::Repor()
{
	vector<Comida*>::iterator iterador = comidas.begin();

	for (; iterador < comidas.end(); iterador++)
		(*iterador)->Repor();

	comidas_restantes = comidas.size();
}
