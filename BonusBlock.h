#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ANI_ID_SPINNING 100
#define ANI_ID_EMPTY 200

#define BBLOCK_STATE_SPINNING 80001
#define BBLOCK_STATE_JUMP	80002
#define BBLOCK_STATE_EMPTY	85001

#define BBLOCK_BBOX_WIDTH 15
#define	BBLOCK_BBOX_HEIGHT 15


class BonusBlock:public CGameObject
{
protected:
	float oy, ay;
	ULONGLONG jump_start;
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 0; };
	virtual int IsBlocking() { return 1; }
	virtual void OnNoCollision(DWORD dt){ y += vy * dt; };

	void OnCollisionWith(LPCOLLISIONEVENT e) {};
public:
	BonusBlock(float x, float y) : CGameObject(x, y)
	{
		this->oy = y;
		this->ay = 0;
		jump_start = -1;
	}
	virtual void SetState(int state);
};

