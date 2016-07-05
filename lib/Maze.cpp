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
			throw new Exception("Food is not alined.");

	bool primeira = true;
	for (int var = varInit; var + (FOOD_DISTANCE / 2) <= varMax; var += FOOD_DISTANCE)
	{
		if (sameRow) x = var;
		else y = var;
		
		// Na construcao, apenas desenhar foods nas corners.
		#ifdef  CONSTRUINDO_MAZE
		if (primeira)
		#endif
		foods->Add(new Food(x, y));
		primeira = false;
	}
	
	// Na construcao, desenhar tambem a last food.
	foods->Add(new Food(greater->GetPosition()->X(), greater->GetPosition()->Y()));

#ifdef  CONSTRUINDO_MAZE
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
	ifstream arq;
	arq.open(MAZE_FILE, ios::in);

	if (!arq)
		throw new FileNotFoundException(MAZE_FILE);

	// Position timeraria para leitura dos pontos
	int row, column;

	// Significa que uma corner nao tem seu percurso wallkable até a next.
	bool barreira_h = false;	// |
	bool barreira_v  = false;	// -
	bool sem_food_v = false;		// ^
	bool sem_food_h = false;		// <
	bool corner_start_pacman_agora = false;
	bool corner_start_ghost_agora = false;
	
	// Identificador: L C
	char identificador;

	// Corners nexts
	Corner * new_obj_corner = 0, * left_corner = 0;
	
	string comentario;
	int line = 0;

	while (arq >> identificador)
	{
		line++;
		bool lerNovamente = false;

		switch (identificador)
		{
			case ' ':
			case '#':
				arq >> comentario;
				lerNovamente = true;
				break;
			case 'L':
				arq >> row;

				// Apos ler <L> <num_row>, deve-se obter a column.
				lerNovamente = true;

				// Em uma new_obj row, nao ha referencia para corner à left.
				left_corner = 0;
				break;

			case 'C':
				arq >> column;
				break;
			case '|':
				barreira_h = true;
				lerNovamente = true;
				break;
			case '-':
				barreira_v = true;
				lerNovamente = true;
				break;
			case '^':
				sem_food_v = true;
				lerNovamente = true;
				break;
			case '<':
				sem_food_h = true;
				lerNovamente = true;
				break;
			case 'P':
				corner_start_pacman_agora = true;
				lerNovamente = true;
				break;
			case 'X':
				corner_start_ghost_agora = true;
				lerNovamente = true;
				break;
			case 'F':
				int L1, C1, L2, C2;
				arq >> L1;
				arq >> C1;
				
				arq >> L2;
				arq >> C2;
				
				jail = new Box(C1, L1, C2, L2);
				lerNovamente = true;
				break;	
			case 'I':
				int l, c;
				arq >> l;
				arq >> c;
				PillComposition::Instance()->Add(new Pill(c, l));
				lerNovamente = true;
				break;

			default:
				string err = "Error parsing maze file. "; 
				cout << line;
				throw new Exception(err + identificador + " aline ");
				break;
		}
	
		if (!lerNovamente)
		{	
			new_obj_corner = new Corner(row, column);
			Corner * top_corner = corners->GetAbove(new_obj_corner);
			
			if (corner_start_pacman_agora)
			{
				corner_start_pacman = new_obj_corner;
				corner_start_pacman_agora = false;
			} 
			if (corner_start_ghost_agora)
			{
				corner_start_ghost = new_obj_corner;
				corner_start_ghost_agora = false;
			}
	
			
			// Caso exista barrira, pode leftuecer a last corner
			if (barreira_h) left_corner = 0;
			if (barreira_v) top_corner = 0;

			// Registra corner atual.
			corners->RegisterCorner(new_obj_corner, left_corner, top_corner);
	
			if ((left_corner != 0) && (!sem_food_h))
			Generate_foods(new_obj_corner, left_corner);

			if ((top_corner != 0) && (!sem_food_v))
			Generate_foods(new_obj_corner, top_corner);

			// Redefine corner left para a atual, porque a next provavelmente estara a right. desta
			left_corner = new_obj_corner;

			barreira_h = false;
			barreira_v = false;
			sem_food_v  = false;
			sem_food_h = false;
		}
	}

	arq.close();

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

