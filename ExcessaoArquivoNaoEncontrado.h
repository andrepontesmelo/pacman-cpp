#ifndef EXCESSAO_ARQUIVO_NAO_ENCONTRADO_H
#include "Excessao.h"
#define EXCESSAO_ARQUIVO_NAO_ENCONTRADO_H

class ExcessaoArquivoNaoEncontrado : public Excessao
{
	public:
		ExcessaoArquivoNaoEncontrado(string arq);
};

#endif


