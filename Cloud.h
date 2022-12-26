#pragma once

#include "GameObject.h"
class Cloud:public CGameObject
{
protected:
	int spriteIdCloud;
	float bbox_width, bbox_height;
public:
	Cloud(float x, float y, float bbox_width, float bbox_height, int spriteIdCloud) :CGameObject(x, y)
	{
		this->x = x;
		this->y = y;
		this->bbox_width = bbox_width;
		this->bbox_height = bbox_height;
		this->spriteIdCloud = spriteIdCloud;
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 0; }
	int IsCollidable() { return 0; };
};

