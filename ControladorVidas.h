#ifndef CONTROLADOR_VIDAS_H
#define CONTROLADOR_VIDAS_H
#include "Pacman.h"
#include "Params.h"
#include "BonusVida.h"
#include "ExcessaoReferenciaNula.h"
#include "Texto.h"
#include "Posicao.h"
#include "Tela.h"
#include "Allegro.h"
#include <vector>
using std::vector; 

class ControladorVidas : IDesenhavel
{
	private:
		static ControladorVidas * instancia;
		Pacman * pacman;
		Posicao * pos;
		Texto * titulo;
		vector<BonusVida*> vidas;
		void Criar_vidas();
		
	public:
		ControladorVidas();
		static ControladorVidas* Instancia();
		void Pacman_foi_comido();
		void Set_pacman(Pacman* pacman);
		BonusVida* Criar_vida(int qual);

		// Membros de IDesenhavel
		virtual bool Visivel() { return true; }
		virtual void Set_centralizado(bool c) {};
		virtual int Largura() {return 0;}
		virtual int Altura() {return 0;}
		virtual Posicao* Pos() {return pos;}
		virtual void Desenhar();
};

#endif
