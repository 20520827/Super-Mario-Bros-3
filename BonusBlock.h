#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ANI_ID_SPINNING 100
#define ANI_ID_EMPTY 200

#define BBLOCK_STATE_SPINNING 80001
#define BBLOCK_STATE_EMPTY	85001

#define BBLOCK_BBOX_WIDTH 15
#define	BBLOCK_BBOX_HEIGHT 15

class BonusBlock:public CGameObject
{
protected:
	int aniIdBonusBlock;
public:
	BonusBlock(float x, float y) : CGameObject(x, y) { this->aniIdBonusBlock = ANI_ID_SPINNING; }
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 1; }
	void SetState(int state);
};

