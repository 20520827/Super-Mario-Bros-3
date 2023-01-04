#include "BonusBlock.h"
void BonusBlock::Render()
{
	int aniId = ANI_ID_SPINNING;
	if (state == BBLOCK_STATE_EMPTY)
	{
		aniId = ANI_ID_EMPTY;
	}

	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	//RenderBoundingBox();
}

void BonusBlock::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - BBLOCK_BBOX_WIDTH / 2;
	t = y - BBLOCK_BBOX_HEIGHT / 2;
	r = l + BBLOCK_BBOX_WIDTH;
	b = t + BBLOCK_BBOX_HEIGHT;
}

void BonusBlock::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case BBLOCK_STATE_SPINNING:
		break;
	case BBLOCK_STATE_EMPTY:
		ay = 0;
		vy = 0;
		break;
	case BBLOCK_STATE_JUMP:
		jump_start = GetTickCount64();
		vy = -0.25f;
		ay = 0.002f;
		break;
	}
}

void BonusBlock::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;

	if (abs(y) > oy)
	{
		y = oy;
	}

	if ((state == BBLOCK_STATE_JUMP) && (GetTickCount64() - jump_start > 220))
	{
		SetState(BBLOCK_STATE_EMPTY);
		if (y != oy)
		{
			y = oy;
		}
		return;
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
