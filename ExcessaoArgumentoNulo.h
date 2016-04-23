#ifndef EXCESSAO_ARGUMENTO_NULO

#define EXCESSAO_ARGUMENTO_NULO

#include "Excessao.h"

class ExcessaoArgumentoNulo: public Excessao
{
	public:
		ExcessaoArgumentoNulo(string argumento, string metodo);
};

#endif


