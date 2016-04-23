#ifndef CRONOMETRO_H
#define CRONOMETRO_H
#include <sys/time.h>
//#include <sys/resource.h>
#define UM_MILHAO 1000000

class Cronometro
{
	public:
		Cronometro() {}
		void Iniciar();
		void Atualizar_leitura();
		int Leitura_Ms();
	private:
		struct timeval inicio, fim;

};
#endif
