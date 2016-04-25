#include "Pacman.h"

void Pacman::Initilize()
{
	Corner * initial_corner = Maze::Instance()->Corner_start_pacman();
	next_direction = FixedDirection::Right();
	this->drawing = flipped_drawings[next_direction->GetCode()];	

	drawing->SetPosition(Maze::Instance()->Corner_start_pacman()->GetPosition()->X(), Maze::Instance()->Corner_start_pacman()->GetPosition()->Y());

	next_corner = initial_corner->GetCorner(next_direction->GetCode());
}

Pacman::Pacman()
{
	LoadBitmaps();

	lifes = INITIAL_LIFES;

	Initilize();	
	drawing->SetCentered(true);
	
	if (next_corner == 0)
		throw new Exception("Cannot move to next corner.");

	Reconstruction::Instance()->AddObserver(this);
}


void Pacman::LoadBitmaps()
{
	Animation * ani;
	stringstream filename;
	Position * initial_position = Maze::Instance()->Corner_start_pacman()->GetPosition();
	IDrawable * first = 0;
	IDrawable * last_created = 0;
	

	for (int direction_nr = 0; direction_nr < 4; direction_nr++)
	{
		FixedDirection * current_direction = FixedDirection::GetByCode(direction_nr);

		ani = new Animation(PACMAN_MOUTH_INTERVAL);
		string short_name_direction = current_direction->ShortName();
	
		for (int x = 0; x <= 4; x++)
		{
			filename.str("");
			filename << "img/pacman" << x << "_" << short_name_direction << ".bmp";

			ani->Add_bitmap(new Bitmap(filename.str(), initial_position->X(), initial_position->Y()));
		}

		for (int x = 3; x >= 1; x--)
		{
			filename.str("");
			filename << "img/pacman" << x << "_" << short_name_direction << ".bmp";

			ani->Add_bitmap(new Bitmap(filename.str(), initial_position->X(), initial_position->Y()));
		}

		ani->SetCentered(true);

		flipped_drawings[current_direction->GetCode()] = ani;
		if (last_created == 0)
		{
			first = ani;
		} else
		{
			ani->SetImitatorPosition(last_created);
		}
		
		last_created = ani;	

	}

	first->SetImitatorPosition(last_created);
}

void Pacman::Flip()
{
	IDrawable * nextt = flipped_drawings[next_direction->GetCode()];

	this->drawing = nextt;
}


void Pacman::UpdatePosition(int elapsed_ms)
{
	switch (Keyboard::Instance()->GetKeyPressed())
	{
		case Keyboard::BOTTOM:
			next_direction = FixedDirection::Bottom();
			break;

		case Keyboard::LEFT:
			next_direction = FixedDirection::Left();
			break;

		case Keyboard::RIGHT:
			next_direction = FixedDirection::Right();
			break;

		case Keyboard::TOP:
			next_direction = FixedDirection::Top();
			break;

		default:
			break;
	}

	if (direction->Opposit() == next_direction)
	{
		next_corner = next_corner->GetCorner(next_direction->GetCode());
		direction = next_direction;
		stopped = false;
		Flip();
	}

	WalkingElement::UpdatePosition(elapsed_ms);
}

void Pacman::Draw()
{
	WalkingElement::Draw();
}

void Pacman::WasEaten()
{
	lifes--;

	Reconstruction::Instance()->PacmanDied();
}

void Pacman::Refresh(int action)
{
	switch (action)
	{
		case Reconstruction::NEW_PHASE:
		case Reconstruction::PACMAN_DIED:
			Initilize();
		break;
	}
}