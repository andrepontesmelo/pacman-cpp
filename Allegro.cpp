#include "Allegro.h"

Allegro* Allegro::instancia = 0;

Allegro * Allegro::Instancia()
{
	if (instancia == 0)
		instancia = new Allegro();	

	return instancia;
}

void Allegro::Esperar(int tempo)
{
	rest(tempo);
}
void Allegro::Inicializa(int largura, int altura)
{
	this->largura = largura;
	this->altura = altura;

  if (allegro_init()!=0) 
  {
    std::cout << "allegro_init failed\n";
    exit(1);
  }

 if (install_keyboard()) {
   allegro_message("Cannot initalize keyboard input.\n");
   exit(1);
 }
  set_color_depth(16);  // Idem
  if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, largura, altura, 0, 0) < 0) {  
    set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
    allegro_message("Unable to set graphic mode: %s\n", allegro_error);
    exit(2);
  }
}

void Allegro::Finaliza()
{
	allegro_exit();
}
