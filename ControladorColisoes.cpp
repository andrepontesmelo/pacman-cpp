#include "ControladorColisoes.h"

ControladorColisoes* ControladorColisoes::instancia = 0;

ControladorColisoes* ControladorColisoes::Instancia()
{
	if (instancia == 0)
		instancia = new ControladorColisoes();

	return instancia;
}

void ControladorColisoes::Adicionar(IColidivel* d)
{
#ifdef DEBUG
	if (d == 0) throw new ExcessaoReferenciaNula("IColidivel d", "ControladorColisoes::Adicionar()");
#endif
	colidiveis.push_back(d);
}

void ControladorColisoes::Verificar_colisoes()
{
	if (ultima_pos_pacman == 0)
		ultima_pos_pacman = new Posicao(pacman->Pos()->X(), pacman->Pos()->Y());

		if ((ultima_pos_pacman->Distancia_horizontal(pacman->Pos()) != 0)
	&&  (ultima_pos_pacman->Distancia_vertical(pacman->Pos()) != 0))
	{
		Posicao * pacman_pos = pacman->Pos();
		
		ultima_pos_pacman->Set_x(pacman_pos->X());
		ultima_pos_pacman->Set_y(pacman_pos->Y());
		

	}

	// Apenas verificar se colidido com o pacman
	std::vector<IColidivel*>::iterator iterador = colidiveis.begin();

	// Objeto grande é um que ocupa toda a area de ultima_pos_pacman ... pos pacman
	largura_grande = abs(pacman->Pos()->X() - ultima_pos_pacman->X()) + pacman->Largura();
	altura_grande = abs(pacman->Pos()->Y() - ultima_pos_pacman->Y()) + pacman->Altura();
	
	pos_grande->Set_x((pacman->Pos()->X() + ultima_pos_pacman->X()) / 2);
	pos_grande->Set_y((pacman->Pos()->Y() + ultima_pos_pacman->Y()) / 2);

	for (; iterador < colidiveis.end(); iterador++)
	{
		IColidivel *obj = *iterador;
		if (obj->Visivel() && Verificar_colisao(obj))
		{
			if (obj->Comivel_pelo_pacman())
				 obj->Foi_comido();
			else
				obj->Comeu_pacman();
		}
	}
	
	Posicao * pacman_pos = pacman->Pos();
	
	ultima_pos_pacman->Set_x(pacman_pos->X());
	ultima_pos_pacman->Set_y(pacman_pos->Y());
}

bool ControladorColisoes::Verificar_colisao(IColidivel* obj)
{
#ifdef DEBUG
	if (pacman == 0) 
		throw new ExcessaoReferenciaNula("pacman", "ControladorColisoes::Verificar_colisao");

	if (obj->Pos() == 0)
		throw new ExcessaoReferenciaNula("obj->Pos()", "ControladorColisoes::Verificar_colisao");
#endif
/*	

	bool colidiu_horizontalmente = 
		obj->Pos()->Distancia_horizontal(pacman->Pos()) < (obj->Largura() + pacman->Largura()) / 2;

	bool colidiu_verticalmente =
		obj->Pos()->Distancia_vertical(pacman->Pos()) < (obj->Altura() + pacman->Altura()) / 2;
*/
	
	bool colidiu_horizontalmente = 
		obj->Pos()->Distancia_horizontal(pos_grande) < (obj->Largura() + largura_grande) / 2;

	bool colidiu_verticalmente =
		obj->Pos()->Distancia_vertical(pos_grande) < (obj->Altura() + altura_grande) / 2;

	return (colidiu_horizontalmente && colidiu_verticalmente);
}

void ControladorColisoes::Zerar()
{
	delete(ultima_pos_pacman);
	ultima_pos_pacman = new Posicao(pacman->Pos()->X(), pacman->Pos()->Y());
}

