#include "BGTiles.h"

#include "Sprite.h"
#include "Sprites.h"

#include "Textures.h"

void BGTiles::Render()
{
	CSprites* s = CSprites::GetInstance();

	s->Get(this->spriteIdTiles)->Draw(x, y);

	RenderBoundingBox();
}

void BGTiles::OnNoCollision(DWORD dt)
{
	if (this->blockable != 0)
	{
		this->blockable = 0;
	}
}

void BGTiles::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - bbox_width / 2;
	t = y - bbox_height / 2;
	r = l + bbox_width;
	b = t + bbox_height;
}

void BGTiles::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case BGT_STATE_SOLID:
		this->blockable = 1;
		break;
	case BGT_STATE_TRANS:
		this->blockable = 0;
		break;
	}
}