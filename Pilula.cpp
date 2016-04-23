#include "Pilula.h"

Pilula::Pilula(int x, int y) : Bonus()
{
	desenho = Construir_animacao(x, y);
	desenho->Set_centralizado(true);

	// Inscreve-se na reconstrução
	Reconstrucao::Instancia()->Adicionar_observador(this);
}

void Pilula::Foi_comido()
{
	if (!visivel) return;

#ifdef DEBUG
	if (fantasmas == 0)
		throw new ExcessaoReferenciaNula("fantasmas", "Pilula::Foi_comido()");
#endif

	fantasmas->Pilula_comida();
	ElementoRepresentavel::Foi_comido();
}

Animacao* Pilula::Construir_animacao(int x, int y)
{
	Animacao * ani = new Animacao(PILULA_ANIMACAO_PERIODO);

	Cor * cor = new Cor(PILULA_COR_R, PILULA_COR_G, PILULA_COR_B);

	// Cria um bitmap em branco
	for (int raio = PILULA_RAIO; raio < PILULA_RAIO_MAX; raio++)
	{
		Bitmap * bmp = new Bitmap(2 * PILULA_RAIO_MAX + 1, 2 * PILULA_RAIO_MAX + 1, x, y);

		bmp->Desenhar_circulo_preenchido(PILULA_RAIO_MAX, PILULA_RAIO_MAX, raio, cor);

		ani->Inserir_bitmap(bmp);
	}

	// Cria um bitmap em branco
	for (int raio = PILULA_RAIO_MAX; raio > PILULA_RAIO; raio--)
	{
		Bitmap * bmp = new Bitmap(2 * PILULA_RAIO_MAX + 1, 2 * PILULA_RAIO_MAX + 1, x, y);

		bmp->Desenhar_circulo_preenchido(PILULA_RAIO_MAX, PILULA_RAIO_MAX, raio, cor);

		ani->Inserir_bitmap(bmp);
	}

	return ani;
}

void Pilula::Atualiza(int acao)
{
	switch (acao)
	{
		case Reconstrucao::NOVA_FASE:
			visivel = true;
		break;
	}
}

