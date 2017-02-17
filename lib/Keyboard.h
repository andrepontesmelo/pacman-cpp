#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "Subject.h"
#include "Allegro.h"
#include <iostream>
using std::cout;

class Keyboard : public Subject
{
public:
enum Key {ESC, LEFT, RIGHT, TOP, BOTTOM, NOTHING};
enum Key GetKeyPressed();
static Keyboard * Instance();
void Pause();
private:
Keyboard();
static Keyboard* instance;
enum Key last_key;
};

#endif
