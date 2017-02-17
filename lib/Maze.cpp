#include "Maze.h"

Maze * Maze::instance = 0;

Maze::Maze()
{
								corners = new CornerCollection();

								foods = new FoodComposition();

								drawing = new Bitmap(MAZE_BITMAP, 0, 0);
								drawing->SetCentered(false);
								LoadMaze();
}

void Maze::Generate_foods(Corner *a, Corner *b)
{
								Corner *less, *greater;

								int x = 0, y = 0;
								bool sameRow = a->GetPosition()->SameRow(b->GetPosition());
								int varInit, varMax;

								if (sameRow)
								{
																y = a->GetPosition()->Y();

																if (b->GetPosition()->RightOf(a->GetPosition()))
																{
																								less = a; greater = b;
																} else
																{
																								less = b; greater = a;
																}

																varInit = less->GetPosition()->X();
																varMax = greater->GetPosition()->X();

								} else
								if (a->GetPosition()->SameColumn(b->GetPosition()))
								{
																x = a->GetPosition()->X();

																if (b->GetPosition()->Below(a->GetPosition()))
																{
																								less = a; greater = b;
																} else
																{
																								less = b; greater = a;
																}

																varInit = less->GetPosition()->Y();
																varMax = greater->GetPosition()->Y();

								} else
																throw new Exception("Food is not aligned.");

								bool first = true;
								for (int var = varInit; var + (FOOD_DISTANCE / 2) <= varMax; var += FOOD_DISTANCE)
								{
																if (sameRow) x = var;
																else y = var;

		#ifdef  BUILDING_MAZE
																if (first)
		#endif
																foods->Add(new Food(x, y));
																first = false;
								}

								foods->Add(new Food(greater->GetPosition()->X(), greater->GetPosition()->Y()));

#ifdef  BUILDING_MAZE
								((Bitmap *) drawing)->DrawLine(less->GetPosition()->X(), less->GetPosition()->Y(),
																																							greater->GetPosition()->X(), greater->GetPosition()->Y(),
																																							new Color(255, 255, 200));
#endif
}

void Maze::Draw()
{
								DrawingElement::Draw();
								PillComposition::Instance()->Draw();

								foods->Draw();
}

void Maze::LoadMaze()
{
								ifstream file;
								file.open(MAZE_FILE, ios::in);

								if (!file)
																throw new FileNotFoundException(MAZE_FILE);

								int row, column;

								bool barrier_h = false; // |
								bool barrier_v  = false;// -
								bool without_food_v = false; // ^
								bool without_food_h = false; // <
								bool will_start_pacman_corner = false;
								bool will_start_ghost_corner = false;
								char identifier;

								Corner * new_obj_corner = 0, * left_corner = 0;

								string comment;
								int line = 0;

								while (file >> identifier)
								{
																line++;
																bool readAgain = false;

																switch (identifier)
																{
																case ' ':
																case '#':
																								file >> comment;
																								readAgain = true;
																								break;
																case 'L':
																								file >> row;

																								readAgain = true;
  																							left_corner = 0;
																								break;

																case 'C':
																								file >> column;
																								break;
																case '|':
																								barrier_h = true;
																								readAgain = true;
																								break;
																case '-':
																								barrier_v = true;
																								readAgain = true;
																								break;
																case '^':
																								without_food_v = true;
																								readAgain = true;
																								break;
																case '<':
																								without_food_h = true;
																								readAgain = true;
																								break;
																case 'P':
																								will_start_pacman_corner = true;
																								readAgain = true;
																								break;
																case 'X':
																								will_start_ghost_corner = true;
																								readAgain = true;
																								break;
																case 'F':
																								int L1, C1, L2, C2;
																								file >> L1;
																								file >> C1;

																								file >> L2;
																								file >> C2;

																								jail = new Box(C1, L1, C2, L2);
																								readAgain = true;
																								break;
																case 'I':
																								int l, c;
																								file >> l;
																								file >> c;
																								PillComposition::Instance()->Add(new Pill(c, l));
																								readAgain = true;
																								break;

																default:
																								string err = "Error parsing maze file. ";
																								cout << line;
																								throw new Exception(err + identifier + " aline ");
																								break;
																}

																if (!readAgain)
																{
																								new_obj_corner = new Corner(row, column);
																								Corner * top_corner = corners->GetAbove(new_obj_corner);

																								if (will_start_pacman_corner)
																								{
																																corner_start_pacman = new_obj_corner;
																																will_start_pacman_corner = false;
																								}
																								if (will_start_ghost_corner)
																								{
																																corner_start_ghost = new_obj_corner;
																																will_start_ghost_corner = false;
																								}


																								if (barrier_h) left_corner = 0;
																								if (barrier_v) top_corner = 0;

																								corners->RegisterCorner(new_obj_corner, left_corner, top_corner);

																								if ((left_corner != 0) && (!without_food_h))
																																Generate_foods(new_obj_corner, left_corner);

																								if ((top_corner != 0) && (!without_food_v))
																																Generate_foods(new_obj_corner, top_corner);

																								left_corner = new_obj_corner;

																								barrier_h = false;
																								barrier_v = false;
																								without_food_v  = false;
																								without_food_h = false;
																}
								}

								file.close();

}

Maze * Maze::Instance()
{
								if (instance == 0)
																instance = new Maze();

								return instance;
}


Corner * Maze::Corner_start_pacman()
{

#ifdef DEBUG
								if (corner_start_pacman == 0)
																throw new NullArgumentException("corner_start_pacman", "Maze::Corner_start_pacman()");
#endif
								return corner_start_pacman;
}

Corner * Maze::GetInitialGhostCorner()
{

#ifdef DEBUG
								if (corner_start_ghost == 0)
																throw new NullArgumentException("corner_start_ghost", "Maze::GetInitialGhostCorner()");
#endif
								return corner_start_ghost;
}


Box * Maze::GetJail()
{
#ifdef DEBUG
								if (jail == 0)
																throw new NullReferenceException("jail", "Maze::GetJail()");
#endif

								return jail;
}
