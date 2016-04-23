#include "Aproximador.h"

Aproximador::Aproximador(Posicao * pos_alvo, ElementoAmbulante * perseguidor) 
{
	this->pos_alvo = pos_alvo;
	this->perseguidor = perseguidor;
}


bool Aproximador::Validar_proxima_direcao(DirecaoFixa * d)
{
	return pos_alvo->Maior_que(perseguidor->Pos(), d)	&& (perseguidor->Proxima_esquina()->Obter_esquina(d->Cod()) != 0);
}

/*
	Direcao valida que o perseguidor pode tomar
	para se afatar do alvo
*/
DirecaoFixa * Aproximador::Direcao_afastamento()
{
	DirecaoFixa * aproximar = Direcao_aproximacao();
	DirecaoFixa * oposto = aproximar->Oposto();
	
	if (perseguidor->Proxima_esquina()->Obter_esquina(oposto->Cod()) != 0)
		return oposto;
	else
	{
		// Aleatoriamente escolhe qualquer direcao
		return perseguidor->Proxima_esquina()->Direcao_para_qualquer_esquina_vizinha();
	}
}
