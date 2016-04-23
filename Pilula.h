#ifndef PILULA_H
#define PILULA_H
#include "Bonus.h"
#include "Animacao.h"
#include "Params.h"
#include "IFantasma.h"
#include "ExcessaoReferenciaNula.h"
#include "Reconstrucao.h"

class Pilula : public Bonus
{
	public:
		Pilula(int x, int y);
		virtual void Foi_comido();
		void Set_fantasmas(IFantasma * fantasmas) { this->fantasmas = fantasmas; }
		void Atualiza(int acao);

	private:
		IFantasma * fantasmas;
		Animacao * Construir_animacao(int x, int y);

};

#endif
