#ifndef ALEATORIO_H
#define ALEATORIO_H

#include <cstdlib>
#include <ctime>

class Random
{
public:
static Random* Instance();

int Generate(int max);
bool GenerateBool();
double Generate();

private:
static Random* instance;
Random();
};

#endif
