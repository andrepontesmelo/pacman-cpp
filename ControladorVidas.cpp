#include "ControladorVidas.h"

ControladorVidas * ControladorVidas::instancia = 0;

ControladorVidas::ControladorVidas()
{
	pacman = 0;
	pos = new Posicao(CONTROLADOR_VIDAS_POS_X, CONTROLADOR_VIDAS_POS_Y);

	titulo = new Texto("Vidas", pos->X(), pos->Y(), new Cor(250, 25, 124));
}

ControladorVidas* ControladorVidas::Instancia()
{
	if (instancia == 0)
		instancia = new ControladorVidas();

	return instancia;
}

void ControladorVidas::Pacman_foi_comido()
{
#ifdef DEBUG
	if (pacman == 0)
		throw new ExcessaoReferenciaNula("pacman", "ControladorVidas::Pacman_foi_comido(). Provavelmente o Set_pacman() nao foi feito anteriormente.");
#endif
	Allegro::Instancia()->Esperar(1000);	
	
	pacman->Foi_comido();

	// Salto do pacman para a origem nao pode gerar colisoes
	ControladorColisoes::Instancia()->Zerar();

	// Reinicia os fantasmas
	//ComposicaoFantasma::Instancia()->Reiniciar();

	// Retira as vidas
	vidas.clear();
		
	// Cria novamente
	Criar_vidas();


	if (pacman->Num_vidas() < 0)
	{
		// Fim do jogo!	
		Tela * tela = Tela::Instancia();

		Texto *fim = new Texto("FIM", tela->Largura() / 2, tela->Altura() / 2, 
		new Cor(255, 5, 20));
			
		fim->Set_centralizado(true);	
		fim->Desenhar();
		tela->Atualizar();
		Allegro::Instancia()->Esperar(8000);
		exit(0);
	}
}

void ControladorVidas::Set_pacman(Pacman* pacman)
{
	this->pacman = pacman; 
	Criar_vidas();	
}

void ControladorVidas::Criar_vidas()
{
	for (int v = 0; v < pacman->Num_vidas(); v++)
	{
		vidas.push_back(Criar_vida(v));	
	}
}

BonusVida* ControladorVidas::Criar_vida(int qual)
{
	BonusVida * b = new BonusVida();

	b->Set_pos(CONTROLADOR_VIDAS_POS_X + b->Largura() * 2 * qual, 
		CONTROLADOR_VIDAS_POS_Y + 50);

	return b;
}


void ControladorVidas::Desenhar()
{
	titulo->Desenhar();
	
	vector<BonusVida*>::iterator iterador = vidas.begin();

	for (; iterador < vidas.end(); iterador++)
	{
		(*iterador)->Desenhar();
	}

}
