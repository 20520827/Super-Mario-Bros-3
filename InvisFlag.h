#pragma once
#include "GameObject.h"

class InvisFlag:public CGameObject
{
protected:
	float bbox_width, bbox_height;
public:
	InvisFlag(float x, float y) :CGameObject(x, y)
	{
		this->x = x;
		this->y = y;
		this->bbox_width = 1;
		this->bbox_height = 8;
	}
	void Render() { RenderBoundingBox(); }
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 0; }
	int IsCollidable() { return 1; };
};

