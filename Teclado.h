#ifndef TECLADO_H 
#include "Assunto.h"
#include "Allegro.h"
#include <iostream>
using std::cout;
#define TECLADO_H

class Teclado : public Assunto
{
	public:
		enum Tecla {ESC, ESQUERDA, DIREITA, CIMA, BAIXO, NADA};
		enum Tecla Tecla_pressionada();
		static Teclado * Instancia();
		void Pausa(); 	// Espera o usuario pressionar alguma tecla.
			
	private:
		Teclado();
		static Teclado* instancia;
		enum Tecla ultima_tecla;
};

#endif
