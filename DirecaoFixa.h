#ifndef DIRECAO_FIXA_H
#define DIRECAO_FIXA_H
#include "Direcao.h"
#include "Excessao.h"
#include "ExcessaoReferenciaNula.h"
#include <string>
#include <sstream>

#include "Params.h"

using std::stringstream;
using std::string;

class DirecaoFixa : public Direcao
{
	public:
		static DirecaoFixa* Cima() { return cima; }
		static DirecaoFixa* Baixo() { return baixo; }
		static DirecaoFixa* Esquerda() { return esquerda; }
		static DirecaoFixa* Direita() { return direita; }

		static DirecaoFixa* Obter_pelo_codigo(int cod);
		//static DirecaoFixa* Obter_seguindo(Posicao* pos);

		int Cod() { return cod; }
		string Sigla() { return sigla; }
		DirecaoFixa* Oposto();

		virtual void Setar_aleatoriamente(double modulo_minimo)
			{ throw new Excessao("Tentativa de alterar DirecaoFixa em Setar_aleatoriamente()"); }
		virtual void Inverte_x()
			{ throw new Excessao("Tentativa de alterar DirecaoFixa em Inverte_x()"); }
		virtual void Inverte_y()
			{ throw new Excessao("Tentativa de alterar DirecaoFixa em Inverte_y()"); }
		virtual void Set_x(float x)
			{ throw new Excessao("Tentativa de alterar DirecaoFixa em Set_x()"); }
		virtual void Set_y(float y)
			{ throw new Excessao("Tentativa de alterar DirecaoFixa em Set_y()"); }
	
	private:
		static DirecaoFixa* cima;
		static DirecaoFixa* baixo;
		static DirecaoFixa* esquerda;
		static DirecaoFixa* direita;
		
		// Codigo da direcao fixa
		int cod;
		DirecaoFixa* oposto;
		string sigla;
		void Set_oposto(DirecaoFixa * oposto) { this->oposto = oposto; }
		

		// Opostos sao setados uma vez so, em Oposto()
		static bool opostos_setados;
		static void Setar_opostos();

		DirecaoFixa(int cod, float x, float y, string sigla) : Direcao(x, y) 
		{ this->cod = cod; oposto = 0; this->sigla = sigla; }
		
		enum COD { CIMA, BAIXO, ESQUERDA, DIREITA };

};

#endif
