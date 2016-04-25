#ifndef ALLEGRO_H
#include <iostream>
#include <allegro.h>
#define ALLEGRO_H

class Allegro
{
private:
	Allegro() {}
	static Allegro* instance;
	int width, height;

public:
	void Initialize(int width, int height);
	void Finalize();
	static Allegro* Instance();
	int Width() { return width; }
	int Height() { return height; }
	void Wait(int time);
};

#endif
