#ifndef TABULEIRO_H
#define TABULEIRO_H
#include <fstream>
#include <string>

#include "Params.h" 	// Está a definição do arquivo do labirinto bmp
#include "Bitmap.h"
#include "DirecaoFixa.h"
#include "Esquina.h"
#include "ElementoRepresentavel.h"
#include "Caixa.h"

// Excessoes
#include "ExcessaoArquivoNaoEncontrado.h"
#include "ExcessaoArgumentoNulo.h"
#include "Excessao.h"

#include "ComposicaoComida.h"
#include "ComposicaoPilula.h"
#include "ColecaoEsquinas.h"


using std::ios;
using std::ifstream;
using std::string;
using std::stringstream;

//using namespace std;

class Labirinto : public ElementoRepresentavel
{
	private:
		static Labirinto* instancia;
//		Esquina *** vetorPontoEsquina;
		Bitmap * bitmap;
		Labirinto();
		void Carregar_transitavel();
		ColecaoEsquinas *  esquinas;
		void Registrar_esquina(Esquina *esquina, Esquina *suaEsquerda);
		void Gerar_comidas(Esquina *a, Esquina *b);

		ComposicaoComida * comidas;

		Esquina * esquina_inicio_pacman;
		Esquina * esquina_inicio_fantasma;

		// Caixa que define a prisao
		Caixa * area_central;

	public:
		static Labirinto * Instancia();
		void Desenhar();
		Esquina * Esquina_inicio_pacman();
		Esquina * Esquina_inicio_fantasma(); 	// Esquina logo acima da caixa central
		
		Caixa * Area_central();
};

#endif
