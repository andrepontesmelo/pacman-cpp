#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "Subject.h"
#include "Allegro.h"
#include <iostream>
using std::cout;

class Keyboard : public Subject
{
public:
	enum Tecla {ESC, LEFT, RIGHT, TOP, BOTTOM, NOTHING};
	enum Tecla GetKeyPressed();
	static Keyboard * Instance();
	void Pause();			
private:
	Keyboard();
	static Keyboard* instance;
	enum Tecla last_key;
};

#endif
