#include "Direcao.h"

string Direcao::String()
{
	stringstream resposta;	
	resposta << "X: " << x << " Y: " << y << " ";

	return resposta.str();
}

Direcao* Direcao::Obter_aleatoriamente(double modulo_minimo)
{
	Direcao *nova = new Direcao();
	nova->Setar_aleatoriamente(modulo_minimo);

	return nova;
}

void Direcao::Setar_aleatoriamente(double modulo_minimo)
{
	Aleatorio * aleatorio = Aleatorio::Instancia();

	x = 0; y = 0;

	while(fabs(x) < modulo_minimo)
		x = aleatorio->Gerar();
	
 	while(fabs(y) < modulo_minimo)
		y = aleatorio->Gerar();
}
