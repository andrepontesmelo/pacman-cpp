#include "FantasmaGuloso.h"

int FantasmaGuloso::fantasmas_criados = 0;

string FantasmaGuloso::Nome_alternado()
{
	fantasmas_criados++;

	if (fantasmas_criados%2)
		return "img/f_vermelho.bmp";
	else 
		return "img/f_azul.bmp";
}

FantasmaGuloso::FantasmaGuloso(int tempo_prisao, Posicao * pos_pacman) : Fantasma(tempo_prisao)
{
	aproximador_pacman = new AproximadorGuloso(pos_pacman, this);

	desenho_normal = new Bitmap(Nome_alternado());
	desenho_normal->Set_pos(Labirinto::Instancia()->Esquina_inicio_fantasma()->Pos()->X(), Labirinto::Instancia()->Esquina_inicio_fantasma()->Pos()->Y());

	desenho_normal->Set_centralizado(true);

	desenho = desenho_normal;
}

DirecaoFixa * FantasmaGuloso::Proxima_direcao()
{
	if (acao == VOLTANDO)
	{
		return aproximador_prisao->Direcao_aproximacao();
	} else
	{
		if (efeito_pilula)	
	 		return aproximador_pacman->Direcao_afastamento();
		else
			return aproximador_pacman->Direcao_aproximacao();
	}
}
