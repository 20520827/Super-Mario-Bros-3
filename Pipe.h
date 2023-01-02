#pragma once
#include "GameObject.h"

#define PIPE_STATE_SOLID 1000
#define PIPE_STATE_TRANS 2000

class Pipe:public CGameObject
{
protected:
	float bbox_width, bbox_height;
	int spriteIdPipe;
	int isSolid;
public:
	Pipe(float x, float y, float bbox_width, float bbox_height, int spriteIdPipe) :CGameObject(x, y)
	{
		this->x = x;
		this->y = y;
		this->bbox_width = bbox_width;
		this->bbox_height = bbox_height;
		this->spriteIdPipe = spriteIdPipe;
		this->isSolid = 1;
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return this->isSolid; }
	int GetSpriteId() { return this->spriteIdPipe; }
	void SetState(int state);
};

