#pragma once
#include "GameObject.h"

#define BCOIN_BBOX_WIDTH 15
#define BCOIN_BBOX_HEIGHT 15

#define BCOIN_STATE_UNRENDER 0
#define BCOIN_STATE_RENDER 100
#define BCOIN_STATE_ACTIVATE 200

#define BCOIN_DELAY 250
#define BCOIN_RENDER_TIMER 425

#define ID_ANI_BCOIN 130001

class BonusCoin:public CGameObject
{
protected:
	float ay;
	ULONGLONG delay_start;
	ULONGLONG render_start;
public:
	BonusCoin(float x, float y) : CGameObject(x, y)
	{
		this->ay = 0;
		delay_start = -1;
		render_start = -1;
		this->state = BCOIN_STATE_UNRENDER;
	}
	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();

	int IsCollidable() { return 1; };
	int IsBlocking() { return 0; }
	void OnNoCollision(DWORD dt) { y += vy * dt; }

	void OnCollisionWith(LPCOLLISIONEVENT e) {}
	void SetState(int state);
};

