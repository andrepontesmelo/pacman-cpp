#ifndef CAIXA_H
#define CAIXA_H
#include "Posicao.h"

class Caixa
{
	public:
		Caixa(int pos_esq_superior_x, int pos_esq_superior_y,
				int pos_dir_inferior_x, int pos_dir_inferior_y);

		Posicao * Pos1() { return pos1; }
		Posicao * Pos2() { return pos2; }

		Posicao * Pos_esq_superior() { return pos1; }
		Posicao * Pos_dir_inferior() { return pos2; }

		// Centro da caixa
		Posicao * Pos_centro();

	private:
		// Posicao dos estremos
		Posicao * pos1, * pos2, * pos_centro;
		Posicao * Gerar_pos_centro();
};

#endif
