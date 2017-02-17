#include "WalkingElement.h"

void WalkingElement::Initilize()
{
								acc_time = 0;
}

WalkingElement::WalkingElement()
{
								direction = FixedDirection::Left();
								Initilize();
}

WalkingElement::WalkingElement(FixedDirection * straight_initial_direction)
{
								direction = straight_initial_direction;
								Initilize();
}

void WalkingElement::UpdatePosition(int elapsed_ms)
{
								FixedDirection * next_direction = NextDirection();

								elapsed_ms += acc_time;
								int walking_pixels = elapsed_ms / Interval();
								acc_time = elapsed_ms % Interval();

#ifdef DEBUG
								if (next_corner == 0)
																throw new NullReferenceException("next_corner", "WalkingElement::UpdatePosition()");
#endif

								bool exceeded = drawing->GetPosition()->GreaterThan(next_corner->GetPosition(), direction);
								bool not_exceeded = !exceeded;
								bool almost_exceeded = drawing->GetPosition()->Distance(next_corner->GetPosition()) < walking_pixels;

								if (exceeded || (not_exceeded && almost_exceeded))
								{
																if (next_corner->GetCorner(next_direction->GetCode()) != 0)
																{
																								drawing->SetPosition(next_corner->GetPosition()->X(), next_corner->GetPosition()->Y());

																								next_corner = next_corner->GetCorner(next_direction->GetCode());
																								direction = next_direction;
																								stopped = false;
																								Flip();
																}
																else if (next_corner->GetCorner(direction->GetCode()) != 0)
																{
																								next_corner = next_corner->GetCorner(direction->GetCode());
																								stopped = false;
																}
																else
																{
																								drawing->SetPosition(next_corner->GetPosition()->X(), next_corner->GetPosition()->Y());
																								stopped = true;
																}
								}

								if (!stopped)
								{
																drawing->IncrementPosition((int) (direction->X() * walking_pixels), (int) (direction->Y() * walking_pixels));
								}
}

void WalkingElement::Draw()
{
								DrawingElement::Draw();
}

void WalkingElement::FindNextCorner()
{
								Corner * next = next_corner->GetCorner(direction->GetCode());

								if (next != 0)
																next_corner = next;
								else
																exit(58);
}
