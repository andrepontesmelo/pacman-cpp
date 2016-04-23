#ifndef COMIDA_H
class Comida;
#define COMIDA_H

#include "Posicao.h"
#include "ElementoRepresentavel.h"
#include "ExcessaoReferenciaNula.h"
#include "Cor.h"
#include "Bitmap.h"
#include "Params.h"
#include "ControladorColisoes.h"
#include "Reconstrucao.h"

class Comida : public ElementoRepresentavel, public Assunto
{
	private:
		Posicao * posicao;
		Bitmap * Criar_bitmap(Posicao * posicao);
		void Inicializar(Posicao * posicao);

	public:
		Comida(Posicao * posicao);
		Comida(int x, int y);
		virtual ~Comida(){}
		Posicao * Pos() { return posicao; }
		virtual bool Comivel_pelo_pacman() { return true; }
		virtual void Foi_comido();
		void Repor() { visivel = true; }
};

#endif
