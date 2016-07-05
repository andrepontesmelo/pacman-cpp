#include "Allegro.h"

Allegro* Allegro::instance = 0;

Allegro * Allegro::Instance()
{
	if (instance == 0)
		instance = new Allegro();	

	return instance;
}

void Allegro::Wait(int time)
{
	rest(time);
}

void Allegro::Initialize(int width, int height)
{
	this->width = width;
	this->height = height;

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
  if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, width, height, 0, 0) < 0) {  
    set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
    allegro_message("Unable to set graphic mode: %s\n", allegro_error);
    exit(2);
  }
}

void Allegro::Finalize()
{
	allegro_exit();
}
