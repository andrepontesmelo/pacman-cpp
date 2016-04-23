#ifndef TELA_H
#include "IDesenhavel.h"
#include "Allegro.h"
#include "Cor.h"
#define TELA_H

class Tela
{
	public:
		static Tela* Instancia();
		int Largura();
		int Altura();
		void Desenhar(BITMAP * bitmap, int x, int y);	// Desenha no buffer
		void Desenhar_texto(string texto, int x, int y, Cor * cor, bool centralizado);

		void Atualizar();			// Desenha o buffer na tela

	private:
		Tela(int largura, int altura);
		static Tela* instancia;			// Singleton
		BITMAP* buffer;
		int largura;
		int altura;
};	

#endif
