#ifndef IDESENHAVEL_H
#include "Posicao.h"

class IDesenhavel
{
	public:
		virtual void  Set_centralizado(bool c) = 0;
		virtual int  Largura() = 0;
		virtual int  Altura() = 0;
		virtual Posicao* Pos() = 0;
		virtual void  Desenhar() = 0;
		virtual bool Visivel() = 0;

		IDesenhavel() { 
			imitador_posicao = 0; 
			transmitindo_posicao_ao_imitador = false; 
		}

		void Incrementa_pos(int x, int y)
		{ Set_pos(X() + x, Y() + y);  }
		void Set_pos_x(int x) { Set_pos(x, Y()); }
		void Set_pos_y(int y) { Set_pos(X(), y); }

		int virtual X() { return Pos()->X(); }
		int virtual Y() { return Pos()->Y(); }
		
		virtual ~IDesenhavel() {}

		void Set_imitador_posicao(IDesenhavel* i) 
		{ imitador_posicao = i;	}
	
		void virtual Set_pos(int x, int y) 
		{ 
//			cout << "Imitador_posicao: " << imitador_posicao << "\n";
//			cout << "transmitindo_posicao_ao_imitador?" << transmitindo_posicao_ao_imitador << "\n";
			if ((imitador_posicao == 0) || (transmitindo_posicao_ao_imitador)) return;

			// Evita circulo de mensagens			
			transmitindo_posicao_ao_imitador = true;
			imitador_posicao->Set_pos(x, y); 
			transmitindo_posicao_ao_imitador = false;
		}


	private:
		// Pode-se ter associado ao IDesenhavel um outro IDesenhavel que imita a posicao
		//deste
		IDesenhavel * imitador_posicao;
		bool transmitindo_posicao_ao_imitador;
};

#define IDESENHAVEL_H
#endif
