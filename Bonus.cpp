#include "Bonus.h"

void Bonus::Inicializar()
{
	// Registra si mesmo no controlador de colisoes:
	ControladorColisoes::Instancia()->Adicionar(this);
}

