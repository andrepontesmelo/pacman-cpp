#include "Tela.h"

Tela* Tela::instancia = 0;

Tela::Tela(int largura, int altura)
{
	this->largura = largura;
	this->altura = altura;

	// Cria o buffer
	buffer = create_bitmap(largura, altura);
	clear_bitmap(buffer);
}


int Tela::Largura()
{
	return largura;
}

int Tela::Altura()
{
	return altura;
}


Tela* Tela::Instancia()
{
	if (instancia == 0)
	{
		Allegro * allegro = Allegro::Instancia();
		instancia = new Tela(allegro->Largura(), allegro->Altura());
	}

	return instancia;
}

void Tela::Atualizar()
{
	
	vsync();
	blit(buffer, screen, 0, 0, 0, 0, largura, altura); 
	clear_bitmap(buffer);
}

void Tela::Desenhar(BITMAP * bitmap, int x, int y)
{
	draw_sprite(buffer, bitmap, x, y);
}

void Tela::Desenhar_texto(string texto, int x, int y, Cor * cor, bool centralizado)
{
	if (centralizado)
  		textout_centre(buffer, font, texto.c_str(), x, y, makecol(cor->R(), cor->G(), cor->B()));
	else
		textout(buffer, font, texto.c_str(), x, y, makecol(cor->R(), cor->G(), cor->B()));

	//textout(buffer, font, "BLAH!!!!!!!!!!", x, y, makecol(cor->R(), cor->G(), cor->B()));
	//cout << "X:" << x << " Y:" <<y << "\n ";

}

