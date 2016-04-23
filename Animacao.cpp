#include "Animacao.h"

void Animacao::Inserir_bitmap(Bitmap *bmp)
{
#ifdef DEBUG
	if (bmp == 0)
		throw new ExcessaoReferenciaNula("bmp", "Animacao::Inserir_bitmap()");
#endif
	
	bitmaps.push_back(bmp);
   Preparar();
}

void Animacao::Preparar()
{
	iterador = bitmaps.begin();
	cronometro.Iniciar();
}

Animacao::Animacao(int tempo)
{
	tempo_Ms = tempo; 
}

void Animacao::Desenhar()
{
#ifdef DEBUG 
	Confirmar_existencia_bitmaps("Desenhar()");
#endif

if (iterador == bitmaps.end())
	iterador = bitmaps.begin();

	(*iterador)->Desenhar();

	cronometro.Atualizar_leitura();
	if (cronometro.Leitura_Ms() > tempo_Ms)
	{
      iterador++;
		cronometro.Iniciar();
	}
}
/*
int Animacao::X()
{
#ifdef DEBUG
	Confirmar_existencia_bitmaps("X()");
#endif

	return Primeiro_bitmap()->X();
}

int Animacao::Y()
{
#ifdef DEBUG
	Confirmar_existencia_bitmaps("Y()");
#endif

	return Primeiro_bitmap()->Y();
}
*/
void Animacao::Set_centralizado(bool c) 
{
	std::vector<Bitmap*>::iterator i;

	i = bitmaps.begin();

	for (; i < bitmaps.end(); i++)
		(*i)->Set_centralizado(c);
	
}

void Animacao::Set_pos(int x, int y)
{
#ifdef DEBUG
	Confirmar_existencia_bitmaps("Pos()");
#endif
	std::vector<Bitmap*>::iterator i;
	i = bitmaps.begin();

	for (; i < bitmaps.end(); i++)
		(*i)->Set_pos(x, y);

	IDesenhavel::Set_pos(x, y);
}

Posicao* Animacao::Pos()
{
#ifdef DEBUG
	Confirmar_existencia_bitmaps("Pos()");
#endif

	return Primeiro_bitmap()->Pos();
}

int Animacao::Altura()
{
	return Primeiro_bitmap()->Altura();
}

int Animacao::Largura()
{
	return Primeiro_bitmap()->Largura();
}

#ifdef DEBUG
void Animacao::Confirmar_existencia_bitmaps(string modulo)
{
	if (bitmaps.size() == 0)
	{
		throw new Excessao("Foi solicitado Desenhar() para uma animacao cujo tem conjunto de bitmaps é vazio. \nErro em Animacao::" + modulo);
	}
}
#endif

Bitmap * Animacao::Primeiro_bitmap()
{
	return (*bitmaps.begin());
}
