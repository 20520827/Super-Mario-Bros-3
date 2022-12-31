#pragma once

#include "GameObject.h"

class InvisPlat:public CGameObject
{
protected:
	float bbox_width, bbox_height;
	float oy;
public:
	InvisPlat(float x, float y, float bbox_width, float bbox_height) :CGameObject(x, y)
	{
		this->x = x;
		this->y = y;
		this->oy = y;
		this->bbox_width = bbox_width;
		this->bbox_height = bbox_height;
	}
	void Render() { /*RenderBoundingBox();*/ }
	void Update(DWORD dt) { }
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 1; }
	int IsOneWayY() { return 1; }
};

