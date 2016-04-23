#ifndef ANIMACAO_H
#define ANIMACAO_H
#include <string>
#include <vector>

#include "IDesenhavel.h"
#include "Cronometro.h"
#include "ExcessaoReferenciaNula.h"
#include "Excessao.h"
#include "Bitmap.h"
#include "Params.h"

using std::string;
using std::stringstream;

class Animacao : public IDesenhavel
{
	public:
		Animacao(int tempo); 
		void Inserir_bitmap(Bitmap *bmp);
		void Desenhar();
			
//		int virtual X();
//		int virtual Y();
		bool virtual Visivel() { return true; }
		void virtual Set_centralizado(bool c);
		void Set_pos(int x, int y);
		Posicao* Pos();
		int Largura();
		int Altura();
	
	private:
		// Tempo entre a troca de bitmaps.
		int tempo_Ms;
		
		// Colecao de bitmaps
		std::vector <Bitmap*> bitmaps;
		
		// Aponta para o item a ser mostrado atualmente
		std::vector<Bitmap*>::iterator iterador;

		// Prepara inicio da animacao		
		void Preparar();		
		
		// Controle de tempo
		Cronometro cronometro;
		
		// Verifica e dispara excessao caso animação seja vazia de bitmaps
		void Confirmar_existencia_bitmaps(string modulo);

		// Ponteiro para primeiro elemento da animação
		Bitmap * Primeiro_bitmap();
};

#endif

