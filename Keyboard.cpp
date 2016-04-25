#include "Keyboard.h"

Keyboard * Keyboard::instance = 0;

Keyboard::Keyboard()
{
	last_key = NOTHING;
}

void Keyboard::Pause()
{
	readkey();
}


Keyboard* Keyboard::Instance()
{
	if (instance == 0)
		instance = new Keyboard();
	
	return instance;
}

enum Keyboard::Tecla Keyboard::GetKeyPressed()
{
	if (key[KEY_ESC])
		last_key = ESC;

	if (key[KEY_DOWN])
		last_key = BOTTOM;

	if (key[KEY_UP])
		last_key = TOP;

	if (key[KEY_LEFT])
		last_key = LEFT;

	if (key[KEY_RIGHT])
		last_key = RIGHT;

	return last_key;
}
