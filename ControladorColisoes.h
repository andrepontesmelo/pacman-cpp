#ifndef CONTROLADORCOLISOES
#define CONTROLADORCOLISOES
#include "ExcessaoReferenciaNula.h"
#include "IColidivel.h"
#include "Params.h"
#include "ControladorColisoes.h"

#include <vector>

class ControladorColisoes
{
	public:
		void Verificar_colisoes();
		void Adicionar(IColidivel *objeto);
		static ControladorColisoes* Instancia();
		void Set_pacman(IColidivel *p) { pacman = p; }
		
		// Zera a referencia da ultima posicao do pacman.  
		// Util quando este faz saltos, como quando é comido.
		void Zerar();

	private:
		ControladorColisoes() 
		{ ultima_pos_pacman = 0; pos_grande = new Posicao(); }

		std::vector<IColidivel*> colidiveis;
		bool Verificar_colisao(IColidivel*);
		IColidivel * pacman;
		static ControladorColisoes *instancia;
		Posicao * ultima_pos_pacman;
		
		// Figura grande eh aquela formada pela uniao do pacman na pos. anterior U atual.
		int largura_grande, altura_grande;
		Posicao * pos_grande;
};

#endif
