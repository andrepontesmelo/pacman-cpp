#include "Caixa.h"

Caixa::Caixa(int pos_esq_superior_x, int pos_esq_superior_y,
				int pos_dir_inferior_x, int pos_dir_inferior_y)
{
	pos1 = new Posicao(pos_esq_superior_x, pos_esq_superior_y);
	pos2 = new Posicao(pos_dir_inferior_x, pos_dir_inferior_y);

	pos_centro = 0;
}

Posicao* Caixa::Pos_centro()
{
	if (pos_centro == 0)
		pos_centro = Gerar_pos_centro();

	return pos_centro;
}

Posicao* Caixa::Gerar_pos_centro()
{
	
	return new Posicao((pos2->X() + pos1->X()) / 2, (pos2->Y() + pos1->Y()) / 2);
}
