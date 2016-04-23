#ifndef DIRECAO_H
#define DIRECAO_H
#include "Aleatorio.h"
#include <math.h>
#include <iostream>
#include <string>
#include <sstream>
using std::string;
using std::stringstream;
using std::cout;
class Direcao
{
	public:
		Direcao(float x, float y) { this->x = x; this->y = y; } 
		Direcao() {} 
		virtual ~Direcao() {}
	
		float X() { return x; }
	 	float Y() { return y; }

		virtual void Setar_aleatoriamente(double modulo_minimo);
		
		virtual void Inverte_x() { x *= -1; }
		virtual void Inverte_y() { y *= -1; }

		string String();
		static Direcao* Obter_aleatoriamente(double modulo_minimo);

	private:
		float x, y;

	public:
		virtual void Set_x(float x) { this->x = x; }
		virtual void Set_y(float y) { this->y = y; }
	};

#endif
