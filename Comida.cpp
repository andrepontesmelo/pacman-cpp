#include "Comida.h"

void Comida::Inicializar(Posicao * posicao) 
{
	this->posicao = posicao;

//	cout << "Comida na pos: " << posicao->String() << "\n";
	// Pode-se futuramente gerar apenas um bitmap que sera utilidados para as varias comidas, usando um bitmap statico
	desenho = Criar_bitmap(posicao);

	// Registra si mesmo no controlador de colisoes:
	ControladorColisoes::Instancia()->Adicionar(this);
}

Comida::Comida(int x, int y)
{
	// A subtração faz com que a comida seja centralizada na posicao.
	Inicializar(new Posicao(x - COMIDA_RAIO, y - COMIDA_RAIO));
}

Comida::Comida(Posicao * posicao)
{
	Inicializar(posicao);
}


Bitmap * Comida::Criar_bitmap(Posicao * posicao)
{
#ifdef DEBUG
	if (posicao == 0)
		throw new ExcessaoReferenciaNula("posicao", "Comida::Criar_bitmap");
#endif

	// Cria um bitmap em branco
	Bitmap * bmp = new Bitmap(2 * COMIDA_RAIO + 1, 2 * COMIDA_RAIO + 1, posicao->X(), posicao->Y());
	Cor * cor = new Cor(COMIDA_COR_R, COMIDA_COR_G, COMIDA_COR_B);

	bmp->Limpar();
	bmp->Desenhar_circulo_preenchido(COMIDA_RAIO, COMIDA_RAIO, COMIDA_RAIO, cor);

	return bmp;
}

void Comida::Foi_comido()
{
	ElementoRepresentavel::Foi_comido(); 
	Reconstrucao::Instancia()->Comida_comida();
}
