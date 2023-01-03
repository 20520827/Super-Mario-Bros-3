#pragma once

#include "GameObject.h"


class Bush:public CGameObject
{
protected:
	int spriteIdBush;
	float bbox_width, bbox_height;
public:
	Bush(float x, float y, int spriteIdBush) :CGameObject(x, y)
	{
		this->x = x;
		this->y = y;
		this->bbox_width = 0;
		this->bbox_height = 0;
		this->spriteIdBush = spriteIdBush;
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 0; }
	int IsCollidable() { return 0; };
};

