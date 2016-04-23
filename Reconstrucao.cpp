#include "Reconstrucao.h"

Reconstrucao* Reconstrucao::instancia = 0;

Reconstrucao::Reconstrucao()
{
}

Reconstrucao* Reconstrucao::Instancia()
{
	if (instancia == 0)
		instancia = new Reconstrucao();

	return instancia;
}


void Reconstrucao::Pacman_morreu()
{
	Notificar(PACMAN_MORREU);
}

void Reconstrucao::Nova_fase()
{
	Notificar(NOVA_FASE);
}

void Reconstrucao::Comida_comida()
{
	Notificar(COMIDA_COMIDA);
}
