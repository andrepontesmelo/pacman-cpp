#include "Esquina.h"

void Esquina::Inicializar()
{
	// Zera as esquinas.
	for (int x = 0; x < 4; x++)
	{
		esquinas[x] = 0;
		transitaveis[x] = false;
	}
}
/*
Esquina::Esquina(Posicao * posicao)
{
#ifdef DEBUG
	if (posicao == 0)
		throw new ExcessaoArgumentoNulo("posicao", "Esquina::Esquina(Posicao*)");

#endif
	this->posicao = posicao;
	Inicializar();
}
*/
Esquina::Esquina(int linha, int coluna)
{
	posicao = new Posicao(coluna, linha);
	
	Inicializar();	
}

void Esquina::Setar_esquina(int pos, Esquina * novaVizinha, bool transitavel)
{
	esquinas[pos] = novaVizinha;
	transitaveis[pos] = transitavel;

}

DirecaoFixa* Esquina::Direcao_para_qualquer_esquina_vizinha()
{
	int tentativa = Aleatorio::Instancia()->Gerar(3);
	
	while (esquinas[tentativa] == 0)
		tentativa = Aleatorio::Instancia()->Gerar(3);
	
	return DirecaoFixa::Obter_pelo_codigo(tentativa);
}
