#ifndef TEXTO_H
#define TEXTO_H
#include "IDesenhavel.h"
#include <string>
#include "Posicao.h"
#include "Tela.h"
#include "Cor.h"

class Texto : public IDesenhavel
{
	private:
		string texto;
		Posicao * pos;
		Cor * cor;		
		bool centralizado;

	public:
		Texto(string texto, int x, int y, Cor * cor);

		virtual void  Set_centralizado(bool c) {centralizado = c;}
		virtual int  Largura() { return 0; }
		virtual int  Altura() { return 0; }
		virtual Posicao* Pos() {return pos; }
		virtual void  Desenhar();
		virtual bool Visivel() { return true; }
};
		
#endif
