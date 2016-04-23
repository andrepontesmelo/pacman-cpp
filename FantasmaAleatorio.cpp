#include "FantasmaAleatorio.h"

int FantasmaAleatorio::fantasmas_criados = 0;

string FantasmaAleatorio::Nome_alternado()
{
	fantasmas_criados++;

	if (fantasmas_criados%2)
		return "img/f_laranja.bmp";
	else 
		return "img/f_bege.bmp";
}

FantasmaAleatorio::FantasmaAleatorio(int tempo_prisao) : Fantasma(tempo_prisao)
{
	desenho_normal = new Bitmap(Nome_alternado());
	desenho_normal->Set_pos(Labirinto::Instancia()->Esquina_inicio_fantasma()->Pos()->X(), Labirinto::Instancia()->Esquina_inicio_fantasma()->Pos()->Y());

	desenho_normal->Set_centralizado(true);

	desenho = desenho_normal;
}

DirecaoFixa* FantasmaAleatorio::Proxima_direcao()
{
	//proxima_direcao = proxima_esquina->Direcao_para_qualquer_esquina_vizinha();

	//return proxima_direcao;

	return proxima_esquina->Direcao_para_qualquer_esquina_vizinha();
}
