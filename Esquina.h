#ifndef ESQUINA_H
#define ESQUINA_H

#include "DirecaoFixa.h"
#include "Posicao.h"
#include "ExcessaoArgumentoNulo.h"
#include "Params.h"
#include "Aleatorio.h"

#include <iostream>
class Esquina
{
private:
	Esquina * esquinas[4];
	bool transitaveis[4];	// Indica se cada esquina é transitavel
	Posicao * posicao;
	void Inicializar();

public:
	Esquina(int linha, int coluna);

	Esquina * Obter_esquina(int pos) { 	return esquinas[pos]; }
	
	DirecaoFixa* Direcao_para_qualquer_esquina_vizinha();
	
	void Setar_esquina(int pos, Esquina * novaVizinha, bool transitavel);

	Posicao * Pos() { return posicao; }
};

#endif
