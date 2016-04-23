/* É um objeto que é observado pelas entidades que podem ser reconstruídas, como
as pilulas, os fantasmas, o pacman e as comidas.
*/

#ifndef RECONSTRUCAO_H
#define RECONSTRUCAO_H
#include "Assunto.h"

class Reconstrucao : public Assunto
{
	private:
		static Reconstrucao * instancia;
		Reconstrucao();

	public:
		static Reconstrucao* Instancia();
		enum Acao { PACMAN_MORREU, NOVA_FASE, COMIDA_COMIDA };
		
		// Deve ser chamado apenas pelo proprio pacman
		void Pacman_morreu();
		
		// Deve ser chamado pelo ComposicaoComida assim que acabarem as comidas
		void Nova_fase();
		
		// Comida foi comida. Deve ser chamado por comida.
		void Comida_comida();
};

#endif
