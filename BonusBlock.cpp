#include "BonusBlock.h"
void BonusBlock::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(this->aniIdBonusBlock)->Render(x, y);

	RenderBoundingBox();
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
		this->aniIdBonusBlock = ANI_ID_SPINNING;
		break;
	case BBLOCK_STATE_EMPTY:
		this->aniIdBonusBlock = ANI_ID_EMPTY;
		break;
	}
}