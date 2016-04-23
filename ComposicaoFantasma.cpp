#include "ComposicaoFantasma.h"

ComposicaoFantasma * ComposicaoFantasma::instancia = 0;

void ComposicaoFantasma::Atualiza(int acao)
{
	// Dispara mensagem para todos
	vector<IFantasma*>::iterator iterador;
	for (iterador = fantasmas.begin(); iterador < fantasmas.end(); iterador++)
		(*iterador)->Atualiza(acao);

	switch (acao)
	{
		case Reconstrucao::NOVA_FASE:
			fantasmas.push_back(new FantasmaGuloso(TEMPO_MIN_PRESO + INTERVALO_PRESO * fantasmas.size(), pos_pacman));
		
		break;
	}
}

ComposicaoFantasma::ComposicaoFantasma()
{
	pos_pacman = 0;
	estagio_pilula = DESATIVADA;

	// Registra si mesmo no Reconstrucao para obter observacao
	Reconstrucao::Instancia()->Adicionar_observador(this);
}

void ComposicaoFantasma::Gerar_fantasmas(Pacman * pacman)
{
	if (pos_pacman != 0)
		throw new Excessao("Gerar_fantasmas chamado mais de uma vez na composicao de fantasmas.");
	
	pos_pacman = pacman->Pos();

	if (pos_pacman == 0)
		throw new ExcessaoReferenciaNula("pos_pacman", "ComposicaoFantasma::Gerar_fantasmas()");

	fantasmas.push_back(new FantasmaGuloso(TEMPO_MIN_PRESO + INTERVALO_PRESO * 0, pos_pacman));

	fantasmas.push_back(new FantasmaAleatorio(TEMPO_MIN_PRESO + INTERVALO_PRESO * 1));
	
	fantasmas.push_back(new FantasmaGuloso(TEMPO_MIN_PRESO + INTERVALO_PRESO * 2, pos_pacman));
	
	fantasmas.push_back(new FantasmaAleatorio(TEMPO_MIN_PRESO + INTERVALO_PRESO * 3));
}

void ComposicaoFantasma::Desenhar()
{
	vector<IFantasma*>::iterator iterador;
	for (iterador = fantasmas.begin(); iterador < fantasmas.end(); iterador++)
		(*iterador)->Desenhar();
	
	switch (estagio_pilula)
	{
		case ATIVADA:
			crono_efeito_pilula.Atualizar_leitura();
			if (crono_efeito_pilula.Leitura_Ms() > PILULA_DURACAO)
			{
				for (iterador = fantasmas.begin(); iterador < fantasmas.end(); iterador++)
					(*iterador)->Pilula_acabando();

				estagio_pilula = ACABANDO;
				crono_fim_pilula.Iniciar();
			}
			break;
		case ACABANDO:
			crono_fim_pilula.Atualizar_leitura();
			if (crono_fim_pilula.Leitura_Ms() > PILULA_DURACAO_ACABANDO)
			{
				for (iterador = fantasmas.begin(); iterador < fantasmas.end(); iterador++)
					(*iterador)->Pilula_acabou();

				estagio_pilula = DESATIVADA;
			}
			break;
		case DESATIVADA:
			break;
	}
}

void ComposicaoFantasma::Atualizar_posicao(int tempo)
{
	vector<IFantasma*>::iterator iterador;
	for (iterador = fantasmas.begin(); iterador < fantasmas.end(); iterador++)
		(*iterador)->Atualizar_posicao(tempo);
}

void ComposicaoFantasma::Pilula_comida()
{
	vector<IFantasma*>::iterator iterador;
	for (iterador = fantasmas.begin(); iterador < fantasmas.end(); iterador++)
		(*iterador)->Pilula_comida();
	
	estagio_pilula = ATIVADA;
	crono_efeito_pilula.Iniciar();
}

ComposicaoFantasma* ComposicaoFantasma::Instancia()
{
	if (instancia == 0)
		instancia = new ComposicaoFantasma();

	return instancia;
}


