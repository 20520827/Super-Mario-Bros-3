#pragma once
#include"GameObject.h"

#define BGT_STATE_SOLID 100
#define BGT_STATE_TRANS	200

class BGTiles:public CGameObject
{
protected:
	int spriteIdTiles;
	float bbox_width, bbox_height;
	int blockable;
public:
	BGTiles(float x, float y, float bbox_width, float bbox_height, int spriteIdTiles) :CGameObject(x, y)
	{
		this->x = x;
		this->y = y;
		this->bbox_width = bbox_width;
		this->bbox_height = bbox_height;
		this->spriteIdTiles = spriteIdTiles;
		this->blockable = 0;
	}
	void Render();
	void Update(DWORD dt){};
	void OnNoCollision(DWORD dt);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void SetState(int state);
	int IsBlocking() { return blockable; }
	int IsCollidable() { return 1; };
};

