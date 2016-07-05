#include "Pill.h"

Pill::Pill(int x, int y) : Bonus()
{
	drawing = Construir_animation(x, y);
	drawing->SetCentered(true);

	// Inscreve-se na reconstrução
	Reconstruction::Instance()->AddObserver(this);
}

void Pill::WasEaten()
{
	if (!visible) return;

#ifdef DEBUG
	if (ghosts == 0)
		throw new NullReferenceException("ghosts", "Pill::WasEaten()");
#endif

	ghosts->PillEaten();
	DrawingElement::WasEaten();
}

Animation* Pill::Construir_animation(int x, int y)
{
	Animation * ani = new Animation(PILL_ANIMATION_INTERVAL);

	Color * color = new Color(PILL_COLOR_R, PILL_COLOR_G, PILL_COLOR_B);

	// Cria um bitmap at branco
	for (int radius = PILL_RADIUS; radius < PILL_RADIUS_MAX; radius++)
	{
		Bitmap * bmp = new Bitmap(2 * PILL_RADIUS_MAX + 1, 2 * PILL_RADIUS_MAX + 1, x, y);

		bmp->DrawFilledCircle(PILL_RADIUS_MAX, PILL_RADIUS_MAX, radius, color);

		ani->Add_bitmap(bmp);
	}

	// Cria um bitmap at branco
	for (int radius = PILL_RADIUS_MAX; radius > PILL_RADIUS; radius--)
	{
		Bitmap * bmp = new Bitmap(2 * PILL_RADIUS_MAX + 1, 2 * PILL_RADIUS_MAX + 1, x, y);

		bmp->DrawFilledCircle(PILL_RADIUS_MAX, PILL_RADIUS_MAX, radius, color);

		ani->Add_bitmap(bmp);
	}

	return ani;
}

void Pill::Refresh(int action)
{
	switch (action)
	{
		case Reconstruction::NEW_PHASE:
			visible = true;
		break;
	}
}

