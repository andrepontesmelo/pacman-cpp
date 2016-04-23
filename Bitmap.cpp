#include "Bitmap.h"

// Todas as construtoras chamam este método.
void Bitmap::Inicializa(BITMAP * bitmap, Posicao * pos)
{

#ifdef DEBUG
	if (bitmap == 0)
		throw new ExcessaoArgumentoNulo("bitmap", "Construtora de Bitmap");

	if (pos == 0)
		throw new ExcessaoReferenciaNula("posicao", "Bitmap::Bitmap(...)");
#endif		

	this->bmp = bitmap;

	this->posicao = pos;

	this->largura = bitmap->w;
	this->altura = bitmap->h;

	centralizado = false;
	instancia_tela = Tela::Instancia();
}


Bitmap::Bitmap(string arquivo, int x, int y)
{
	BITMAP * bitmap = load_bmp(arquivo.c_str(), NULL);
#ifdef DEBUG
	if (bitmap == NULL)
		throw new ExcessaoArquivoNaoEncontrado(arquivo);
#endif
	Inicializa(bitmap, new Posicao(x, y));
}


// Cria bitmap em branco
Bitmap::Bitmap(int largura, int altura, int x, int y)
{	
	bmp = create_bitmap(largura, altura);
	Limpar();

	Inicializa(bmp, new Posicao(x, y));
}

Bitmap::~Bitmap()
{
	destroy_bitmap(bmp);
}
/*
int Bitmap::X()
{
#ifdef DEBUG
	if (posicao == 0)
		throw new ExcessaoReferenciaNula("posicao", "Bitmap::X()");
#endif
	return posicao->X();
}

int Bitmap::Y()
{
#ifdef DEBUG
	if (posicao == 0)
		throw new ExcessaoReferenciaNula("posicao", "bitmap::y()");
#endif
	return posicao->Y();
}
*/
void Bitmap::Set_pos(int x, int y)
{
#ifdef DEBUG
	if (posicao == 0)
		throw new ExcessaoReferenciaNula("posicao", "bitmap::Set_pos()");
#endif

	posicao->Set_x(x);
	posicao->Set_y(y);

	IDesenhavel::Set_pos(x, y);
}

void Bitmap::Limpar()
{
	clear_bitmap(bmp);
}


void Bitmap::Desenhar_circulo_preenchido(int x, int y, int raio, Cor * cor)
{
#ifdef DEBUG
	if (cor == 0)
		throw new ExcessaoArgumentoNulo("cor", "Bitmap::Desenhar_circulo_preenchido(...)");
#endif
	circlefill(bmp, x, y, raio, makecol(cor->R(), cor->G(), cor->B()));
	
		
}

void Bitmap::Desenhar_linha(int x, int y, int x1, int y1, Cor * cor)
{
#ifdef DEBUG
	if (cor == 0)
		throw new ExcessaoArgumentoNulo("cor", "Bitmap::Desenhar_linha(...)");
#endif
	line(bmp, x, y, x1, y1, makecol(cor->R(), cor->G(), cor->B()));

}

void Bitmap::Desenhar()
{
#ifdef DEBUG
	if (posicao == 0)
		throw new ExcessaoReferenciaNula("posicao", "Bitmap::Desenhar()");
#endif

	if (centralizado)
		instancia_tela->Desenhar(bmp, posicao->X() - (largura / 2), posicao->Y() - (altura / 2));
	else
		instancia_tela->Desenhar(bmp, posicao->X(), posicao->Y());
}
