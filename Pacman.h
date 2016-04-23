#ifndef PACMAN_H
class Pacman;
#define PACMAN_H

#include "ElementoAmbulante.h"
#include "Bitmap.h"
#include "Teclado.h"
#include "DirecaoFixa.h"
#include "IDesenhavel.h"
#include "Reconstrucao.h"
#include "IObservador.h"

class Pacman : public ElementoAmbulante, public IObservador
{
	private:
		int num_vidas;
		DirecaoFixa * proxima_direcao;
		// 4 IDesenhaveis, um para cada lado.
		IDesenhavel* desenhos_girados[4];
		void Abrir_desenhos();
		void Inicializar();

	protected:
		virtual DirecaoFixa* Proxima_direcao() { return proxima_direcao; }
		virtual void Girar();
		virtual int Periodo() { return PACMAN_PERIODO; }

	public:
		Pacman();
		~Pacman() {};
		void virtual Atualizar_posicao(int tempo_passado_Ms);
		void virtual Desenhar();
		int Num_vidas() { return num_vidas; }
		void virtual Foi_comido();
		void virtual Atualiza(int acao);

};
#endif
