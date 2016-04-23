
#ifndef POSICAO_H
#include "DirecaoFixa.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;
#define POSICAO_H

class Posicao
{
	private:
		int x, y;
	public:
		Posicao();		// Nasce na origem
		Posicao(int x, int y);	// Nascem em x, y
		int X();
		int Y();
		void Set_x(int x_) { x = x_; }
		void Set_y(int y_) { y = y_; }
		int Distancia(Posicao *b);
		int Distancia_horizontal(Posicao *b);
		int Distancia_vertical(Posicao *b);
		static int Distancia(Posicao *a, Posicao *b);
		string String();

		bool Mesma_linha(Posicao *b) { return (y == b->Y()); }
		bool Mesma_coluna(Posicao *b) { return (x == b->X()); }
		bool Direita_de(Posicao *b) { return x > b->X(); }
		bool Baixo_de(Posicao *b)   { return y > b->Y(); }
		bool Cima_de(Posicao *b) { return !Baixo_de(b); }
		bool Esquerda_de(Posicao *b) { return !Direita_de(b); }
/*
		void Inverte_x() { x *= -1; }
		void Inverte_y() { y *= -1; }
	
*/
		bool Maior_que(Posicao *b, DirecaoFixa *d);	
		bool Menor_que(Posicao *b, DirecaoFixa *d) { return !Maior_que(b, d); }
};

#endif

