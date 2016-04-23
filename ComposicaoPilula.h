#ifndef COMPOSICAO_PILULA
class ComposicaoPilula;
#define COMPOSICAO_PILULA

#include <vector>
#include "Pilula.h"
#include "Cronometro.h"
using std::vector; 


class ComposicaoPilula
{
	public:
	
		void Adicionar(Pilula *pilula);
		void Desenhar();
		void Set_fantasmas (IFantasma * fantasma);
		static ComposicaoPilula* Instancia();
		
	// Repoe pilulas comidas, chamado quando passa de fase.
		void Repor();

	private:
		vector<Pilula*> pilulas;
		ComposicaoPilula() { fantasmas = 0; }	
		IFantasma * fantasmas;
		static ComposicaoPilula* instancia;


};

#endif
