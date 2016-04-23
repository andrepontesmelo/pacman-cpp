#ifndef ELEMENTOREPRESENTAVEL
#define ELEMENTOREPRESENTAVEL

#include "IColidivel.h"
#include "Posicao.h"
#include "ExcessaoReferenciaNula.h"
#include "Params.h"

class ElementoRepresentavel : public IColidivel
{
	public:
		ElementoRepresentavel(IDesenhavel *desenho);

		// Interface IDesenhavel:
		void virtual Desenhar();
		int X();
		int Y();
		void Set_pos(int x, int y);
		int Largura(); int Altura();
		Posicao * Pos() { return desenho->Pos(); }
		void Set_centralizado(bool c) { desenho->Set_centralizado(c); }
		virtual bool Comivel_pelo_pacman() { return false; }
		virtual bool Visivel() { return visivel; }
		virtual void Foi_comido() { visivel = false; }
		virtual ~ElementoRepresentavel() {}	
	protected:
		// Esta construtora sem o desenho pode ser chamada pelas filhas, mas o desenho deve ser setado depois
		ElementoRepresentavel();		
		IDesenhavel *desenho;
		bool visivel;

		// Inicializar() Nao eh virtual porque vtable nao está pronta antes do fim da construtora.
		void Inicializar();

	private:
		
};

#endif
