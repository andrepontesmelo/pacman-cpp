#include "CollisionDetection.h"

CollisionDetection* CollisionDetection::instance = 0;

CollisionDetection* CollisionDetection::Instance()
{
								if (instance == 0)
																instance = new CollisionDetection();

								return instance;
}

void CollisionDetection::Add(ICollidable* d)
{
#ifdef DEBUG
								if (d == 0) throw new NullReferenceException("ICollidable d", "CollisionDetection::Add()");
#endif
								collidables.push_back(d);
}

void CollisionDetection::Detect()
{
								if (last_pacman_position == 0)
																last_pacman_position = new Position(pacman->GetPosition()->X(), pacman->GetPosition()->Y());

								if ((last_pacman_position->HorizontalDistance(pacman->GetPosition()) != 0)
												&&  (last_pacman_position->VerticalDistance(pacman->GetPosition()) != 0))
								{
																Position * pacman_pos = pacman->GetPosition();

																last_pacman_position->SetX(pacman_pos->X());
																last_pacman_position->SetY(pacman_pos->Y());
								}

								std::vector<ICollidable*>::iterator iterador = collidables.begin();

								largest_width = abs(pacman->GetPosition()->X() - last_pacman_position->X()) + pacman->Width();
								largest_height = abs(pacman->GetPosition()->Y() - last_pacman_position->Y()) + pacman->Height();

								largest_position->SetX((pacman->GetPosition()->X() + last_pacman_position->X()) / 2);
								largest_position->SetY((pacman->GetPosition()->Y() + last_pacman_position->Y()) / 2);

								for (; iterador < collidables.end(); iterador++)
								{
																ICollidable *obj = *iterador;
																if (obj->Visible() && DetectCollision(obj))
																{
																								if (obj->PacmanCanEat())
																																obj->WasEaten();
																								else
																																obj->AtePacman();
																}
								}

								Position * pacman_pos = pacman->GetPosition();

								last_pacman_position->SetX(pacman_pos->X());
								last_pacman_position->SetY(pacman_pos->Y());
}

bool CollisionDetection::DetectCollision(ICollidable* obj)
{
#ifdef DEBUG
								if (pacman == 0)
																throw new NullReferenceException("pacman", "CollisionDetection::DetectCollision");

								if (obj->GetPosition() == 0)
																throw new NullReferenceException("obj->GetPosition()", "CollisionDetection::DetectCollision");
#endif

								bool hit_horizontally =
																obj->GetPosition()->HorizontalDistance(largest_position) < (obj->Width() + largest_width) / 2;

								bool hit_vertically =
																obj->GetPosition()->VerticalDistance(largest_position) < (obj->Height() + largest_height) / 2;

								return (hit_horizontally && hit_vertically);
}

void CollisionDetection::Reset()
{
								delete(last_pacman_position);
								last_pacman_position = new Position(pacman->GetPosition()->X(), pacman->GetPosition()->Y());
}
