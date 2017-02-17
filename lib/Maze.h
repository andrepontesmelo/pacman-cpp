#ifndef MAZE_H
#define MAZE_H
#include <fstream>
#include <string>

#include "Params.h"
#include "Bitmap.h"
#include "FixedDirection.h"
#include "Corner.h"
#include "DrawingElement.h"
#include "Box.h"

#include "FileNotFoundException.h"
#include "NullArgumentException.h"
#include "Exception.h"

#include "FoodComposition.h"
#include "PillComposition.h"
#include "CornerCollection.h"


using std::ios;
using std::ifstream;
using std::string;
using std::stringstream;

class Maze : public DrawingElement
{
private:
static Maze* instance;
Bitmap * bitmap;
Maze();
void LoadMaze();
CornerCollection *  corners;
void RegisterCorner(Corner *corner, Corner *itsLeft);
void Generate_foods(Corner *a, Corner *b);

FoodComposition * foods;

Corner * corner_start_pacman;
Corner * corner_start_ghost;
Box * jail;

public:
static Maze * Instance();
void Draw();
Corner * Corner_start_pacman();
Corner * GetInitialGhostCorner();

Box * GetJail();
};

#endif
