/*
Um bitmap pode ser construido apartir de um arquivo BMP, 
ou então pode ser criado um vazio. O propio Bitmap armazena informações
sobre seu posicionamento na tela, repondendo ao método Desenha(), 
da interface IDesenhavel
*/

#ifndef BITMAP_H
#include "Allegro.h"
#include "IDesenhavel.h"
#include "ExcessaoArquivoNaoEncontrado.h"
#include "ExcessaoArgumentoNulo.h"
#include "ExcessaoReferenciaNula.h"
#include "Posicao.h"
#include "Cor.h"
#include "Tela.h"
#include <string>
#include "Params.h"
#define BITMAP_H

class Bitmap : public IDesenhavel
{
	private:
		BITMAP *bmp;
		Posicao *posicao;
		int largura, altura;
		bool centralizado;
		Tela * instancia_tela;
		void Inicializa(BITMAP * bitmap, Posicao * pos);
	
	public:

		// Propriedades
		int Largura() { return largura; }
		int Altura()  { return altura; }
//		int X();
//		int Y();
		void Set_pos(int x, int y);
		Posicao * Pos() { return posicao; }
		void Set_centralizado(bool c) { centralizado = c; }
		bool Visivel() { return true; }
		// Abre de um arquivo bitmap
		Bitmap(string arquivo, int x = 0, int y = 0);

		// Gera novo bitmap em branco
		Bitmap(int largura, int altura, int x = 0, int y = 0);

		virtual ~Bitmap();

		void Colidiu(IDesenhavel * outro);
		BITMAP* Bmp() { return bmp; }
		void Limpar();
		void Desenhar_circulo_preenchido(int x, int y, int raio, Cor * cor);
		void Desenhar_linha(int x, int y, int x1, int y1, Cor * cor);
		void Desenhar();
		
};

#endif

