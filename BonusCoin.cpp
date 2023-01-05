#include "BonusCoin.h"

void BonusCoin::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - BCOIN_BBOX_WIDTH / 2;
	t = y - BCOIN_BBOX_HEIGHT / 2;
	r = l + BCOIN_BBOX_WIDTH;
	b = t + BCOIN_BBOX_HEIGHT;
}

void BonusCoin::Render()
{
	int aniId = ID_ANI_BCOIN;
	if (state == BCOIN_STATE_RENDER)
	{
		CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	}
	//RenderBoundingBox();
}

void BonusCoin::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	if ((state == BCOIN_STATE_ACTIVATE) && (GetTickCount64() - delay_start > BCOIN_DELAY))
	{
		SetState(BCOIN_STATE_RENDER);
		return;
	}

	if ((state == BCOIN_STATE_RENDER) && (GetTickCount64() - render_start > BCOIN_RENDER_TIMER))
	{
		SetState(BCOIN_STATE_UNRENDER);
		this->Delete();
		return;
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void BonusCoin::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case BCOIN_STATE_ACTIVATE:
		delay_start = GetTickCount64();
		break;
	case BCOIN_STATE_RENDER:
		render_start = GetTickCount64();
		vy = -0.5f;
		ay = 0.002f;
		break;
	case BCOIN_STATE_UNRENDER:
		break;
	}
}