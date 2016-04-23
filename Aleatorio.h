/*
Util para geração de números aleatórios.
Padrão singleton, gera a semente conforme tempo no momento da instanciação.
*/
#ifndef ALEATORIO_H
#include <cstdlib>
#include <ctime>
#define ALEATORIO_H

class Aleatorio
{
	public:
		static Aleatorio* Instancia();
		
		// Pode ser 0, 1, 2 ... max-1 
		int Gerar(int max);
		
		// Sim ou não
		bool GerarBool(); 
		
		// -1 ... 1 
		double Gerar();
	
	private:
		static Aleatorio* instancia;
		Aleatorio();
};

#endif
