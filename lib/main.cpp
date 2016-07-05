#include "Allegro.h"
#include "Bitmap.h"
#include "Keyboard.h"
#include "Maze.h"
#include "Screen.h"
#include "Position.h"
#include "Params.h"
#include "Pacman.h"
#include "CollisionDetection.h"
#include "LifeController.h"
#include "Cronometer.h"
#include "GhostComposition.h"
#include "PillComposition.h"

int main()
{
	Allegro * allegro = Allegro::Instance();
	allegro->Initialize(SCREEN_WIDTH, SCREEN_HEIGHT);

	Screen * screen = Screen::Instance();
	Maze * maze =  Maze::Instance();
	Pacman * pacman = new Pacman();
	
	LifeController * lifes = LifeController::Instance();
	lifes->SetPacman(pacman);
	GhostComposition * ghosts = GhostComposition::Instance();
	ghosts->Generate_ghosts(pacman);
	PillComposition::Instance()->Set_ghosts(ghosts);

	CollisionDetection * collisions = CollisionDetection::Instance();
	collisions->SetPacman(pacman);
	Keyboard *keyboard = Keyboard::Instance();
	Cronometer cronometer;
	int elapsed_time = 0;
	
	while (keyboard->GetKeyPressed() != Keyboard::ESC)
	{
		cronometer.Start();
		keyboard->GetKeyPressed();
		pacman->UpdatePosition(elapsed_time);

		keyboard->GetKeyPressed();
		ghosts->UpdatePosition(elapsed_time);

		keyboard->GetKeyPressed();
		maze->Draw();

		keyboard->GetKeyPressed();
		ghosts->Draw();

		keyboard->GetKeyPressed();
		pacman->Draw();

		keyboard->GetKeyPressed();
		lifes->Draw();

		screen->Refresh();
		
		keyboard->GetKeyPressed();				
		
		allegro->Wait(10);

		collisions->Detect();
		keyboard->GetKeyPressed();		
		cronometer.Refresh();
		elapsed_time = cronometer.ReadMs();
	}

	allegro->Finalize();
	return 0;
}
END_OF_MAIN();

