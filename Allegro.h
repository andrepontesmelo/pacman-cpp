/*
Classe singleton que adapta a biblioteca grafica Allegro.
*/
#ifndef ALLEGRO_H
#include <iostream>
#include <allegro.h>
#define ALLEGRO_H

class Allegro
{
	private:
		Allegro() {}
		static Allegro* instancia;
		int largura, altura;

	public:
		void Inicializa(int largura, int altura);
		void Finaliza();
		static Allegro* Instancia();
		int Largura() { return largura; }
		int Altura() { return altura; }
		
		// Suspende a thread atual por 'tempo' ms.
		void Esperar(int tempo);
};

#endif
