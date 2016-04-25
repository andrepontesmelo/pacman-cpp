#include "Ghost.h"

void Ghost::Refresh(int action)
{
	switch (action)
	{
		case Reconstruction::NEW_PHASE:
		case Reconstruction::PACMAN_DIED:
		Reset();
		break;
	}
}

void Ghost::Reset()
{
	Maze * maze = Maze::Instance();
	Corner * initial_corner = maze->GetInitialGhostCorner();

	PillFinished();	
	PreparePrisioners();

	drawing->SetPosition(initial_corner->GetPosition()->X(), initial_corner->GetPosition()->Y());
}

Ghost::Ghost(int jail_time)
{
	Maze * maze = Maze::Instance();
	
	this->jail_time = jail_time;

	next_corner = Maze::Instance()->GetInitialGhostCorner();
	Corner * initial_corner = maze->GetInitialGhostCorner();
	jail_follower = new GreedyFollower(initial_corner->GetPosition(), this);

	jail = maze->GetJail();

	LoadBitmaps();
	
	CollisionDetection::Instance()->Add(this);
	
	PreparePrisioners();
}

void Ghost::LoadBitmaps()
{
	Maze * maze = Maze::Instance();
	Corner * initial_corner = maze->GetInitialGhostCorner();
	Position * initial_position = initial_corner->GetPosition();

	Animation * blinking_animation;
	blinking_animation = new Animation(GHOST_BLINKING_INTERVAL);
	blinking_animation->Add_bitmap(new Bitmap("img/ghost_run_away.bmp", initial_position->X()));
	blinking_animation->Add_bitmap(new Bitmap("img/ghost_run_away_b.bmp", initial_position->X()));
	blinking_animation->SetCentered(true);
	
	bitmap_blink = blinking_animation;
	
	bitmap_pill_efect = new Bitmap("img/ghost_run_away.bmp", initial_position->X(), initial_position->Y());
	bitmap_pill_efect->SetCentered(true);

	bitmap_eaten = new Bitmap("img/eyes.bmp", initial_position->X(), initial_position->Y());
	bitmap_eaten->SetCentered(true);

	pill_effect = false;
	blinking = false;

}

void Ghost::PillEaten()
{
	if (action != RETURNING)
	{
		bitmap_pill_efect->SetPosition(drawing->X(), drawing->Y());
		
		drawing = bitmap_pill_efect;
		pill_effect = true;
	}
}

void Ghost::FinishingPill()
{
	if ((action == RELEASE) && (pill_effect))
	{
		bitmap_blink->SetPosition(drawing->X(), drawing->Y());

		drawing = bitmap_blink;
	}
}

void Ghost::PillFinished()
{
	if (action != RETURNING)
	{
		regular_drawing->SetPosition(drawing->X(), drawing->Y());
		drawing = regular_drawing;
		pill_effect = false;
	}
}

void Ghost::PreparePrisioners()
{
	next_corner = Maze::Instance()->GetInitialGhostCorner();

	if (next_corner == 0)
		throw new Exception("Wrong next corner for ghost.");

	action = ARRESTED;
	random_direction = Direction::GetRandomly(0.2);

	cronometer_jail.Start();
}

void Ghost::ExitJail()
{
	pill_effect = false;
	action = RELEASING;	
	PillFinished();
	
	next_corner = Maze::Instance()->GetInitialGhostCorner();
}

void Ghost::UpdatePosition(int elapsed_ms)
{
	acc_time += elapsed_ms;
	int walking_pixels = acc_time / Interval();
	acc_time = acc_time % Interval();

	int delta_x, delta_y;

	switch (action)
	{
		case ARRESTED:

		delta_x = (int) (random_direction->X() * walking_pixels);
		delta_y = (int) (random_direction->Y() * walking_pixels);

		drawing->IncrementPosition(delta_x, delta_y); 

		ForceJail();
		
		cronometer_jail.Refresh();
		if (cronometer_jail.ReadMs() > jail_time)
			ExitJail();

		break;

		case ENTERING:
#ifdef DEBUG
		if (next_corner != Maze::Instance()->GetInitialGhostCorner())
			throw new Exception("Wrong next corner for entering ghost");
#endif
		if (drawing->GetPosition()->Below(jail->GetCenterPosition()))
		{
			PreparePrisioners();
		}

		case RELEASING:
#ifdef DEBUG
		if (next_corner != Maze::Instance()->GetInitialGhostCorner())
			throw new Exception("Wrong next corner for releasing ghost");
#endif

		if (drawing->GetPosition()->HorizontalDistance(next_corner->GetPosition()) < walking_pixels)
		{
			drawing->SetPosition_x(next_corner->GetPosition()->X());

			if (action == RELEASING)
				drawing->IncrementPosition(0, -1 * walking_pixels);
			else if (action == ENTERING)
				drawing->IncrementPosition(0, walking_pixels);

			if ((action == RELEASING && drawing->GetPosition()->Above(next_corner->GetPosition())))				
			{
				action = RELEASE;
			}

		} else
		{
			if (drawing->GetPosition()->RightOf(next_corner->GetPosition()))	
				drawing->IncrementPosition(-1 * walking_pixels, 0); 
			else
				drawing->IncrementPosition(walking_pixels, 0); 
		}

		break;

		case RETURNING:

		if (next_corner->GetPosition()->Distance(Maze::Instance()->GetInitialGhostCorner()->GetPosition()) 
			<= walking_pixels)
		{
			action = ENTERING;
			next_corner = Maze::Instance()->GetInitialGhostCorner();
		} else
		{
			WalkingElement::UpdatePosition(elapsed_ms);
		}
		break;

		case RELEASE:		
			WalkingElement::UpdatePosition(elapsed_ms);
		break;		
	}
}

void Ghost::ForceJail()
{
	Position * drawing_pos = drawing->GetPosition();

	if (drawing_pos->RightOf(jail->Pos2()))
		random_direction->SetX(-1);

	if (drawing_pos->LeftOf(jail->Pos1()))
		random_direction->SetX(1);
	
	if (drawing_pos->Above(jail->Pos1()))
		random_direction->SetY(1);
	
	if (drawing_pos->Below(jail->Pos2()))
		random_direction->SetY(-1);
}

void Ghost::WasEaten()
{
	action = RETURNING;
	
	bitmap_eaten->SetPosition(drawing->X(), drawing->Y());
	
	drawing = bitmap_eaten;
}

int Ghost::Interval()
{
	if ((action == RETURNING) || (action == ENTERING))
		return GHOST_INTERVAL_RETURNING;

	return pill_effect ? GHOST_PILL_INTERVAL : GHOST_INTERVAL;
}

void Ghost::AtePacman()
{
	LifeController * lifes = LifeController::Instance();
	lifes->PacmanWasEaten();
}
