#include "FixedDirection.h"

FixedDirection* FixedDirection::top = new FixedDirection(TOP, 0, -1, "top");
FixedDirection* FixedDirection::bottom = new FixedDirection(BOTTOM, 0, 1, "bottom");
FixedDirection* FixedDirection::left = new FixedDirection(LEFT, -1, 0, "left");
FixedDirection* FixedDirection::right = new FixedDirection(RIGHT, 1, 0, "right");

bool FixedDirection::opposits_settled = false;

FixedDirection* FixedDirection::GetByCode(int cod)
{
								switch (cod)
								{
								case TOP:
																return top;
																break;
								case BOTTOM:
																return bottom;
																break;
								case LEFT:
																return left;
																break;
								case RIGHT:
																return right;
																break;
								default:
																stringstream msg;
																msg << "Invalid code in FixedDirection::GetByCode(int cod), cod=" << cod;

																throw new Exception(msg.str());
								}
}

FixedDirection* FixedDirection::Opposite()
{
								if (!opposits_settled)
																SetOpposite();

#ifdef DEBUG
								if (opposit == 0)
																throw new NullReferenceException("opposite", "FixedDirection::Opposite()");
#endif

								return opposit;
}

void FixedDirection::SetOpposite()
{
								top->SetOpposite(bottom);
								bottom->SetOpposite(top);
								left->SetOpposite(right);
								right->SetOpposite(left);

								opposits_settled = true;
}
