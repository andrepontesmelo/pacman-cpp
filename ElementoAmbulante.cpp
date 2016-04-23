#include "ElementoAmbulante.h"

void ElementoAmbulante::Inicializar()
{
	acumulador_tempo = 0;
}

ElementoAmbulante::ElementoAmbulante()
{
	direcao = DirecaoFixa::Esquerda();
	Inicializar();
}

ElementoAmbulante::ElementoAmbulante(DirecaoFixa * direcao_reta_inicial)
{
	direcao = direcao_reta_inicial;
	Inicializar();
}

void ElementoAmbulante::Atualizar_posicao(int tempo_passado_Ms)
{
	// Obtem a possivel proxima direcao conforme especifidade do objeto
	DirecaoFixa * proxima_direcao = Proxima_direcao();
	
	// Contagem de tempo
	tempo_passado_Ms += acumulador_tempo;
	int pixels_a_andar = tempo_passado_Ms / Periodo();
	acumulador_tempo = tempo_passado_Ms % Periodo();
	/*
	if (pixels_a_andar > MAX_SALTO_PIXELS)
	{
		pixels_a_andar = MAX_SALTO_PIXELS;
		acumulador_tempo = 0;
	}
*/

#ifdef DEBUG
	if (proxima_esquina == 0)
		throw new ExcessaoReferenciaNula("proxima_esquina", "ElementoAmbulante::Atualizar_posicao()");
#endif	

	bool ja_passou = desenho->Pos()->Maior_que(proxima_esquina->Pos(), direcao);
	bool nao_passou = !ja_passou;
	bool quase_passando = desenho->Pos()->Distancia(proxima_esquina->Pos()) < pixels_a_andar;

	// Verifica se ja passou da proxima esquina, faz a conversao ou para ou continua.
	if (ja_passou || (nao_passou && quase_passando))
	{
		if (proxima_esquina->Obter_esquina(proxima_direcao->Cod()) != 0)
		{
			// Possivel ir na direcao "proxima_direcao" na esquina "proxima_esquina"
			// Posiciona o elemento corretamente:
			desenho->Set_pos(proxima_esquina->Pos()->X(), proxima_esquina->Pos()->Y());

			// Faz a conversao:
			proxima_esquina = proxima_esquina->Obter_esquina(proxima_direcao->Cod());
			direcao = proxima_direcao;
			parado = false;
			Girar();
		}
		else if (proxima_esquina->Obter_esquina(direcao->Cod()) != 0)
		{	
			// Possivel ir na direcao_reta "direcao_reta" na esquina "proxima_esquina"
			proxima_esquina = proxima_esquina->Obter_esquina(direcao->Cod());
			parado = false;
		}
		else
		{
			// Pacman esta preso em um canto
			desenho->Set_pos(proxima_esquina->Pos()->X(), proxima_esquina->Pos()->Y());
			parado = true;	
		}
	}

	if (!parado)
	{
/*		cout << "Direcao: " << direcao->String() << " pixels: " << pixels_a_andar << "\n";
		cout << "Inc(y) = " << (int) (direcao->X() * pixels_a_andar) << "\n";
		cout << "Inc(y) = " << (int) (direcao->Y() * pixels_a_andar) << "\n";
*/
		desenho->Incrementa_pos((int) (direcao->X() * pixels_a_andar), (int) (direcao->Y() * pixels_a_andar));
	} 
}

void ElementoAmbulante::Desenhar() 
{
	ElementoRepresentavel::Desenhar();
}

void ElementoAmbulante::Descobrir_proxima_esquina()
{
	Esquina * proxima = proxima_esquina->Obter_esquina(direcao->Cod());

	if (proxima != 0)
		proxima_esquina = proxima;
	else
		exit(58); // Corrigir
}
	
