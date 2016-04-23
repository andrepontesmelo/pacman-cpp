#include "Cronometro.h"

void Cronometro::Iniciar()
{
	gettimeofday(&inicio, 0);
}

void Cronometro::Atualizar_leitura()
{
	gettimeofday(&fim, 0);
}

int Cronometro::Leitura_Ms()
{
	// Computa a diferenca de micro segundos
	int leitura_Ms = fim.tv_usec - inicio.tv_usec;

	// Acrescenta a diferenca de segundos
	leitura_Ms += (fim.tv_sec - inicio.tv_sec) * UM_MILHAO;

	return leitura_Ms;
}
