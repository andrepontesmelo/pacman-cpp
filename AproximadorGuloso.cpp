#include "AproximadorGuloso.h"

AproximadorGuloso::AproximadorGuloso(Posicao * pos_alvo, ElementoAmbulante * perseguidor) 
: Aproximador(pos_alvo, perseguidor)
{
}

DirecaoFixa * AproximadorGuloso::Direcao_aproximacao()
{

	if (Aleatorio::Instancia()->Gerar(1) == 1)
	{
//		cout << "Investindo Esquerda-Direita " << a++ << "\n";
		if (Validar_proxima_direcao(DirecaoFixa::Esquerda()))
			return DirecaoFixa::Esquerda();
	
		if (Validar_proxima_direcao(DirecaoFixa::Direita()))
			return DirecaoFixa::Direita();

	} else 
	{
		//cout << "Investindo Cima_baixo " << b++ << "\n";
		if (Validar_proxima_direcao(DirecaoFixa::Cima()))
			return DirecaoFixa::Cima();
	
		if (Validar_proxima_direcao(DirecaoFixa::Baixo()))
			return DirecaoFixa::Baixo();		
	
		return DirecaoFixa::Direita();

	}

	// O fantasma guloso encontra-se preso. Vá aleatoriamente.
	return perseguidor->Proxima_esquina()->Direcao_para_qualquer_esquina_vizinha();
}

